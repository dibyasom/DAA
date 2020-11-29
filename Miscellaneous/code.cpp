#include<bits/stdc++.h>

using namespace std;

int main(void){
	
	int n, m, k, stud= 0;
	cin >> n >> m >> k;
	while(n--){
		int t, w=0, q;
		for(int i=0; i<k; i++){
			cin >> t;
			w+= t;
		}
		cin >> q;
		
		if(w>=m && q<=10)
		    stud++;
	}
	
	cout << stud << endl;
	
	return 0;
}
