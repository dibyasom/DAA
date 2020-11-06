#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;
typedef unsigned long long int llu;
typedef long double ld;

ll* newArr(llu n){
	return (llu*)malloc(n*sizeof(llu));
}

void fillArr(ll* arr, llu n, char* msg){
	printf("%s\n", msg);
	for(llu i=0; i<n; i++)
		scanf("%lld", (arr+ i));
}

ll maximum_contiguous_subarray(ll* arr, ll size){
	ll max_sum=0, curr_sum = 0;
	for(ll i=0; i<size; i++){
		curr_sum+=arr[i];
		curr_sum = (curr_sum<0) ?0 :curr_sum;
		if(curr_sum>max_sum)
			max_sum = curr_sum;
	}
	return max_sum;
}



int main(void){

	llu size; printf("Size of arr > ");scanf("%llu", &size); 
	ll* arr = newArr(size); fillArr(arr, size, "Drop all elements, as space separated values");
	ll max_sum 	  = maximum_contiguous_subarray(arr, (ll)size-1);
	printf("Max positive sum: %lld\n", max_sum);
	return 0;
}