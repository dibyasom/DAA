#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define infinity LONG_MAX

ll minbikis_DP(ll money, vector<ll>& bikis, vector<ll>& opt_set){
	if(opt_set[money]!= -1)
		return opt_set[money];
	ll min_coins= infinity, num_coins;
	for(int i=0; i<bikis.size(); i++){
		num_coins= minbikis_DP(money-bikis[i], bikis, opt_set)+1;
		min_coins= (num_coins< min_coins) ?num_coins :min_coins;
	}
	opt_set[money]= min_coins;
	return opt_set[money];
}

ll minbikis_driver(ll money, vector<ll>& bikis, vector<ll>& opt_set){
	for(ll i=1; i<=money; i++)
		minbikis_DP(i, bikis, opt_set);
	return opt_set[money];
}

int main(void){
//Fetching the inputs.
	ll money; cin >> money;
	ll size; cin >> size;
	vector<ll> denom(size), opt_set(money+1, -1);
	opt_set[0]= 0;
	for(ll i=0; i<size; i++)
		cin >> denom[i];

//Chrunching some algo.
	cout << minbikis_driver(money, denom, opt_set) << endl;

	return 0;
}