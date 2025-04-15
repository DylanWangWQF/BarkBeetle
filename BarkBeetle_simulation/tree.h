#ifndef TREE_H
#define TREE_H

#include <stddef.h>  // For NULL

typedef enum {
    TREE_TYPE_1,
    TREE_TYPE_2,
    TREE_TYPE_3,
    TREE_TYPE_4,
    TREE_TYPE_5,
    NUM_TREE_TYPES
} TreeType;

// Define a function pointer type for tree functions
typedef int (*TreeFunction)(float features[], int *cnt, int node_loc, int flag, int ifFIA);

// Declare the global tree function pointer
extern TreeFunction tree;

// Function to set the correct tree function
void set_tree_function(TreeType type);

// Declare different tree function implementations
int tree1(float features[], int *cnt, int node_loc, int flag, int ifFIA);
int tree2(float features[], int *cnt, int node_loc, int flag, int ifFIA);
int tree3(float features[], int *cnt, int node_loc, int flag, int ifFIA);
int tree4(float features[], int *cnt, int node_loc, int flag, int ifFIA);
int tree5(float features[], int *cnt, int node_loc, int flag, int ifFIA);

#endif