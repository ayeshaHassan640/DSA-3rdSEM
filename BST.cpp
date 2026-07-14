#include<iostream>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};
BSTNode* Root=NULL;

//STACK FOR TRAVERSALS
struct Node{
	BSTNode* data;
	Node* next;
};
Node* top=NULL;
Node* top2 = NULL;  // Stack 2
//PUSH
void push(BSTNode* value){
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	if(top==NULL){
		top=newNode;
		return;
	}
	newNode->next=top;
	top=newNode;

}
//POP
BSTNode* pop(){
	if(top==NULL){
		cout << "Stack Underflow" << endl;
	
	}
	Node* temp=top;
	BSTNode* value=temp->data;
	top=top->next;
	delete temp;
	return value;
}
void push2(BSTNode* value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top2;
    top2 = newNode;
}
BSTNode* pop2()
{
    if(top2 == NULL)
        return NULL;

    Node* temp = top2;
    BSTNode* value = temp->data;

    top2 = top2->next;

    delete temp;

    return value;
}

//Peek
void peek()
{
	if(top!=NULL)
	{
		cout<< "Top: "<< top->data << endl;
	}
}
//Insert Function
BSTNode* insertBST(BSTNode* curr,int value)		//Agar curr parameter na hota, toh function ko pata hi nahi hota ke tree mein kahan hain hum abhi.
{
	if(curr==NULL)
	{
		BSTNode* temp=new BSTNode;
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		return temp;		//se naye node ka address main() ko mila.
							// main() ne woh address root mein daal diya. Ab root NULL nahi, [50] ko point kar raha hai.
	}
	if(value<curr->data)
	{
		curr->left=insertBST(curr->left,value);
	}
	else
	{
		curr->right=insertBST(curr->right,value);
	}
	return curr;		//Return isliye hai taake har node apne updated child ka address receive kar sake aur save kar sake.
}
//Search Function
void search(BSTNode*curr,int value)
{
	if(curr==NULL)
	{
		cout<< "Value not Found";
		return;
	}
	if(curr->data==value)
	{
		cout << "Value Found";
		return;
	}
	if(value<curr->data)
	{
		search(curr->left,value);
	}
	else
	{
		search(curr->right,value);
	}
	
}
//Find min
BSTNode* findMin(BSTNode* curr)
{
    while(curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
//or
//Find max
BSTNode* findMax(BSTNode* curr)
{
    while(curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}
//Delete
BSTNode* del(BSTNode* curr,int value)
{
	if(curr==NULL)
	{
		return NULL;
	}
	else if(value>curr->data)
	{
		curr->right=del(curr->right,value);
	}
	else
	{
		curr->left=del(curr->left,value);
	}
	//if 0 child
	if(curr->left==NULL && curr->right==NULL)
	{
		delete curr;
	return NULL;
	}
	//if 1 child
	else if(curr->left==NULL ){
		BSTNode* temp=curr->right;
		delete curr;
		return temp;
		}
		else if (curr->right == NULL) {
                BSTNode* temp = curr->left;
                delete curr;
                return temp;
            }
		else
        {
            BSTNode* temp = findMin(curr->right);
            curr->data = temp->data;
            curr->right = del(curr->right, temp->data);
        }
			
}
//DISPLAY
void preOrderDisplay(BSTNode* curr)
{
	if(curr!=NULL)
	{
		cout<< curr->data<< "  ";
		preOrderDisplay(curr->left);
		preOrderDisplay(curr->right);
	}
}
//Display
void inOrderDisplay(BSTNode* curr)
{
	if(curr!=NULL)
	{
		inOrderDisplay(curr->left);
		cout<< curr->data << "  ";
		inOrderDisplay(curr->right);
	}
}
//DISPLAY
void PostOrderDisplay(BSTNode* curr)
{
	if(curr!=NULL){
	PostOrderDisplay(curr->left);
	PostOrderDisplay(curr->right);
	cout<< curr->data << "  ";
}
}

int inOrderTraversal(BSTNode* root){
	BSTNode* curr=root;
	while(curr!=NULL || top!=NULL)
{
    while(curr!=NULL)
    {
        push(curr);
        curr=curr->left;
    }

    curr=pop();

    cout<<curr->data<<" ";

    curr=curr->right;
}
}
void preOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;

    push(root);

    while(!empty())
    {
        BSTNode* curr = pop();

        cout << curr->data << " ";

        if(curr->right != NULL)
            push(curr->right);

        if(curr->left != NULL)
            push(curr->left);
    }
}


void postOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;

    push(root);

    while(!empty())
    {
        BSTNode* curr = pop();

        push2(curr);

        if(curr->left != NULL)
            push(curr->left);

        if(curr->right != NULL)
            push(curr->right);
    }

    while(!empty2())
    {
        BSTNode* curr = pop2();

        cout << curr->data << " ";
    }
}

void decreasingOrder(BSTNode* curr)
{
    if(curr != NULL)
    {
        decreasingOrder(curr->right);
        cout << curr->data << " ";
        decreasingOrder(curr->left);
    }
}

void decreasingOrder(BSTNode* root)
{
    BSTNode* curr = root;

    while(curr != NULL || !empty())
    {
        while(curr != NULL)
        {
            push(curr);
            curr = curr->right;
        }

        curr = pop();

        cout << curr->data << " ";

        curr = curr->left;
    }
}
int main()
{
	while(true){
		//if you want to 
	cout<< "\n1: insert.";
	cout<< "\n2:search.";
	cout<< "\n3:delete.";
	cout<< "\n4:Post order traversal.";
	cout<< "\n5: Pre order traversal.";
	cout<< "\n6: in order traversal.";
	cout<< "\n7:exit.";
	int selectNum;
	cout<< "\n:Enter number.";
	cin>> selectNum;
	
	if(selectNum==1)
	{
		int value;
		cout<< "Enter value.";
		cin>> value;
		Root=insertBST(Root,value);
	}
	else if(selectNum==2)
	{
		int value;
		cout<< "Enter value.";
		cin>> value;
		search(Root,value);
	}
	else if(selectNum==3){
		int value;
		cout<< "Enter value to delete:";
		cin>> value;
		del(Root,value);
	}
	else if(selectNum==4)
	{
		PostOrderDisplay(Root);
	}
	else if(selectNum==5)
	{
		preOrderDisplay(Root);
	}
	else if(selectNum==6)
	{
		inOrderTraversal(Root);
	}
	else if(selectNum==7)
	{
		break;
	}
	else
	{
		cout << "Invalid Choice";
	}
}
	
//	Root=insertBST(Root,89);		//Pehli insert pe Root NULL hota hai. Function NULL receive karta hai, naya node banata hai, aur uska address return karta hai. Agar hum Root = na likhein, toh woh address kho jaata — Root hamesha NULL rehta aur tree kabhi nahi banta.
//	Root=insertBST(Root,86);
//	Root=insertBST(Root,90);
//	//preOrderDisplay(Root);
//	PostOrderDisplay(Root);
//	search(Root,864);
	return 0;
}

