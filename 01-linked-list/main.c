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


// adds node with data (add_val) after a value (find_val) is encountered
static void insert_node (int find_val, int add_val) {
	
	node *temp1 = head;					

	if (temp1 == NULL) {				// if no nodes yet, 
		head = append (head, add_val);		// make one
		return;
	}

	while (temp1 != NULL) {					// else traverse the list
		if (temp1->data == find_val) {			// if data found
			node *temp2 = (node *) malloc(SIZE);	// make a new node
			temp2->next = temp1->next;		// new node's next = prev's next
			temp2->data = add_val;			// assign data
			temp1->next = temp2;			// prev's node = newly made node
			return;
		}
		temp1 = temp1->next;				// continue traversing
	}

	printf ("%d not in the list.\n");			// at this point no value found

}


// prpends a node to head
static void prepend (int data) {

	if (head == NULL) {				// if head is null,
		head = (node *) malloc(SIZE);		// allocate size for head
		head->next = NULL;			// make head -> next = null
		head->data = data;			// make head -> data = data	
	}					

	else {						// else head is not null
		node *temp = (node *) malloc(SIZE);	// make a temp node
		temp->data = data;			// assign it data
		temp->next = head;			// make it point to head (prepend step 1)
		head = temp;				// make temp the new head (prepend step 2)
	}
}


static void remove_node (int data) {
	
	node *temp1 = head;
	
	if (temp1 == NULL) {
		printf("List empty.\n");
		return;
	}

	if (temp1->next == NULL) {
		head = NULL;
		return;
	}

	while (temp1->next != NULL) {
		if (temp1->next->data == data) {
			temp1->next = temp1->next->next;
			return;
		}	
		temp1 = temp1->next;
	}

	printf("Value %d not in the list\n", data);



}


int main(){
	

	node *n1 = append(head, 1);			// first node (curr node = HEAD (no nodes yet))
	node *n2 = append(n1,   2);			// second node (append to n1)
	node *n3 = append(n2,   3);
	printf("Append test\t:\t");			// formatting (see output)
	print_list(head);
	
	prepend(-1);					// prepend tests
	prepend(-2);
	prepend(-3);					// head should be node with -3 data at this point
	printf("Prepend test\t:\t");			// formatting (see output)
	print_list(head);

	insert_node(-1, 0);				// insert node with data 0 after node with -1 found
	printf("Insert test\t:\t");			// formatting (see output)
	print_list(head);				// there should be 0 between -1 and 1

	remove_node(3);					// insert node with data 0 after node with -1 found
	printf("Remove test\t:\t");			// formatting (see output)
	print_list(head);				// there should be 0 between -1 and 1

	
	return 0;
}
