#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


int *rotate_right (int *arr, int size, int times) {
	printf("int arr of size %d to be rotated %d times\n", size, times);
	
	times = times % size;

	if (times == 0) return arr;

	int *temparr = (int *) malloc(size*4);

	for (int i = 0; i < size; i++) {
		*(temparr+i) = arr[size-i-times];
	}

	return temparr;
}
