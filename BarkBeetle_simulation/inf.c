#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include "tree.h"
// #include "pico/stdlib.h"


// Medical Provider Charge
// #define MAX_NODES 10 // Maximum number of conditions in a path/depth
// #define MAX_PATHS 64 // Maximum number of paths
// #define NUM_FEA_LABEL 12 // include label
// #define NUM_FEA 11 // only fea

//iris
// #define MAX_NODES 5 // Maximum number of conditions in a path/depth
// #define MAX_PATHS 10 // Maximum number of paths
// #define NUM_FEA_LABEL 4 // include label
// #define NUM_FEA 3 // only fea

// Diabetes Diagnosis
// #define MAX_NODES 5 // Maximum number of conditions in a path/depth
// #define MAX_PATHS 11 // Maximum number of paths
// #define NUM_FEA_LABEL 6 // include label
// #define NUM_FEA 5 // only fea

// bitcoin
// #define MAX_NODES 11 // Maximum number of conditions in a path/depth
// #define MAX_PATHS 147 // Maximum number of paths
// #define NUM_FEA_LABEL 7 // include label
// #define NUM_FEA 6 // only fea

// energy
#define MAX_NODES 18 // Maximum number of conditions in a path/depth
#define MAX_PATHS 158 // Maximum number of paths
#define NUM_FEA_LABEL 26 // include label
#define NUM_FEA 25 // only fea


typedef struct {
    int feature_index;
    int comparison_type; // 0 for <, 1 for >
    float threshold;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int num_nodes;
    int label;
} Path;


// Function to initialize a node to (-1, 0, -1)
void initialize_node(Node *node) {
    node->feature_index = -1;
    node->comparison_type = 0;
    node->threshold = -2.0f;
}

// Function to initialize all nodes in a path
void initialize_path(Path *path, int label) {
    path->num_nodes = 0;
    path->label = label;
    for (int i = 0; i < MAX_NODES; i++) {
        initialize_node(&path->nodes[i]);
    }
}

void load_feature_range(const char *filename, float fea_range[][2], int NUM_FEAtures) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open feature range file");
        exit(1);
    }

    for (int i = 0; i < NUM_FEAtures; i++) {
        if (fscanf(file, "%f,%f", &fea_range[i][0], &fea_range[i][1]) != 2) {
            fprintf(stderr, "Failed to read feature range data for feature %d\n", i);
            exit(1);
        }
    }

    fclose(file);
}

int tree_pred(Path paths[], float features[], int node_loc, int LoRflag, int ifFIA, uint64_t *num_queries, uint64_t *num_fia) {
    int cnt = 0;
    int r = tree(features, &cnt, node_loc, LoRflag, ifFIA);

    (*num_queries)++;
    paths[r].num_nodes = cnt;
    paths[r].label = r;

    for (int i = 0; i < cnt; i++) {
        paths[r].nodes[i].comparison_type = LoRflag;
    }

    return r;
}

/*TBD: can be optimized in a more flexible way*/
float flexible_stride(float val, float epi, int scale) {
    if (val > 1000) {
        return 1.0f;  // Add only a small value for large integers
    } else {
        return epi * scale;  // Use the normal adjustment for decimals
    }
}


float mBinarySearch(float input[], float fea_range[][2], int baselabel, int fidx, int nidx,
                     float low_bnd, float high_bnd, int ifFIA, int flag, float epi,
                     uint64_t *num_queries, uint64_t *num_fia) {

    int c_bs = baselabel;
    int cnt = 0;

    // Convert bounds to integer multipliers
    int64_t low_mult = (int64_t)roundf(low_bnd / epi);
    int64_t high_mult = (int64_t)roundf(high_bnd / epi);
    int64_t mid_mult;

    float ori_fea_val = input[fidx];

    while (high_mult - low_mult > 1)  // Stop when difference is <= 1
    {
        mid_mult = (low_mult + high_mult) / 2;
        float mid = (float) mid_mult * epi;  // Convert back to float
        input[fidx] = mid;

        cnt = 0;
        c_bs = tree(input, &cnt, nidx, flag, ifFIA);
        (*num_queries)++;
        if (ifFIA == 1) {
            (*num_fia)++;
        }

        if ((flag == 0 && (c_bs == baselabel)) || (flag != 0 && !(c_bs == baselabel))) {
            low_mult = mid_mult;
        } else {
            high_mult = mid_mult;
        }

    }

    input[fidx] = ori_fea_val;
    return (float) low_mult * epi;  // Return final computed boundary
}


// uniq_dup_fea_path: -1 default, 0 uniq feas, 1 dup feas
void confirm_uniq_feas(Path paths[], float input[], float fea_range[][2], int uniq_dup_fea_path[], int baselabel, int flag, float epi, uint64_t *num_queries, uint64_t *num_fia)
{
    int fea_in_path[NUM_FEA];
    for (int i = 0; i < NUM_FEA; i++) {
        fea_in_path[i] = 1;
    }

    for (int i = 0; i < paths[baselabel].num_nodes; i++)
    {
        if (paths[baselabel].nodes[i].feature_index != -1)
        {
            fea_in_path[paths[baselabel].nodes[i].feature_index] = 0;
        }
    }

    for (int i = 0; i < NUM_FEA; i++)
    {
        if (fea_in_path[i] == 0) continue; // in extended path, some feas should already defined, skip

        float m_input[NUM_FEA];
        memcpy(m_input, input, NUM_FEA * sizeof(float));
        m_input[i] = (flag == 0) ? fea_range[i][1] + 1.0 : fea_range[i][0] - 1.0;

        int cnt = 0;
        int r = tree(m_input, &cnt, -1, flag, 0);
        (*num_queries)++;

        if (r != baselabel)
        {
            paths[r].num_nodes = cnt;
            paths[r].label = r;

            int min_nodes = (cnt > paths[baselabel].num_nodes) ? paths[baselabel].num_nodes : cnt;
            
            for (int j = 0; j < min_nodes; j++)
            {
                if (paths[baselabel].nodes[j].feature_index == -1)
                {
                    cnt = 0;
                    // FIA(), making go left on j-th node
                    int r_0 = tree(m_input, &cnt, j, flag, 1);
                    (*num_queries)++;
                    (*num_fia)++;

                    if (r_0 != r)
                    {
                        paths[baselabel].nodes[j].feature_index = i;
                        if (r_0 == baselabel)
                        {
                            // case of unique features, confirm the threshold
                            uniq_dup_fea_path[i] = 0;
                            paths[baselabel].nodes[j].threshold = mBinarySearch(input, fea_range, baselabel, i, -1, fea_range[i][0], fea_range[i][1], 0, flag, epi, num_queries, num_fia);
                        }
                        else
                        {
                            // case of the duplicate features, confirm the treshold in the next step
                            uniq_dup_fea_path[i] = 1;
                        }

                        break;
                    }
                }
            }
        }
    }

}

int check_path_status(Path *path)
{
    int cnt = 0;
    for (int i = 0; i < path->num_nodes; i++)
    {
        if (path->nodes[i].threshold == -2.0f)
        {
            cnt++;
        }
    }
    return cnt;
}

int check_feature_status(int uniq_dup_fea_path[])
{
    int cnt = 0;
    for (int i = 0; i < NUM_FEA; i++)
    {
        if (uniq_dup_fea_path[i] == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

void confirm_dup_feas(Path paths[], float input[], int uniq_dup_fea_path[], float fea_range[][2], float fea_range_on_path[][2], int baselabel, int flag, float epi, uint64_t *num_queries, uint64_t *num_fia)
{
    int c_b[NUM_FEA]; // record the previous label for this fea
    int loc[NUM_FEA]; // record the previous node index for this fea
    for (int i = 0; i < NUM_FEA; i++) {
        c_b[i] = -1;
        loc[i] = -1;
    }
    int cnt = 0;
    int num_nodes = paths[baselabel].num_nodes;
    float tres[NUM_FEA][MAX_NODES] = {0.0f};
    for (int i = 0; i < NUM_FEA; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            tres[i][j] = 0.0f;
        }
    }
    int tidx = 0; // indicate the index for current threshold

    // search the first thres for each dup feas (dont need FIA, so dont need nidx)
    for (int i = 0; i < NUM_FEA; i++) {
        if (uniq_dup_fea_path[i] != 1) continue;
        c_b[i] = baselabel;
        tres[i][tidx] = mBinarySearch(input, fea_range, c_b[i], i, -1, fea_range_on_path[i][0], fea_range_on_path[i][1], 0, flag, epi, num_queries, num_fia);
    }

    while (check_path_status(&paths[baselabel]) != 0)  // && tidx < 10
    {
        for (int i = 0; i < NUM_FEA; i++) 
        {
            if (uniq_dup_fea_path[i] != 1) continue;

            float m_input[NUM_FEA];
            memcpy(m_input, input, NUM_FEA * sizeof(float));

            float stride = flexible_stride(tres[i][tidx], epi, 10);
            m_input[i] = (flag == 0) ? (tres[i][tidx] + stride) : (tres[i][tidx] - stride);

            for (int j = num_nodes - 1; j >= 0; j--)
            {
                if (paths[baselabel].nodes[j].threshold != -2.0f) continue;

                if (paths[baselabel].nodes[j].feature_index == i)
                {
                    // case that find the last node contains i-th dup fea
                    paths[baselabel].nodes[j].threshold = tres[i][tidx];
                    uniq_dup_fea_path[i] = 0; // remove this fea from dup feas
                    break; // jump out of loop-nodes, still in loop-fea
                }

                if (check_feature_status(uniq_dup_fea_path) == 1)
                {
                    paths[baselabel].nodes[j].feature_index = i;
                    paths[baselabel].nodes[j].threshold = tres[i][tidx];
                    loc[i] = j;
                    break;
                } else {
                    cnt = 0;
                    int c_f = tree(m_input, &cnt, j, flag, 1);
                    (*num_queries)++;
                    (*num_fia)++;

                    if (c_f == c_b[i])
                    {
                        paths[baselabel].nodes[j].feature_index = i;
                        paths[baselabel].nodes[j].threshold = tres[i][tidx];
                        loc[i] = j;
                        break;
                    }
                }
            }
        }


        for (int i = 0; i < NUM_FEA; i++) 
        {
            if (uniq_dup_fea_path[i] != 1) continue;

            float m_input[NUM_FEA];
            memcpy(m_input, input, NUM_FEA * sizeof(float));
            if (tidx == 0)
            {
                c_b[i] = baselabel;
            }
            else
            {
                float stride = flexible_stride(tres[i][tidx], epi, 10);
                m_input[i] = (flag == 0) ? (tres[i][tidx] - stride) : (tres[i][tidx] + stride);
                cnt = 0;
                c_b[i] = tree(m_input, &cnt, -1, flag, 0);  // record the right-most label for this fea
                (*num_queries)++;
            }

            fea_range_on_path[i][flag] = tres[i][tidx];
            
            // check if i-th feature will not appear in the following
            m_input[i] = (flag == 0) ? fea_range_on_path[i][1] : fea_range_on_path[i][0];
            cnt = 0;
            int r_ifdup = tree(m_input, &cnt, loc[i], flag, 1);
            (*num_queries)++;
            (*num_fia)++;
            if (r_ifdup == c_b[i])
            {
                uniq_dup_fea_path[i] = 0; // i-th feature will not appear in the following nodes of this path
            }
        }

        for (int i = 0; i < NUM_FEA; i++) 
        {
            if (uniq_dup_fea_path[i] != 1) continue;

            float m_input[NUM_FEA];
            memcpy(m_input, input, NUM_FEA * sizeof(float));

            tres[i][tidx + 1] = mBinarySearch(input, fea_range, c_b[i], i, loc[i], fea_range_on_path[i][0], fea_range_on_path[i][1], 1, flag, epi, num_queries, num_fia);
            float stride = flexible_stride(tres[i][tidx], epi, 10);
            m_input[i] = (flag == 0) ? (tres[i][tidx + 1] - stride) : (tres[i][tidx + 1] + stride);
            cnt = 0;
            c_b[i] = tree(m_input, &cnt, -1, flag, 0);
            (*num_queries)++;
        }

        tidx++;
    }
}


void single_attack_epoch(Path paths[], float input[], float fea_range[][2], float fea_range_on_path[][2], int uniq_dup_fea_path[], int base_label, int flag, float epi, uint64_t *num_queries, uint64_t *num_fia)
{
    confirm_uniq_feas(paths, input, fea_range, uniq_dup_fea_path, base_label, flag, epi, num_queries, num_fia);
    confirm_dup_feas(paths, input, uniq_dup_fea_path, fea_range, fea_range_on_path, base_label, flag, epi, num_queries, num_fia);
}

void recur_attack(Path paths[], int num_paths, float fea_range[][2], int path_recvoer_status[], int path_node_start_idx[], float input_inherent[][NUM_FEA], int new_base_path[], int LR_path_indictor[], float epi, uint64_t *num_queries, uint64_t *num_fia)
{
    int tmp_new_base_path[num_paths];
    memcpy(tmp_new_base_path, new_base_path, num_paths * sizeof(int));

    for (int k = 0; k < num_paths; k++)
    {
        
        if (new_base_path[k] != 1) continue;
        
        float confirmed_thres[NUM_FEA];
        int confirmed_br[NUM_FEA];
        
        for (int i = path_node_start_idx[k]; i < paths[k].num_nodes; i++) {
            // Initialize auxiliary threshold and comparison type arrays
            for (int j = 0; j < NUM_FEA; j++) {
                confirmed_thres[j] = -2.0f;
                confirmed_br[j] = -1;
            }
            // Record current i-th node info
            int cur_fea_idx = paths[k].nodes[i].feature_index;
            int cur_br = paths[k].nodes[i].comparison_type;
            float cur_thres = paths[k].nodes[i].threshold;
            
            // craft input based on the base path (branch from one of the nodes)
            for (int j = 0; j < i; j++)
            {
                if (paths[k].nodes[j].feature_index == cur_fea_idx) {
                    confirmed_thres[cur_fea_idx] = paths[k].nodes[j].threshold;
                    confirmed_br[cur_fea_idx] = paths[k].nodes[j].comparison_type;
                }
            }

            float ori_fea_val = input_inherent[k][cur_fea_idx];
            float stride = flexible_stride(cur_thres, epi, 10);
            if (confirmed_br[cur_fea_idx] == -1)
            {
                input_inherent[k][cur_fea_idx] = (cur_br == 0) ? (cur_thres + stride) : (cur_thres - stride);
            }
            // (0, 0) only in left sub-tree
            else if ((confirmed_br[cur_fea_idx] == 0) && (cur_br == 0))
            {
                input_inherent[k][cur_fea_idx] = cur_thres + stride;
            }
            // (1, 0) only in left sub-tree
            else if ((confirmed_br[cur_fea_idx] == 1) && (cur_br == 0))
            {
                input_inherent[k][cur_fea_idx] = cur_thres + stride;
            }
            // (0, 1) only in right sub-tree
            else if ((confirmed_br[cur_fea_idx] == 0) && (cur_br == 1))
            {
                input_inherent[k][cur_fea_idx] = cur_thres - stride;
            }
            // (0, 1) only in right sub-tree
            else if ((confirmed_br[cur_fea_idx] == 1) && (cur_br == 1))
            {
                input_inherent[k][cur_fea_idx] = cur_thres - stride;
            }
            else
            {
                printf("Failed to select the %d-th feature value, for %d-th node in %d-th label (br=%d, thres=%.6f)\n", cur_fea_idx, i, k, cur_br, cur_thres);
            }

            int uniq_dup_fea_path[NUM_FEA]; // uniq_dup_fea_path: -1 default, 0 uniq feas, 1 dup feas
            for (int j = 0; j < NUM_FEA; j++) {
                uniq_dup_fea_path[j] = -1;
            }
            // fea_range_on_path[][] is used to record the range for each feature that is already confirmed in the parent path
            // [][0] is left bound, [][1] is the right bound
            float fea_range_on_path[NUM_FEA_LABEL][2];
            memcpy(fea_range_on_path, fea_range, NUM_FEA_LABEL * 2 * sizeof(float));

            int cnt = 0;
            int r = tree(input_inherent[k], &cnt, -1, LR_path_indictor[k], 0); // flag =0/1 doesnt matter
            (*num_queries)++;
            paths[r].num_nodes = cnt;

            for (int j = 0; j < cnt; j++)
            {
                if (j < i + 1) // copy the confirmed info in the parent path into the new path
                {
                    paths[r].nodes[j].feature_index = paths[k].nodes[j].feature_index;
                    paths[r].nodes[j].threshold = paths[k].nodes[j].threshold;
                    paths[r].nodes[j].comparison_type = (j != i) ? paths[k].nodes[j].comparison_type : 1 - paths[k].nodes[j].comparison_type;

                    // confirm the feature value range for each appeared feature
                    fea_range_on_path[paths[r].nodes[j].feature_index][1 - paths[r].nodes[j].comparison_type] = paths[r].nodes[j].threshold;
                    uniq_dup_fea_path[paths[r].nodes[j].feature_index] = 1; // temporaily record as dup feas, will be checked below
                }
                else // new path with the node where branch happens
                {
                    paths[r].nodes[j].comparison_type = LR_path_indictor[k]; // extended path's default branch is 0/1
                }
            }


            for (int j = 0; j < NUM_FEA; j++) {
                if (uniq_dup_fea_path[j] != 1) continue;

                float ori = input_inherent[k][j];
                float stride1 = flexible_stride(fea_range_on_path[j][1], epi, 10);
                float stride2 = flexible_stride(fea_range_on_path[j][0], epi, 10);
                input_inherent[k][j] = (LR_path_indictor[k] == 0) ? (fea_range_on_path[j][1] - stride1) : (fea_range_on_path[j][0] + stride2);
                cnt = 0;
                int r_ifdup = tree(input_inherent[k], &cnt, -1, LR_path_indictor[k], 0);
                (*num_queries)++;
                if (r_ifdup == r)
                {
                    uniq_dup_fea_path[j] = 0; // j-th feature will not appear in the following nodes of this path
                }
                input_inherent[k][j] = ori;
            }

            path_recvoer_status[r] = 0;
            LR_path_indictor[r] = LR_path_indictor[k];

            if (paths[r].num_nodes == i + 1)
            {
                input_inherent[k][cur_fea_idx] = ori_fea_val;
                tmp_new_base_path[k] = 0;
                continue;
            }
            
            single_attack_epoch(paths, input_inherent[k], fea_range, fea_range_on_path, uniq_dup_fea_path, r, LR_path_indictor[k], epi, num_queries, num_fia);
            
            // update auxiliary info
            tmp_new_base_path[r] = 1;
            tmp_new_base_path[k] = 0;
            memcpy(input_inherent[r], input_inherent[k], NUM_FEA * sizeof(float));
            path_node_start_idx[r] = i + 1;
            input_inherent[k][cur_fea_idx] = ori_fea_val;
        }
    }
    memcpy(new_base_path, tmp_new_base_path, num_paths * sizeof(int));
}

int sum(int path_recvoer_status[], int len)
{
    int counter = 0;
    for (int i = 0; i < len; i++) {
        counter += path_recvoer_status[i];
    }
    return counter;
}

int main()
{
    // TBD: optimized with smart inputs
    set_tree_function(TREE_TYPE_5); 

    if (tree == NULL) {
        printf("Error: No tree function selected!\n");
        return -1;
    }

    float fea_range[NUM_FEA_LABEL][2];
    load_feature_range("./attr_info/fea_range5.txt", fea_range, NUM_FEA_LABEL);

    uint64_t num_queries = 0; // number of queries
    uint64_t num_fia = 0; // number of fault run

    float epi = 0.001;

    float features_min[NUM_FEA];
    float features_max[NUM_FEA];
    int uniq_dup_fea_path[NUM_FEA]; // uniq_dup_fea_path: -1 default, 0 uniq feas, 1 dup feas
    for (int i = 0; i < NUM_FEA; i++) {
        features_min[i] = fea_range[i][0] - 1.0;
        features_max[i] = fea_range[i][1] + 1.0;

        uniq_dup_fea_path[i] = -1;
    }

    Path paths[MAX_PATHS];
    for (int i = 0; i < MAX_PATHS; i++) {
        initialize_path(&paths[i], i);
    }

    // 1. Confirm features under min/max comp
    // 1.1 get labels of min/max inputs
    // Note that the br for left/right-most path is set in tree_pred()
    int r_min = tree_pred(paths, features_min, -1, 0, 0, &num_queries, &num_fia);
    int r_max = tree_pred(paths, features_max, -1, 1, 0, &num_queries, &num_fia); // 42 in this example

    float fea_range_on_path[NUM_FEA_LABEL][2];
    memcpy(fea_range_on_path, fea_range, NUM_FEA_LABEL * 2 * sizeof(float));

    single_attack_epoch(paths, features_min, fea_range, fea_range_on_path, uniq_dup_fea_path, r_min, 0, epi, &num_queries, &num_fia);
    
    if (paths[0].nodes[0].threshold != -2.0)
    {
        paths[r_max].nodes[0].feature_index = paths[0].nodes[0].feature_index;
        paths[r_max].nodes[0].threshold = paths[0].nodes[0].threshold;
    }
    else
    {
        printf("\nBug! The threshold of the root node should be confirmed!\n");
    }
    
    for (int i = 0; i < NUM_FEA; i++) {
        if (paths[r_max].nodes[0].feature_index == i)
        {
            float m_input[NUM_FEA];
            memcpy(m_input, features_max, NUM_FEA * sizeof(float));
            float stride = flexible_stride(paths[r_max].nodes[0].threshold, epi, 10);
            m_input[i] = paths[r_max].nodes[0].threshold + stride;
            int cnt = 0;
            num_queries++;
            if (tree(m_input, &cnt, -1, 1, 0) == r_max)
            {
                uniq_dup_fea_path[i] = 0; // uniq
            }
            else
            {
                uniq_dup_fea_path[i] = 1; // dup 
            }
        }
        else
        {
            uniq_dup_fea_path[i] = -1;
        }
    }
    single_attack_epoch(paths, features_max, fea_range, fea_range_on_path, uniq_dup_fea_path, r_max, 1, epi, &num_queries, &num_fia);

    
    // path_recvoer_status records if the path is recovered
    // default is 0 (finished), 1 indicates not finished
    int path_recvoer_status[r_max + 1];
    memset(path_recvoer_status, 0, sizeof(path_recvoer_status));
    for (int i = 1; i < r_max; i++) { // 36 for only test left subtree

        path_recvoer_status[i] = 1;
    }

    // indicates if this path should be useds as base path (0: No, 1: Yes, default is 0)
    int new_base_path[r_max + 1];
    memset(new_base_path, 0, sizeof(new_base_path));
    new_base_path[0] = 1;
    new_base_path[r_max] = 1;

    // indicates the start node index in each path, which is used to extend the new path
    int path_node_start_idx[r_max + 1];
    memset(path_node_start_idx, 0, sizeof(path_node_start_idx));
    path_node_start_idx[0] = 1; // exclude the root node
    path_node_start_idx[r_max] = 1;

    // indicates this path is in let or right sub-tree
    int LR_path_indictor[r_max + 1];
    memset(LR_path_indictor, 0, sizeof(LR_path_indictor));
    LR_path_indictor[0] = 0;
    LR_path_indictor[r_max] = 1;

    // each new path inherents the input data from the parent path 
    float input_inherent[r_max + 1][NUM_FEA];
    memcpy(input_inherent[0], features_min, NUM_FEA * sizeof(float));
    memcpy(input_inherent[r_max], features_max, NUM_FEA * sizeof(float));

    int ct = 0;
    while (sum(path_recvoer_status, r_max + 1) != 0 && ct < 10) // && ct < 10
    {
        printf("\n%d-th loop\n", ct);
        recur_attack(paths, r_max + 1, fea_range, path_recvoer_status, path_node_start_idx, input_inherent, new_base_path, LR_path_indictor, epi, &num_queries, &num_fia);
        ct++;
    }
    
    printf("\n---------------------------------------------------------\n"); 
    for (int i = 0; i < r_max + 1; i++) {
        printf("Path for label %d with %d nodes\n", paths[i].label, paths[i].num_nodes);
        for (int j = 0; j < paths[i].num_nodes; j++) {
            printf("  Node %d: (feature_index: %d, comparison_type: %d, threshold: %.6f)\n",
                   j, paths[i].nodes[j].feature_index, paths[i].nodes[j].comparison_type, paths[i].nodes[j].threshold);
        }
    }

    printf("\nRecover tree needs %lu queries, including %lu fault runs, under granularity ε = %.6f\n", num_queries, num_fia, epi);
    // export_tree_csv(paths, r_max + 1);

    return 0;
}