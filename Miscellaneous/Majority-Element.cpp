#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void print(vector<ll>&, ll, ll);

void merge(vector<ll>& arr, ll l, ll m, ll r){
//	printf("%lld->%lld\t", l, m); 
//	print(arr, l, m); 
//	printf("%lld->%lld\t", m+1, r);
//	print(arr, m+1, r);
	ll l_size= m-l+1, r_size= r-m;
    ll arr_l[l_size], arr_r[r_size];
    
	for(ll i=l; i<=m; i++)
	    arr_l[i-l]= arr[i];
    for(ll i=m+1; i<=r; i++)
        arr_r[i-(m+1)]= arr[i];
        
    ll ptr= l, ptr_l= 0, ptr_r= 0;
    while(ptr_l< l_size && ptr_r< r_size){
    	if(arr_l[ptr_l]<= arr_r[ptr_r])
    		arr[ptr++]= arr_l[ptr_l++];
		else
			arr[ptr++]= arr_r[ptr_r++];		
	}
	
	while(ptr_l< l_size)
	    arr[ptr++]= arr_l[ptr_l++];
    while(ptr_r< r_size)
        arr[ptr++]= arr_r[ptr_r++];
}

void merge_sort(vector<ll>& arr, ll l, ll r){
    if(l>=r)
	    return;
	    
    ll m= (l+r)/2;
	merge_sort(arr, l, m);
	merge_sort(arr, m+1, r);
	merge(arr, l, m, r);	
}

bool check_majority(vector<ll>& arr){
	merge_sort(arr, 0, arr.size()-1);
	ll count= 1;
	for(ll i=1; i<arr.size(); i++){
		if(arr[i]== arr[i-1])
		    count++;
        else
            count= 1;
        
        if(count> ceil(arr.size()/2))
            return true;
    }
    return false;
}


void print(vector<ll>& arr, ll l, ll r){
	for(ll i=l; i<=r; i++)
	    cout << arr[i] << " ";
    cout << endl;
}

int main(void){
	
	//Assign input into vector.
	int alternatives; cin >> alternatives;
	vector<ll> arr(alternatives);
	for(ll i=0; i<alternatives; i++)
        cin >> arr[i];
    
	//Display result.    
    cout << (int)check_majority(arr) << endl;
    
	return 0;
}
