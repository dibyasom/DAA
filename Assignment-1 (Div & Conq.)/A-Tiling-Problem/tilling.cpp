// C++ program to place tiles 
#include <bits/stdc++.h> 
using namespace std; 

typedef int ll;
typedef int llu;

void find_marked_tile(ll** arr, ll x, ll y, ll n, ll* r, ll* c);
void add_tile(ll** arr, ll x, ll y, ll r, ll c, ll n);
void fit(ll** arr, int x1, int y1, int x2, int y2, int x3, int y3);

ll** newArr2D(llu r, llu c){
	ll** mat = (ll**)malloc(r * sizeof(ll*));
	for(llu i=0; i<r; i++)
		mat[i] = (ll*)malloc(c * sizeof(ll));
	return mat;
}

void fillVal2D(ll** mat, llu r, llu c, ll val){
	for(llu i=0; i<r; i++)
		for(llu j=0; j<c; j++)
			mat[i][j] = val;
}

void printArr2D(ll** mat, llu r, llu c){
	printf("\n");
	for(llu i=0; i<r; i++){
		for(llu j=0; j<c; j++)
			printf("%d ", *(*(mat+i)+j));
		printf("\n");
	}
}

int cnt;

void fit(ll** arr, int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
	cnt = rand()%91 + 10;
	arr[x1][y1] = cnt; 
	arr[x2][y2] = cnt; 
	arr[x3][y3] = cnt; 
} 

int engage_tiling(ll** arr, int n, int x, int y) 
{  
	if (n == 2) { 
		cnt++; 
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) { 
				if (arr[x + i][y + j] == 0) { 
					arr[x + i][y + j] = cnt; 
				} 
			} 
		} 
		return 0; 
	} 

	int r, c;
	find_marked_tile(arr, x, y, n, &r, &c);

	add_tile(arr, x, y, r, c, n);

	// diving it again in 4 quadrants 
	engage_tiling(arr, n / 2, x, y + n / 2); 
	engage_tiling(arr, n / 2, x, y); 
	engage_tiling(arr, n / 2, x + n / 2, y); 
	engage_tiling(arr, n / 2, x + n / 2, y + n / 2); 

	return 0; 
} 

void find_marked_tile(ll** arr, ll x, ll y, ll n, ll* r, ll* c){
	for (int i = x; i < n; i++)
		for (int j = y; j < n; j++)
			if (arr[i][j] == -1){ 
				*r = i;
				*c = j;
				break; 
			}
}

void add_tile(ll** arr, ll x, ll y, ll r, ll c, ll n){

	if (r < x + n / 2 && c < y + n / 2) 
		fit(arr, x + n / 2, y + (n / 2) - 1, x + n / 2, 
			y + n / 2, x + n / 2 - 1, y + n / 2); 

	else if (r >= x + n / 2 && c < y + n / 2) 
		fit(arr, x + n / 2, y + (n / 2) - 1, x + n / 2, 
			y + n / 2, x + n / 2 - 1, y + n / 2 - 1); 

	else if (r < x + n / 2 && c >= y + n / 2) 
		fit(arr, x + (n / 2) - 1, y + (n / 2), x + (n / 2), 
			y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1); 

	else
		fit(arr, x + (n / 2) - 1, y + (n / 2), x + (n / 2), 
			y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1); 
}

int main() 
{ 
	ll N; printf("Checkboard size -> (2^N)*(2^N)\nN > "); scanf("%d", &N);
	ll size = pow(2, N);
	ll** arr = newArr2D(size, size);
	fillVal2D(arr, size, size, 0);

	ll x,y;
	printf("Co-ordinate to be destroyed (drop <x> <y>) > "); scanf("%d%d", &x, &y);
	arr[x][y] = -1;

	engage_tiling(arr, size, 0, 0); 
	printArr2D(arr, size, size);
	
} 
