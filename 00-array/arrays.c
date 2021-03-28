#include <stdio.h>


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


int main(){
	int intarr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	char *strarr1[3] = {"hi", "hello", "bye"};

	printintarr(intarr1, sizeof(intarr1)/sizeof(int));
	printstrarr(strarr1, sizeof(strarr1)/sizeof(char *));
}
