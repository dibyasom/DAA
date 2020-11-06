#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

/* A Binary Tree node */
struct TNode 
{ 
    int data; 
    struct TNode* left; 
    struct TNode* right; 
}; 
  
struct TNode* newNode(int data); 
  
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int* arr, int start, int end) 
{ 
    /* Base Case */
    if (start > end) 
      return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    struct TNode *root = newNode(arr[mid]); 
  
    /* Recursively construct the left subtree and make it 
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1); 
  
    /* Recursively construct the right subtree and make it 
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end); 
  
    return root; 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct TNode* newNode(int data) 
{ 
    struct TNode* node = (struct TNode*) 
                         malloc(sizeof(struct TNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 

void merge(int* arr, int l, int m,int r){
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
  
    int L[n1], R[n2];  
  
//    Generating left and right sub-arrays
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
  
    i = 0;  
    j = 0;   
    k = l; // Initial index of merged subarray  
    
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) { 
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* Copy the remaining elements of L[], if there  
    are any */
    while (i < n1) {   
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* Copy the remaining elements of R[], if there  
    are any */
    while (j < n2) {   
        arr[k] = R[j];  
        j++;  
        k++;  
    }  	
}

void mergesort(int* arr, int l, int r){
    if(l>=r)
	   return;
    int mid = (l+r)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    
    merge(arr, l, mid, r); 		 	
}

void inorder(struct TNode* node){
	 if(node==NULL)
	     return; 
     inorder(node->left);
     printf("%d, ", node->data);
     inorder(node->right);
}

/* Driver program to test above functions */
int main() 
{ 
    //Accept the input array.
    int size; cout << "This code converts provided array into BST.\nNumber of elements > "; cin >> size;
    int* arr= (int*)malloc(size*sizeof(int));
    cout << "\nDrop all array elements as space-SV > ";
    
    for(int i= 0; i< size; i++)
  		cin >> arr[i];
  
    //Sorting the array in non-decreasing order.
    mergesort(arr, 0, size-1);
    
    /* Convert List to BST */
    struct TNode *root = sortedArrayToBST(arr, 0, size-1); 
  	
  	//Print the inorder traversal, a non-decreasing order will verify that BST creation was succesful.
  	printf("\nInorder traversal of generated tree.(Non-decreasing order of integers would verify successful BST creation.)\n");
  	inorder(root);
  	printf("Done:3\n\n");
  	
    return 0; 
} 
