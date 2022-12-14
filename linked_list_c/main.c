#include"linkedlist.h"

struct Node* listInitMain(int arr[], size_t arr_size, size_t counter){
	if(counter >= arr_size )
		return NULL;
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = arr[counter];
	temp->next = listInitMain(arr, arr_size, counter + 1);
	return temp;
}

struct Node* listInit(int arr[], size_t arr_size){
	if(arr_size == 0)
		return NULL;
	size_t counter = 0;
	return listInitMain(arr, arr_size, counter);
}

struct Node* listInitDat(int data){
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void pushLast(struct Node* head, int data){
	if(!head){
		printf("\nThe list is empty. Initialize before addition.");
		return;
	}
	struct Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = (struct Node*) malloc(sizeof(struct Node));
	temp->next->data = data;
	temp->next->next = NULL;
}

void printList(struct Node* head){
	if(!head){
		printf("\nThe list is empty");
		return;
	}
	printf("\n");
	struct Node* temp = head;
	while(temp){
		printf("\t%d", temp->data);	
		temp = temp->next;
	}
}

void pushFirst(struct Node** head, int data){
	if(!*head){				
		*head = listInitDat(data);
		return;
	}
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void popFirst(struct Node** head){
	if(!*head){
		printf("\nThe list is empty. Initialize before deletion");
		return;
	}
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void popLast(struct Node* head){
	if(!head){
		printf("\nThe list is empty. Initialize before deletion");
		return;
	}
	struct Node* temp = head;
	while(temp->next->next){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void deleteData(struct Node** head, int data){
	if(!*head){
		printf("\nThe list is empty. Initialize before deletion");
		return;
	}
	if((*head)->data == data){
		popFirst(head);
		return;
	}
	struct Node* temp = *head;
	while(temp->next){
		if(temp->next->data == data){
			struct Node* temp2 = temp->next;
			temp->next = temp->next->next;
			free(temp2);
			return;
		}
		temp = temp->next;
	}
	printf("\nThe value: %d was not found in the linked list", data);
}

void searchData(struct Node* head, int data){
	if(!head){
		printf("\nThe list is empty");
		return;
	}
	size_t counter = 1;
	struct Node* temp = head;
	while(temp){
		if(temp->data == data){
			printf("\nThe value: %d exists in the linked list at position: %d", data, counter);
			return;
		}
		counter++;
		temp = temp->next;
	}
	printf("\nThe value: %d does not exist in the linked list");
}

//test for errors with single and double element lists
struct Node* reverseListMain(struct Node* temp){
	if(!temp->next){
		rev_head = temp;
		return temp;
	}
	struct Node* temp2 = reverseListMain(temp->next);
	temp2->next = temp;
	return temp;
}

struct Node* reverseList(struct Node* head){
	if(!head){
		printf("\nThe list is empty. Add elements before reversal");
		return NULL;
	}
	struct Node* tail_temp = reverseListMain(head);
	tail_temp->next = NULL;
	struct Node* temp2 = rev_head;
	rev_head = NULL;
	return temp2;
}

int main(){
	int arrL[] = {1,2,3,4,5,6, 7};
	struct Node* head = listInit(arrL, sizeof(arrL)/sizeof(arrL[0]));
	printList(head);
	pushLast(head, 8);
	printList(head);
	pushLast(head, 9);
	printList(head);
	pushLast(head, 10);
	printList(head);
	pushFirst(&head, 1000);
	printList(head);
	popFirst(&head);
	printList(head);
	popLast(head);
	printList(head);
	deleteData(&head, 1);
	printList(head);
	deleteData(&head, 4);
	printList(head);
	searchData(head, 2);
	struct Node* newHead = reverseList(head);
	printList(newHead);
	return 0;
}
