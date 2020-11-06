#include<bits/stdc++.h>

using namespace std;

int minimize_boxes(vector<float>& w){
	
	//sorting Weights of balls in NON-DECRESING order.
	sort(w.begin(), w.end());
	
	//left & right  pointers.
	int l= 0, r= w.size()-1, box= 0;
	
	//Prompt
	cout << "\nBoxes and their content ->\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	//Picking optimal solution.
	while(l<r){
		
		//Pair lightest-ball with the heaviest one.
		while(l<r && (w[l]+w[r] <= 1.0)){
			printf("Box#%d ~ [ %.2f %.2f ]\n", box+1, w[l], w[r]);
			w[l]= -1; w[r]= -1;
			l++; r--;
			box++;
		}
		
		//If w[l] and w[r] net weight is > 1.0, then further w[i] > w[l], hence move 'r' towards left, until w[l]+w[r] is <= 1.0
		while(l<r && (w[l]+w[r] > 1.0)){
			printf("Box#%d ~ [ %.2f ]\n", box+1, w[r]);
		    box++; r--;	
		}
	}	
	
	//Adjusting for arrays whose size is an odd number.
	if((l< w.size() && r>= 0) && (w[l]!= -1 || w[r]!= -1) && l>=r)
        printf("Box#%d ~ [ %.2f ]\n", box+1, (w[l]==-1)?w[r]:w[l]);
	    box++;
 
	return box;
}

int main(void){
	
	int N; cout << "Number of balls >> "; cin >> N;
	vector<float> W(N);
	
	for(int i=0; i<N; i++)
		cin >> W[i];
	
	cout << "\nMinimum boxes req >> " << minimize_boxes(W) << endl;
}
