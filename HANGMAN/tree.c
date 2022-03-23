#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "my_string.h"
 
Node* rotate_right(Node* pRoot) {

	if(pRoot->left == NULL || pRoot->left->right == NULL){

		return pRoot;
	}

	Node* tmp_root = pRoot->left;
	Node* tmp_left = (tmp_root)->right;

	tmp_root->right = pRoot;
	pRoot->left = tmp_left;

	pRoot->height = avl_max_height(avl_node_height(pRoot->left), avl_node_height(pRoot->right)) + 1;
	tmp_root->height = avl_max_height(avl_node_height(tmp_root->left), avl_node_height(tmp_root->right)) + 1;

	return tmp_root;
}

Node* rotate_left(Node* pRoot){

	if(pRoot->right == NULL || pRoot->right->left == NULL){
		return pRoot;
	}

	Node* tmp_root = pRoot->right;
	Node* tmp_right = tmp_root->left;

	tmp_root->left = pRoot;
	pRoot->right = tmp_right;

	pRoot->height = avl_max_height(avl_node_height(pRoot->left), avl_node_height(pRoot->right)) + 1;
	tmp_root->height = avl_max_height(avl_node_height(tmp_root->left), avl_node_height(tmp_root->right)) + 1;

	return tmp_root;

}

Tree* tree_init_default(void){

	Tree* tree = (Tree*)malloc(sizeof(Tree));

	if(tree != NULL){

		tree->root = NULL;
	}

	return tree;
}	

void tree_insert(Tree* pTree, MY_STRING hKey, MY_STRING hWord){

	if(pTree != NULL){

		node_insert(&(pTree->root), hKey, hWord);
	}

	if(pTree == NULL){

		printf("error tree null");
		exit(1);
	}
}

void node_insert(Node** pRoot, MY_STRING hKey, MY_STRING hWord) {
	if (*pRoot == NULL) {

		*pRoot = (Node*)malloc(sizeof(Node));

		if (*pRoot == NULL) {

			printf("error\n");
			exit(1);
		}

		(*pRoot)->hKey = my_string_init_default();
		my_string_assignment(&((*pRoot)->hKey), hKey);

		(*pRoot)->hVector = g_vector_init_default(my_string_assignment, my_string_destroy);
		g_vector_push_back((*pRoot)->hVector, hWord);

		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		(*pRoot)->height = 1;
	}

	else if(my_string_compare(hKey, (*pRoot)->hKey) < 0){

		node_insert(&((*pRoot)->left), hKey, hWord);
	}

	else if(my_string_compare(hKey, (*pRoot)->hKey) > 0){

		node_insert(&((*pRoot)->right), hKey, hWord);
	}

	else{

		g_vector_push_back((*pRoot)->hVector, hWord);
	}
	
	(*pRoot)->height = 1 + avl_max_height(avl_node_height((*pRoot)->left), avl_node_height((*pRoot)->right));

	int balance = check_balance((*pRoot));
	
	if(balance > 1 && my_string_compare(hKey, ((*pRoot)->left->hKey)) < 0){

		*pRoot = rotate_right(*pRoot);
		//left left case
	}

	if(balance < -1 && my_string_compare(hKey, ((*pRoot)->right->hKey)) > 0){

		*pRoot = rotate_left(*pRoot);
		//right right
	}

	if(balance > 1 && my_string_compare(hKey, ((*pRoot)->left->hKey)) > 0){

		(*pRoot)->left = rotate_left((*pRoot)->left);
		*pRoot = rotate_right(*pRoot);
		//left right
	}

	if(balance < -1 && my_string_compare(hKey, ((*pRoot)->right->hKey)) < 0){

		(*pRoot)->right = rotate_right((*pRoot)->right);
		*pRoot = rotate_left(*pRoot);
		//right left
	}
	
}

Node* traverse_find_largest(Node* root) {

	if(root != NULL){

		if(root->left != NULL && root->right != NULL){	

			Node* left = traverse_find_largest(root->left);
			Node* right = traverse_find_largest(root->right);	
	
			if(g_vector_get_size(right->hVector) == g_vector_get_size(left->hVector)){

				if(g_vector_get_size(right->hVector) < g_vector_get_size(root->hVector)){

					return root;
				}

				else{

					return right;
				}

			}	

			else if(g_vector_get_size(left->hVector) > g_vector_get_size(right->hVector)){

				if(g_vector_get_size(left->hVector) > g_vector_get_size(root->hVector)){

					return left;
				}

				else{

					return root;
				}
			}
			else if(g_vector_get_size(right->hVector) > g_vector_get_size(root->hVector)){

				return right;
			}

			else{

				return root;
			}
		}

		else if(root->left == NULL && root->right == NULL){

			return root;
		}

		else if(root->left == NULL){

			if(g_vector_get_size(root->right->hVector) > g_vector_get_size(root->hVector)){

				return root->right;
			}

			else{

				return root;
			}
		}

		else{

			if(g_vector_get_size(root->left->hVector) > g_vector_get_size(root->hVector)){

				return root->left;
			}

			else{

				return root;
			}
		}

	}

	return NULL;
}


void traversal_in_order(Node* root) {
	
	if (root != NULL) {

		traversal_in_order(root->left);

		my_string_insertion((root->hKey), stdout);
		printf(": %d\n\n", g_vector_get_size(root->hVector));

		traversal_in_order(root->right);
	}
}

int check_balance(Node* root) {

	if(root == NULL){

		return 0;
	}

	else{

		return avl_node_height(root->left) - avl_node_height(root->right);
	}
}

int avl_max_height(int h1, int h2){

	return (h1 > h2) ? h1 : h2;
}
int avl_node_height(Node* root){

	return (root == NULL) ? 0 : root->height;
}
		
void tree_destroy_helper(Node* root){

	if(root == NULL){

		return;
	}

	tree_destroy_helper(root->right);
	tree_destroy_helper(root->left);

	my_string_destroy(&(root->hKey));

	if(root->hVector != NULL){

		g_vector_destroy(&(root->hVector));
	}

	free(root);
}

void tree_destroy(Tree** tree){

	if(*tree != NULL){

		tree_destroy_helper((*tree)->root);
		free(*tree);	
		*tree = NULL;
	}
}
