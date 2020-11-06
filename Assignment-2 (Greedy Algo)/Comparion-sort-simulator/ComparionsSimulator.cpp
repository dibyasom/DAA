#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int ll;
typedef unsigned long long int llu;
typedef long double ld;

ll* newArr(llu);

ll* newArr(llu n){
	return (ll*)malloc(n*sizeof(ll));
}

void fillVal(ll* arr, llu n, ll val){
	for(llu i=0; i<n; i++)
		arr[i]= val;
}

ll* randomFill(llu n, ll min_val, ll max_val){
	ll* arr = newArr(n);
	for(llu i=0; i<n; i++){
		arr[i] = rand()%(max_val-min_val)+min_val;
	}
	return arr;
}

void swap(ll* a, ll* b){
	ll temp = *a;
	*a = *b;
	*b = temp;
}

/*Quiksort*/ //Commenting out because this has n^2 worst runtime.
//ll fix_pivot(ll* v, ll l, ll r){
//	ll pivot = v[r], ind = l-1;
//	for(ll i=l; i<r; i++){
//		if(v[i]>=pivot){
//			ind++;
//			swap(v+i, v+ind);
//		}
//	}
//	swap(v+(++ind), v+r);
//	return ind;
//}
//
//void quicksort(ld* v, ll l, ll r){
//	if(l<r){
//		ll pi = fix_pivot(w, v, l, r);
//		quicksort(v, l, pi-1);
//		quicksort(v, pi, r);
//	}
//}

int number_of_comp = 0;

void merge(ll* arr, ll l, ll m, ll r){
    ll i, j, k;  
    ll n1 = m - l + 1;  
    ll n2 = r - m;  
  
    int L[n1], R[n2];  
  
//    Generating left and right sub-arrays
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
  
    i = 0;  
    j = 0;   
    k = l; // Initial index of merged subarray  
    
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) { 
		    number_of_comp++; 
            arr[k] = L[i];  
            i++;  
        }  
        else {  
      	    number_of_comp++; 
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* Copy the remaining elements of L[], if there  
    are any */
    while (i < n1) {   
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* Copy the remaining elements of R[], if there  
    are any */
    while (j < n2) {   
        arr[k] = R[j];  
        j++;  
        k++;  
    }  	
}

void mergesort(ll* arr, ll l, ll r){
    if(l>=r)
	   return;
    ll mid = (l+r)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    
    merge(arr, l, mid, r); 		 	
}

void printArr(ll* arr, llu size){
	printf("[");
	for(ll i=0; i<size; i++)
 	    printf("%d ", arr[i]);
	printf("]\n");
}

int main(void){
	llu n, size = 5; 
	ll benchmark_size, b_size, min, max;
	
	printf("~~Comparison-Based-SortingAlgo Simulator~~\n\n(0)Worst-Case [Filled with same elements]\n(1)Filled with Random-Elements.\nChoice > ");
	int choice; scanf("%d", &choice);
	
	if(choice){
		printf("\n\nBenchmark Configurator.\nRandom Array size fixed @%llu,\nMin-Val & Max-Val in array > ", size);
		scanf("%d %d", &min, &max);
	}
	
	printf("No. of iterations [>1000 is good]> ");
	scanf("%lld", &benchmark_size);
	b_size= benchmark_size;
	
	ll* arr;
	ll* comp_freq = newArr(benchmark_size); //Store the no. of comparisions required to sort benchmark_size number of arrays.
	fillVal(comp_freq, benchmark_size, 0);
	
	//Running mergesort benchmark_size times.
	while(b_size--){
		number_of_comp= 0;
		if(choice)
    	    arr= randomFill(size, min, max);
		else{
			arr= newArr(size);
			fillVal(arr, size, rand()%1000);
		}
		
		//Display random-generated array.
		printf("\nInput Arr #%lld> ", benchmark_size-b_size);
		printArr(arr, size);
		
		//Call Comparison Based sorting algo, mergesort in my case:3
		mergesort(arr, 0, size-1);
		
		//Update count of number_of_comp in freq array.
		comp_freq[number_of_comp]++;
		
		printf("No. of comparisons> %d\n", number_of_comp);
	}
	
	//Display frequency table of comparisions.
	if(choice)
 	    printf("\nRandom Filled Array:3\n<No. of comparisons>\tFrequency\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	else
		printf("\nFilled w Identical elements:3\n<No. of comparisons>\tFrequency\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(ll i= 0; i<benchmark_size; i++)
		if(comp_freq[i])
		    printf("\t%lld\t\t%lld\n", i, comp_freq[i]);
  
	//Occurence of 7?
	printf("\nInference>\nFrequency of 7-Comparisons while sorting %lld-random worst-case arrays> %.2f%%\n\n", benchmark_size, ((float)comp_freq[7]/benchmark_size)*100);
	return 0;
}

