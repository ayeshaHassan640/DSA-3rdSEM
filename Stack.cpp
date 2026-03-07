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
	Node* temp=top;
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
//Display
void display(){
	if(top==NULL){
		cout<< "Stack Underflow";
		return;
	}
	Node* temp=top;
	while(temp!=NULL){
		cout<< temp->data<<endl;
		temp=temp->next;
	}

}
int main(){
	push(22);
	push(55);
	push(35);
	pop();
	display();
}

