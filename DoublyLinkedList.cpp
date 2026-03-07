#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev;
};
Node* head=NULL;
//INSERT
void insert(int value){
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	newNode->prev = NULL;
	if(head==NULL){
		head=newNode;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
	return;
}
//INSERT At MIDDLE OR ANY SPECFIC POSITION
void insertAtMid(int pos,int value){
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	if(pos<1){
		cout<< "Invalid position:";
		return;
	}
	//Insert at start
	Node* temp=head;
	if(pos==1)
	{
		newNode->next=temp;
		newNode->prev=NULL;
		
	if(head!=NULL)
	{
		head->prev=newNode;
	}
	head = newNode;
        return;
    }
    
	for(int i=1;i<pos-1;i++){
		if(temp->next==NULL){
			cout<< "Invalid position";
			break;
		}
			temp=temp->next;
		}
		newNode->prev=temp;
		newNode->next=temp->next;
		
		if(temp->next != NULL){
        temp->next->prev = newNode;
    	}

    temp->next = newNode;
				
	}
//Search
void search(int value){
	if(head==NULL){
		cout<< "List is empty" << endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		if(temp->data==value){
			cout << "Value Found: " << temp->data << endl;
			return;
		}
		temp=temp->next;
	}
}
//Delete
void del(int value){
	if(head==NULL){
		cout << "List is empty"  << endl;
	}
	//CASE#1 (agar head delete krna ho)
	Node* temp=head;
	if(temp->data==value){
		head=head->next;
		if(head!=NULL){
			head->prev=NULL;
		}
		delete temp;
		return;
	}
	//CASE#2 (agar last node delete krna ho)
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;

	
	//CASE#3 (agar middle se delete krna ho)
	Node* curr=head->next;
	Node* prev=head;
	while(curr!=NULL){
		if(curr->data==value){
			prev->next=curr->next;
			curr->next->prev=prev;
			delete curr;
			return;
		}
		prev=curr;
		curr=curr->next;
	}
}
//DISPLAY
void displayForward(){
	if(head==NULL){
		cout << "List is empty" << endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<< temp->data << " ";
		temp=temp->next;
	}	
}
//DISPLAY BACKWARD
void displayBackward(){
	if(head==NULL){
		cout<< "List is empty";
		return;
	}
	Node* temp =head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		cout<< temp->data <<" ";
		temp=temp->prev;
	}
}
int main(){
	insert(50);
	insert(100);
	insert(150);
	displayForward();
	displayBackward();
	search(100);
	del(150);
	displayForward();
	displayBackward();
}
