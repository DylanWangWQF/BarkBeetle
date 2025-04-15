import argparse

def generate_decision_tree(depth, nr_features, plain_tree=False):
    """
    Generate a C function (as a string) that implements a full binary decision tree.
    
    The generated function is named "tree_<depth>_<nr_features>".
    If plain_tree is True, the function signature and tree structure omit
    the helper code for the Fia attack.
    
    Arguments:
      depth: int, depth of the decision tree (number of decisions along a path)
      nr_features: int, number of features used for splitting
      plain_tree: bool, if True, generate plain tree code without FIA helper.
      
    Returns:
      A string containing the C code of the decision tree function.
    """
    # Allowed threshold range for each feature.
    initial_ranges = {i: (0.0, 2.0**depth) for i in range(nr_features)}
    leaf_counter = [0]  # mutable counter for leaf values

    def recurse(level, indent, feature_ranges, plain_tree):
        # Base case: leaf node.
        if level == depth:
            code = indent + f"return {leaf_counter[0]};\n"
            leaf_counter[0] += 1
            return code
        
        # Select feature index (cycling through available features).
        feat = level % nr_features
        low, high = feature_ranges.get(feat, (0.0, 10.0))
        threshold = (low + high) / 2.0
        threshold_str = f"{threshold:.2f}f"
        
        # Generate the if condition.
        if plain_tree:
            code = indent + f"if (features[{feat}] < {threshold_str}) {{\n"
        else:
            code = indent + f"if (features[{feat}] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < {threshold_str}) {{\n"
        
        # Update allowed threshold range for left branch.
        left_ranges = feature_ranges.copy()
        left_ranges[feat] = (low, threshold)
        if plain_tree:
            left_code = recurse(level + 1, indent + "    ", left_ranges, plain_tree)
        else:
            left_code = indent + "    " + "(*cnt)++;\n" + recurse(level + 1, indent + "    ", left_ranges, plain_tree)
        
        # Update allowed threshold range for right branch.
        right_ranges = feature_ranges.copy()
        right_ranges[feat] = (threshold, high)
        if plain_tree:
            right_code = recurse(level + 1, indent + "    ", right_ranges, plain_tree)
        else:
            right_code = indent + "    " + "(*cnt)++;\n" + recurse(level + 1, indent + "    ", right_ranges, plain_tree)
        
        code += left_code
        code += indent + "} else {\n"
        code += right_code
        code += indent + "}\n"
        return code

    # Generate the function header.
    if plain_tree:
        function_code = f"int tree_{depth}_{nr_features}(float features[]) {{\n"
    else:
        function_code = f"int tree_{depth}_{nr_features}(float features[], int *cnt, int node_loc, int flag, int ifFIA) {{\n"
        function_code += "    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;\n"
    
    function_code += recurse(0, "    ", initial_ranges, plain_tree)
    function_code += "}\n"
    return function_code

def export_tree_to_file(depth, nr_features, plain_tree=False, filename="tree.c"):
    """
    Export the generated decision tree function(s) to a C file.
    
    The file will start with the following header lines:
      #include "tree.h"
      #include <float.h>
      #include <stdio.h>
    
    Arguments:
      depth: int, depth of the decision tree.
      nr_features: int, number of features used for splitting.
      plain_tree: bool, if True, generate plain tree code without FIA helper.
      filename: str, the name of the file to write to (default "tree.c").
    """
    header_lines = (
        '#include "tree.h"\n'
        "#include <float.h>\n"
        "#include <stdio.h>\n\n"
    )
    tree_function_code = generate_decision_tree(depth, nr_features, plain_tree)
    full_code = header_lines + tree_function_code
    
    with open(filename, "w") as f:
        f.write(full_code)
    print(f"Tree function exported to {filename}")

def main():
    parser = argparse.ArgumentParser(
        description="Generate C decision tree(s) and export them to tree.c. " +
                    "Either generate a range of trees with variable depth (fixed nr_features) " +
                    "or a range of trees with variable number of features (fixed depth)."
    )
    # Mode 1: Variable depth, fixed number of features.
    parser.add_argument("--min_depth", type=int, default=None,
                        help="Minimum depth for variable depth mode")
    parser.add_argument("--max_depth", type=int, default=None,
                        help="Maximum depth for variable depth mode")
    parser.add_argument("--nr_features", type=int, default=None,
                        help="Fixed number of features for variable depth mode")
    
    # Mode 2: Variable number of features, fixed depth.
    parser.add_argument("--min_nr_features", type=int, default=None,
                        help="Minimum number of features for variable features mode")
    parser.add_argument("--max_nr_features", type=int, default=None,
                        help="Maximum number of features for variable features mode")
    parser.add_argument("--depth", type=int, default=None,
                        help="Fixed depth for variable features mode")
    
    # Boolean flag for plain tree generation.
    parser.add_argument("--plain_tree", action="store_true", default=False,
                        help="If set, generate plain tree without FIA helper code")
    
    args = parser.parse_args()
    
    code_segments = []
    
    # Determine mode based on provided arguments.
    if args.min_depth is not None and args.max_depth is not None and args.nr_features is not None:
        # Variable depth mode (fixed nr_features).
        for d in range(args.min_depth, args.max_depth + 1):
            code_segments.append(generate_decision_tree(d, args.nr_features, plain_tree=args.plain_tree))
    elif args.min_nr_features is not None and args.max_nr_features is not None and args.depth is not None:
        # Variable features mode (fixed depth).
        for nf in range(args.min_nr_features, args.max_nr_features + 1):
            code_segments.append(generate_decision_tree(args.depth, nf, plain_tree=args.plain_tree))
    else:
        parser.error("Must provide either (min_depth, max_depth, nr_features) "
                     "or (min_nr_features, max_nr_features, depth).")
    
    header_lines = (
        '#include "tree.h"\n'
        "#include <float.h>\n"
        "#include <stdio.h>\n\n"
    )
    full_code = header_lines + "\n".join(code_segments)
    
    filename = "tree.c"
    with open(filename, "w") as f:
        f.write(full_code)
    print(f"Tree functions exported to {filename}")

if __name__ == "__main__":
    main()
