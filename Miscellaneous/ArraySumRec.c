#include<stdio.h>

int sum_of_arr(int*, int);

int sum_of_arr(int *arr, int size){//Recursive function to calculate the sum of array-elements.
	static int curr= 0;	 		   //  <--Current index.
	if(curr>=size)				   //  <--Out of bound check.
		return 0;
	return arr[curr++]+sum_of_arr(arr, size);
}

int main(void){
	
	//Accept arr input from user.
	printf("\nSize of array> ");
	int size; scanf("%d", &size);

	printf("Drop all elements as space separated values>>>>>\n");
	int arr[size]; 
	for(int i=0; i<size; i++)
		scanf("%d", &arr[i]);

	//display result.
	printf("\n\nSum of array-elements> %d\n", sum_of_arr(arr, size));

	return 0;
}