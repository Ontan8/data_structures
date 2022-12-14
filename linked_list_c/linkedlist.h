#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* rev_head = NULL;

#endif
