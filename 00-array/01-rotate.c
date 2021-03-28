#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/* time: O(n), space: O(n) */
int *rotate_right (int *arr, int size, int times) {
	times = times % size;
	if (times == 0) return arr;
	int *temparr = (int *) malloc(size*4);
	for (int i = 0; i < size; i++) {
		*(temparr+((i+times)%size))= arr[i];
	}
	return temparr;
}

/* time: O(n), space: O(n) */
int *rotate_left (int *arr, int size, int times) {
	times = times % size;
	if (times == 0) return arr;
	int *temparr = (int *) malloc(size*4);
	for (int i = 0; i < size; i++) {
		int temp = (i-times) < 0 ? (i-times)%size + size : (i-times)%size;	// negative modulo for c
		*(temparr+temp)= arr[i];
	}
	return temparr;
}

/* time: O(n), space: O(1) */


