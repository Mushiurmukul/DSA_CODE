// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<bits/stdc++.h>
using namespace std;
#define COUNT 10
//Definition of Node for Binary search tree
class BstNode {
public:
	int data; 
	BstNode* left;
	BstNode* right;
	BstNode(int d)
	{
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
// Function to create a new Node in heap
/*BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode(data);
	//newNode->data = data;
	//newNode->left = newNode->right = NULL;
	return newNode;
}*/
// To insert data in BST, returns address of root node 
BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
BstNode* Delete(BstNode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root =new BstNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
void print2DUtil(BstNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
void print2D(BstNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
void Display(BstNode* root)
{
	if(root==NULL)
	{
		return ;
	}
	Display(root->left);
	cout<<root->data<<endl;
	Display(root->right);
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	print2D(root);
    Delete(root, 10);
    cout<<endl;
    cout<<endl;
    cout<<endl;
	print2D(root);
	//Display(root);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}