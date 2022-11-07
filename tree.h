#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "my_string.h"
#include "generic_vector.h"
struct node;
typedef struct node Node;

struct node {
	MY_STRING hKey;
	G_VECTOR hVector;
	Node* left;
	Node* right;
	int height;
};

struct tree;
typedef struct tree Tree;

struct tree {
	Node* root;
};

//void tree_insert(Node** pRoot, MY_STRING hKey, MY_STRING hWord);
Tree* tree_init_default(void);

void tree_insert(Tree* pTree, MY_STRING hKey, MY_STRING hWord);

void node_insert(Node** pRoot, MY_STRING hKey, MY_STRING hWord);

Node* traverse_find_largest(Node* root);

void traversal_in_order(Node* root);

int avl_node_height(Node* root);

int avl_max_height(int h1, int h2);

int check_balance(Node* pRoot);

Node* rotate_left(Node* pRoot);

Node* rotate_right(Node* pRoot);

void tree_destroy_helper(Node* root);

void tree_destroy(Tree** tree);

#endif
