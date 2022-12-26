#include<stdio.h>
#include<stdbool.h>
#include"bst.h"

bool isLeaf(struct Node* ptr){
	return (!(ptr->left) && !(ptr->right)) ? true : false;
}

struct Node* minValNode(struct Node* ptr){
	return ((ptr)->left) ? minValNode(ptr->left) : ptr;
}

struct Node* maxValNode(struct Node* ptr){
	return ((ptr)->right) ? maxValNode(ptr->right) : ptr;
}

struct Node* initNode(int val){
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* rootInit(){
	return NULL;
}

struct Node* rootInitData(int val){
	return initNode(val);
}

void addDataMain(struct Node* ptr, struct Node* val_ptr){
	//duplicate values not permitted
	if(val_ptr->data == ptr->data){
		free(val_ptr);
		return;
	}
	if(val_ptr->data < ptr->data){
		if(!ptr->left){
			ptr->left = val_ptr;
			return;
		}
		addDataMain(ptr->left, val_ptr);
	}
	else{
		if(!ptr->right){
			ptr->right = val_ptr;
			return;
		}
		addDataMain(ptr->right, val_ptr);
	}
}

void addData(struct Node** ptr, int val){
	if(!(*ptr)){
		(*ptr) = initNode(val);
		return;
	}
	addDataMain((*ptr), initNode(val));
}

void printTree(struct Node* ptr){
	if(!ptr)
		return;
	printTree(ptr->left);
	printf("\t%d", ptr->data);
	printTree(ptr->right);
}

bool searchNode(struct Node* ptr, int val){
	if(!ptr)
		return false;
	if(ptr->data == val)
		return true;
	return (ptr->data > val) ? searchNode(ptr->left, val) : searchNode(ptr->right, val);
}

void deleteNode(struct Node** ptr, int val){
	if(!(*ptr))
		return;
	if(val > (*ptr)->data)
		deleteNode(&(*ptr)->right, val);
	else if(val < (*ptr)->data)
		deleteNode(&(*ptr)->left, val);
	else{
		if((!(*ptr)->left) && (!(*ptr)->right)){
			struct Node* temp = *ptr;
			*ptr = NULL;
			free(temp);
			return;
		}
		if(!(*ptr)->left){
			struct Node* temp = *ptr;
			ptr = &(*ptr)->right;
			free(temp);
			return;
		}
		if(!(*ptr)->right){
			struct Node* temp = *ptr;
			ptr = &(*ptr)->left;
			free(temp);
			return;
		}
		struct Node* temp = minValNode((*ptr)->right);
		(*ptr)->data = temp->data;
		deleteNode(&(*ptr)->right, temp->data);
	}
}

int main(){
	struct Node* root = rootInitData(108);
	addData(&root, 42);
	addData(&root, 170);
	addData(&root, 64);
	printTree(root);
	deleteNode(&root, 64);
	printf("\n");
	printTree(root);
	return 0;
}
