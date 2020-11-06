// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

void printVect(vector<int>& arr);

int minCoins_greedy(int* deno, int n, int V) 
{ 
    sort(deno, deno + n); 
  
    // Initialize result 
    vector<int> ans; 
  
    // Traverse through all denomination 
    for (int i = n - 1; i >= 0; i--) { 
  
        // Find denominations 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  	printVect(ans);
    return (int)ans.size();
} 

void printVect(vector<int>& arr){
	for(int i= 0; i<arr.size(); i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

int minCoins_dynamic(int* coins, int m, int V) 
{ 
    
    int table[V+1]; 
  
    table[0] = 0; 
  
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  
    for (int i=1; i<=V; i++) 
    { 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    return table[V]; 
} 

int* fill_exponents(int size){
	int c= rand()%19+2; //Random value for C.
	
	int* arr= (int*)malloc(size*sizeof(int));
	for(int i=0; i<size; i++)
		arr[i]= (int)pow(c, i);
		
	return arr;	
}

int main() 
{ 
  	int arr[] = {1, 7, 14, 20, 61};
  	int size= 5;
    int benchmark_size= 10000;
    int b_size= benchmark_size;
    
    //Stress Test :)
	while(benchmark_size--){
		
//		//Create random-size, random-filled array (To be assumed as coins).
//		int size= rand()%4+2;
//		arr= fill_exponents(size);
		
		//Generate random value for amount to be achieved as sum of least no. of coins.
		int val= rand()%40+1;
		
		cout << "Iteration<" << (b_size-benchmark_size) << ">" << endl;
		//if return from dynamic= return from greedy, probably it's correct.
		if(minCoins_dynamic(arr, size, val)== minCoins_greedy(arr, size, val))
	 	    cout << " Stress Result > verified @value= " << val << endl;
		else{
		//One of the algo has generated wrong res.
			cout << "Broke @value= " << val << endl;
			break;
		}
	}
	return 0; 
} 


