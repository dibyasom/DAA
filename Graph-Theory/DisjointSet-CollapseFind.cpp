#include<bits/stdc++.h>

using namespace std;

class node{
	public:
		int weight, src, dest, status;
		node(int w, int s, int d){
			weight= w;
			src= s;
			dest= d;
		}
};

void swap(node**, int, int);
int fix_pivot(node** , int , int );
void quicksort_weights(node**, int, int);
int* find(int* rel, int src);

void swap(node** v, int x, int y){
	node* temp= v[x];
	v[x]=v[y];
	v[y]=temp;
}

int fix_pivot(node** v, int l, int r){
	int pivot= v[l]->weight;
	int curr=l+1, smol= l;
	while(curr<= r){
		if(v[curr]->weight< pivot){
			swap(v, ++smol, curr);
		}
		curr++;
	}
	swap(v, smol, l);
	return smol;
}

void quicksort_weights(node** v, int l, int r){
	if(l>=r)
		return;
	int partition = fix_pivot(v, l, r);
	quicksort_weights(v, l, partition-1);
	quicksort_weights(v, partition+1, r);
}

int* find(int* rel, int src){
	int	*data= new int(2);
	while(rel[src]>= 0)
		src= rel[src];
	data[0]= src;
	data[1]= rel[src];
	return data;
}

bool cycle_exists(int* relation, int v, int src, int dest){
	return 1;
}

int main(void){
//Fetching the graph.
	int e,v; cout << "Number of vertices & edges> "; 
	cin >> v >> e;

	node *vertex[e];
	cout << "Drop Wt Src Dest of every edge>>\n";
	int w,s,d;
	for(int i=0; i<e; i++){
		cin >> w >> s >> d;
		vertex[i]= new node(w, s, d);
	}
	quicksort_weights(vertex, 0, e-1);
	
	int rel[v];
	for(int i=0; i<v; i++)
		rel[i]= -1;

	//0th->Parent 1st->Rank
	int *relation= find(rel, 3);
	cout << relation[0] << " " << relation[1] << endl;

	return 0;
}


