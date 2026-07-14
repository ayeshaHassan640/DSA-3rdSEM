#include<iostream>
using namespace std;
#define SIZE 100
struct Node{
	char val;
    Node* left;
    Node* right;
};
Node* stack[SIZE];
int top = -1;

void push(Node* value) {
    if (top == SIZE - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    top++;
    stack[top] = value;
    cout << value->val << " pushed\n";
}

Node* pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return NULL;
    }
    cout << "Popped: " << stack[top]->val << endl;
    return stack[top--];
}
Node* buildTree(string postfix){
	for(int i=0;i<postfix.length();i++){
		if(postfix[i]== ' '){
			continue;
		}
		
		Node* newNode = new Node;
        newNode->val = postfix[i];         // value assign karo
        newNode->left = NULL;
        newNode->right = NULL;

		if (newNode->val == '+' || newNode->val == '-' ||
            newNode->val == '*' || newNode->val == '/') {
            newNode->right = pop();        // newNode
            newNode->left  = pop();        // newNode
        }
        

		push(newNode);
}
		return pop();
	}
//============ TRAVERSALS ============
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// ============ MAIN ============
int main() {
    string postfix = "abc*+d-";
    //  Infix = a + b * c - d

    cout << "\n--- Building Tree ---\n";
    Node* root = buildTree(postfix);

    cout << "\n--- Tree Traversals ---\n";
    cout << "Inorder  (Infix)  : "; inorder(root);   cout << endl;
    cout << "Preorder (Prefix) : "; preorder(root);  cout << endl;
    cout << "Postorder(Postfix): "; postorder(root); cout << endl;

    return 0;
}

