#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* top=NULL;
//PUSH
void push(int value){
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
void pop(){
	if(top==NULL){
		cout << "Stack Underflow" << endl;
		return;
	}
	Node* temp=top;
	top=top->next;
	delete temp;
}
//Peek
void peek()
{
	if(top!=NULL)
	{
		cout<< "Top: "<< top->data << endl;
	}
}
//Display
void displayFor(){
	if(top==NULL){
		cout<< "Stack Underflow"<< endl;
		return;
	}
	Node* temp=top;
	while(temp!=NULL){
		cout<< temp->data<<endl;
		temp=temp->next;
	}
}

//DisplayUsing Recursion
void displayForRecur(Node* top){
	if(top==NULL){
		return;
	}
	cout<<top->data<< "  ";
	displayForRecur(top->next);
}
void displayBackRecur(Node* top){
	if(top==NULL){
		return;
	}
	displayBackRecur(top->next);
	cout<<top->data<< "  ";
}
int main(){
	push(22);
	push(55);
	push(35);
	pop();
//	peek();
	displayForRecur(top);
	displayBackRecur(top);
}

