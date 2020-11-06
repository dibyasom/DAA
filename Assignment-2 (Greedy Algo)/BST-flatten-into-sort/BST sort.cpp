#include <iostream> 
using namespace std; 

//Creating the blueprint for BST.
struct Node { 
    int key; 
    struct Node *left, *right; 
    Node(int key){ 
        this->key = key; 
        left = right = NULL; 
    } 
}; 

//Inorder travel is Left->Root->Right.
void printInorder(struct Node* node) 
{ 
    if (node == NULL) //Base condition: Leaf node encountered.
        return; 
  
    //Traverse into left-node.
    printInorder(node->left); 
  
  	//Print the key of current node.
    cout << node->key << " "; 
  
    //Now travel into right node.
    printInorder(node->right); 
} 

int main() 
{ 
  	cout << "Generating Binary Search Tree with Feeded values....\n";
  	
  	//Constructing a BST with n=5 keys.
    struct Node *root = new Node(8);
	
	//left-subtree. 
    root->left= new Node(3); 
    root->left->left= new Node(1); 
    root->left->right= new Node(6);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(7);
    
    //right-subtree
    root->right= new Node(10);
	root->right->right= new Node(14); 
	root->right->right->left= new Node(13);
  	
  	cout << "Tree generated!\n\nPrinting Keys in sorted order > ";
    printInorder(root); 

    return 0; 
} 
