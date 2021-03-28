#include <stdio.h>
#include "linkedlist.h"

static node *head;
static node *curr;
static node *tail = NULL;

static void print_list (node *head) {
	node *temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

static void append (int data) {
}
static void add_node (int data) {
}

static void prepend (node *ptr) {

}

static void remove_node (node *ptr) {

}


int main(){
	
	node n0, n1, n2;
	
	n0.data = 0;
	n1.data = 1;
	n2.data = 2;	

	head = &n0;
	n0.next = &n1;
	n1.next = &n2;
	n2.next = NULL;
	tail = &n2;

	print_list(head);

	
	return 0;
}
