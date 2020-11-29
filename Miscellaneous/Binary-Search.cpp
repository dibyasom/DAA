#include<bits/stdc++.h>

using namespace std;

void print(vector<long>&);

long search(vector<long>& a, long l, long r, long key){
	if(l>r)
  	    return -1;
    long m= (l+r)/2;
    if(a[m]== key)
        return m;
    if(a[m]>  key)
        return search(a, l, m-1, key);
    return search(a, m+1, r, key);
}

void print(vector<long>& arr){
	for(long i= 0; i<arr.size(); i++)
 	    cout << arr[i] << " ";
}

int main(void){
	
	vector<long> a, b; long n,k, _n, _k;
	cin >> n; _n= n;
	while(_n--){
		long temp; cin >> temp;
		a.push_back(temp);
	}
	cin >> k; _k= k;
	while(_k--){
		long temp; cin >> temp;
		b.push_back(temp);
	}
		
	while(++_k< k)
	    cout << search(a, (long)0, n-1, b[_k]) << " ";
        
	return 0;
}
