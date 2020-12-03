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



bool cycle_exists(int* relation,int u, int v){
	//[Data]::0th->Parent 1st->Rank
	int *u_data= find(relation, u), *v_data= find(relation, v);
	if(u_data[0]==v_data[0])
		return 1;
	else{
		if(u_data[1]<v_data[1]){
			relation[u_data[0]]+= relation[v_data[0]];
			relation[v]= u_data[0];
		}
		else{
			relation[v_data[0]]+= relation[u_data[0]];
			relation[u]= v_data[0];
		}
		return 0;
	}
}

void kruskal_MST(node** edges, int no_of_vertices, int no_of_edges){
	quicksort_weights(edges, 0, no_of_edges-1);
	int rel[no_of_vertices];for(int i=0; i<no_of_vertices; i++) rel[i]= -1;
	
	cout << "Edges in the Spanning-Tree, rendered via Kruskal Algo>\n\n";
	int edge=0, u, v, min_cost=0, mst_edge=0;
	while(mst_edge< no_of_vertices && edge<no_of_edges){
		u= edges[edge]->src;
		v= edges[edge]->dest;
		if(!cycle_exists(rel, u, v)){
			min_cost+= edges[edge]->weight;
			cout << u << " -> " << v << endl;
			mst_edge++;
		}
		edge++;
	}

	if(mst_edge==no_of_vertices-1)
		cout << "\n\nYes this graph can be induced into MST with aforementioned edges.\nWeight(MST)> " << min_cost << endl;
	else
		cout << "\n\nNope! this graph can't be induced into MST :/" << endl;
}

int main(void){
//Fetching the graph.
	int e,v; cout << "\nNumber of vertices & edges> "; 
	cin >> v >> e;

	node *edges[e];
	cout << "Drop weight, source, and destination of " << e << " edges.\n";
	int w,s,d;
	for(int i=0; i<e; i++){
		cin >> w >> s >> d;
		edges[i]= new node(w, s, d);
	}
	
	kruskal_MST(edges, v, e);

	return 0;
}