#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define SIZE sizeof(node)

static node *head;	

// print list from a certain node
static void print_list (node *from) {
	
	node *temp = from;				// make new node temp = from (to not change original)
	
	while (temp != NULL) {				// while it is not NULL
		printf("%d -> ", temp->data);		// print its data
		temp = temp->next;			// and move to next node
	}

	printf("NULL\n");
}


// append a node at the end (and update curr node)
static node *append (node *curr, int data) {
	
	node *temp = (node *) malloc(SIZE);		// allocate memory for new node
	temp->data = data;				// set its data to data
	temp->next = NULL;				// next = NULL (since appended at the end)
	
	if (curr == NULL) {				// if curr is NULL (no nodes yet),
		curr = temp;				// assign curr to newly made node
		head = curr;				// update head (since this is first node)
		return curr;				// return pointer to current node
	}

	curr->next = temp;				// else make curr's next to temp (appended node)

	return temp;					// return node *temp
}


static void add_node (int data) {
}


static void prepend (int data) {
	
	node *temp = (node *) malloc(SIZE);
	temp->data = data;
	head = temp;

	if (head == NULL) {
		head->next = NULL;
	}
	else {
		temp->next = head;
	}
}

static void remove_node (node *ptr) {

}


int main(){
	

//	node *n1 = append(head, 0);			// first node (curr node = HEAD (no nodes yet))
//	node *n2 = append(n1,   1);			// second node (append to n1)
	
	prepend(-1);

	print_list(head);

	
	return 0;
}
