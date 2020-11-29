#include <bits/stdc++.h> 
using namespace std; 
 
void kFactors(int n, int k) 
{ 
	vector<int> P; 

	while (n%2 == 0) 
	{ 
		P.push_back(2); 
		n /= 2; 
	} 
 
	for (int i=3; i*i<=n; i=i+2) 
	{ 
		while (n%i == 0) 
		{ 
			n = n/i; 
			P.push_back(i); 
		} 
	} 

	if (n > 2) 
		P.push_back(n); 

	if (P.size() < k) 
	{ 
		cout << "-1" << endl; 
		return; 
	} 

	for (int i=0; i<k-1; i++) 
		cout << P[i] << ", "; 
 
	int product = 1; 
	for (int i=k-1; i<P.size(); i++) 
		product = product*P[i]; 
	cout << product << endl; 
} 

bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

int main() 
{ 
    int t; cin >> t;
    while(t--){
    	int k,x; cin >> k >> x;
    	if(isPrime(x) || k>=x)
    	    cout << (k+x-1) << endl;
	    else{
	    	
		}
	}
	return 0; 
} 

