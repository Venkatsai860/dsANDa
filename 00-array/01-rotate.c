#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"


int *rotate_right (int *arr, int size, int times) {
	printf("int arr of size %d to be rotated %d times\n", size, times);
	int *temparr = (int *) malloc(size*4);
	*(temparr+4) = -1;
	return temparr;
}
