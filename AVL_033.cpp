#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;			//every node stores own height
};

		//CALCULATE HEIGHT.....
		int getHeight(AVLNode* node) {
		    if (node == NULL)
		        return -1; 				// Empty node ki height -1 hoti hai
		    
		    return node->height; 		// Saved value return karein, recursion ki zaroorat nahi
}
				//CHECK BALANCE FACTOR
				int getBalance(AVLNode* node) {
   					 if (node == NULL) 
						return 0;
    				return getHeight(node->left) - getHeight(node->right);
}
//UPDATE KRO HEIGHT KO AFTER EVERY INSERTION
					void updateHeight(AVLNode* node) {
						if (node != NULL)
    					node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

				AVLNode* rotateRight(AVLNode* curr) {
					AVLNode* temp =curr;
					curr=curr->left;  
    				AVLNode* temp2 = curr->right;
   				    curr->right =temp;
    				temp->left=temp2;
    				updateHeight(temp);
    				updateHeight(curr);
    				return curr;
}

				AVLNode* rotateLeft(AVLNode* curr) {
   				 AVLNode* temp=curr;
    				curr=curr->right;  
    				AVLNode* temp2=curr->left;
    				curr->left=temp;
    				temp->right=temp2;
    				updateHeight(temp);
    				updateHeight(curr);
    				return curr;
}

				AVLNode* insert(AVLNode* node, int value) {
   				 // normal BST insert
   				 if (node == NULL){
    				AVLNode* temp=new AVLNode;
					temp->data=value;
					temp->left=NULL;
					temp->right=NULL;
					temp->height = 0; // Naya node hamesha 0 height par hota hai
					return temp;
        }
    
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node; // duplicate nahi chalega
    //// --- WAPSI (Backtracking) SHURU ---
    // height update
    updateHeight(node);
    
    // Step 3: balance check karo
    int balance = getBalance(node);
    
    // Left case
    if (balance == 2 && value < node->left->data)
        return rotateRight(node);
    
    // Left Right case
    if (balance == 2 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    // Right case
    if (balance == -2 && value > node->right->data)
        return rotateLeft(node);
    
    // Right Left case
    if (balance == -2 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

void inorder(AVLNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void preorder(AVLNode* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void postorder(AVLNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    AVLNode* root = NULL;
    //root = likhna aisa hi hai jaise har dafa naye banne wale "Sadar" (President) ka naam record mein update karna.
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); 
    root = insert(root, 40);
    root = insert(root, 50); 
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "prerder: ";
    preorder(root);
    cout << endl;
    cout << "postorder: ";
    postorder(root);
    cout << endl;
    
    return 0;
}
