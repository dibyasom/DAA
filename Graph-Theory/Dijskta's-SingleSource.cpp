#include<bits/stdc++.h>

using namespace std;

#define infinity INT_MAX;

class node{
	public:
		int weight, src, dest, status;
		node(int w, int s, int d){
			weight= w;
			src= s;
			dest= d;
		}
};

int find_min(int *adj_nodes, int* visited, int no_of_vertices){
	int min= infinity, min_ind=-1;
	for(int i=0; i<no_of_vertices; i++)
		if(adj_nodes[i]<=min && !visited[i]){
		   	min=adj_nodes[i];
			min_ind=i;
		}
	return min;
}

void dijsktra_single_source(node** edges, int number_of_vertices, int number_of_edges, int source){
	int adj_matrix[number_of_vertices][number_of_vertices];
	
	for(int i=0; i<number_of_vertices; i++)
		for(int j=0; j<number_of_vertices; j++)
			adj_matrix[i][j]= (i===j) ?0 :infinity;
		
	for(int i=0; i<number_of_edges; i++){
		adj_matrix[edges[i].src][edges[i].dest]= edges[i].weight;
	}
	
	int visited[number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		visited=(i==source) ?1 :0;

	for(int i=0; i<number_of_vertices-1; i++){
		int ind= find_min(adj_matrix[0], visited, number_of_vertices);
		if(ind==-1)
			break;
		for(int i=0; i<no_of_vertices; i++){
			int cost= adj_matrix[0][i]+adj_matrix[0][i];
			if(adj_matrix[ind][i]<=cost)
				adj_matrix[0][i]= cost;
		}
	}
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
	
	//kruskal_MST(edges, v, e);

	return 0;
}