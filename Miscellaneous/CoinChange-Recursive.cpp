#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define infinity LONG_MAX

ll minbikis(ll money, vector<ll>& bikis){
	if(money==0)
		return 0;
	ll min_coins = infinity, num_coins;
	for(size_t i=0; i<bikis.size(); i++){
		if(money>= bikis[i]){
			num_coins= minbikis(money-bikis[i], bikis)+1;
			min_coins= (num_coins<= min_coins) ?num_coins :min_coins;
			}	
	}
	return min_coins;
}

void print_vect(vector<ll>& v){
	for(size_t i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(void){
//Fetching the inputs.
	ll money; cin >> money;
	ll size; cin >> size;
	vector<ll> denom(size);
	for(ll i=0; i<size; i++)
		cin >> denom[i];

//Chrunching some algo.
	cout << minbikis(money, denom) << endl;

	return 0;
}