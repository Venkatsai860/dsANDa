#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

void printintarr(int *arr, int size) {
	printf("intarr: ");
	for (int i = 0; i < size; i++) {
		printf(" %d ", arr[i]);
	}
	printf("\n");
}


void printstrarr(char **str, int size){
	printf("chararr: ");
	for (int i = 0; i < size; i++) {
		printf(" %s ", str[i]);
	}
	printf("\n");

}


void reverse_arr(int *arr, int size) {
	for (int i =0; i < size / 2; i++){
		int temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size - i-1] = temp;
	}
}


int main(){
	int intarr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	// can manually do intarr1[size]
	int intarr1size = sizeof(intarr1)/sizeof(int);

	char *strarr1[3] = {"hi", "hello", "bye"};

	//PRINT
	printintarr(intarr1, intarr1size); 
	printstrarr(strarr1, sizeof(strarr1)/sizeof(char *));

	//REVERSE
	reverse_arr(intarr1, intarr1size);
	printintarr(intarr1, intarr1size);

	//ROTATE RIGHT
	int rotat_times = 3;
	int *rotated_r = rotate_right(intarr1, intarr1size, rotat_times);
	printf("Roatated right %d times ", rotat_times);
	printintarr(rotated_r, intarr1size);
	free(rotated_r);
}
