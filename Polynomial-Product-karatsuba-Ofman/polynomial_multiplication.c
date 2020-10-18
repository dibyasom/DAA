#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int ll;
typedef unsigned long long int llu;

ll check_powerOf2(ll terms){
	 return (float)log2(terms) == (int)log2(terms);
}

ll* newArr(llu n){
	return (llu*)malloc(n*sizeof(llu));
}

void fillArr(ll* arr, llu n, char* msg){
	printf("%s\n", msg);
	for(llu i=0; i<n; i++)
		scanf("%lld", (arr+ i));
}

void fillVal(ll* arr, llu size,ll val){
	for(llu i=0; i< size; i++)
		*(arr+ i) = 0;
}

void fetchSize(llu* size, char* msg){
	printf("%s ", msg);
	llu n; scanf("%lld", size);
}

void printArr(ll* arr, llu n){
	printf("\n\n~~~<Product Poly>~~~\n");
	for(ll i=0; i< n; i++)
		if(n-i > 1)
			printf("%lldx^%lld + ", *(arr+ i), (n-i));
		else
			printf("%lld", *(arr+ i));
	printf("\nDegree> %llu", n-1);

	printf("\n\n");
}

void naive_multiply(ll* a, ll* b, llu terms){ //Ignore,  only used for verifying the result of div-&-conq.
	ll prod_terms = 2*terms-1;
	ll* prod = newArr(prod_terms); fillVal(prod, prod_terms, 0);
	for(llu i=0; i<terms; i++)
		for(llu j=0; j<terms; j++)
			prod[i+j] += a[i]*b[j];
	printArr(prod, prod_terms);
	free(prod);
}

void print(ll* arr, llu n){
	for(llu i=0; i< n; i++)
		printf("%lld ", *(arr+ i));
}

ll* multiply_divide_and_conquer(ll* A, ll* B, ll n, ll a, ll b){// div-&-conq implementation.
	

	if(n == 1){
		ll* R = newArr(1);
		R[0] = A[a]*B[b];
		// printf("%lld*\n", R[0]);
		return R;
	}

	ll* R = newArr(2*n-1);

	ll* D1E1 = multiply_divide_and_conquer(A, B, n/2, a, b); //Prod of terms, with power >= n/2 :)
	ll* D0E0 = multiply_divide_and_conquer(A, B, n/2, a+n/2, b+n/2); //Prod of terms, with power < n/2 :))

	ll* D1_plus_D0 = newArr(n/2);
	ll* E1_plus_E0 = newArr(n/2);

	for(ll i=0; i<=(n-2); i++)
		R[i] = D1E1[i];
	for(ll i=n; i<=(2*n-2); i++)
		R[i] = D0E0[i-n];

	for(ll i=0; i<n/2; i++){
		D1_plus_D0[i] = A[a+i]+A[(a+n/2)+i];
		E1_plus_E0[i] = B[b+i]+B[(b+n/2)+i];
	}

	ll* D1E0_plus_D0E1 = multiply_divide_and_conquer(D1_plus_D0, E1_plus_E0, n/2, 0, 0);
	// print(D1E0_plus_D0E1, n/2);

	for(ll i=n/2; i<(n+n/2-1); i++){
		R[i] += (*(D1E0_plus_D0E1++)-*(D1E1++)-*(D0E0++));
		// R[i] += *(D0E1++) + *(D1E0++);
	}

	return R; 
}

int main(void){
	llu terms; fetchSize(&terms, "Degree of polynomial? (Must be (2^n -1)) >> ");
	terms++; //Number of terms = degree+1

	if(check_powerOf2(terms)) //Check if the given number of terms is a power of 2?
	{
		ll* A = newArr(terms); fillArr(A, terms, "Coeff. for eq.A? ");
		ll* B = newArr(terms); fillArr(B, terms, "Coeff. for eq.B? ");

		// naive_multiply(A, B, terms);
		printf("Engaging div-&-conq!\n");
		ll* R = multiply_divide_and_conquer(A, B, terms, 0, 0);
		printArr(R, 2*terms-1);

		free(A); free(B);
	}
	else{
		printf("Cannot be solved by this algo, try again later, bye:)\n");
	}

	return 0;
}