#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head=NULL;
//INSERT FUNCTION
void insert(int value){
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=head;
	//iNSERT At START
	if(head==NULL){
		head=newNode;
		newNode->next=head;
		return;
	}
	//INSERT AT END
	Node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->next=head;
}
//INSERT AT MID
void insertAtMid(int pos,int value)
{
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=head;
	// Start pe insert karna ho
    if(pos == 1)
	{
		Node* last=head;
		while(last->next!=head){
			last=last->next;
		}
        newNode->next = head;
        head = newNode;
        last->next=head;
        return;
    }
    Node* temp=head;
	for(int i=1;i<pos-1;i++)
	{
		if(temp->next==head)
			break;
			temp=temp->next;	
	}
		newNode->next=temp->next;
		temp->next=newNode;
}

//SEARCH FUNCTION
void search(int value)
{
	//if list is empty
	if(head==NULL)
	{
		cout<< "List is empty";
		return;
	}
	Node* temp = head;
	do
	{
    if(temp->data == value)
	{
        cout << "Value Found: " << temp->data << endl;
        return;
    }
    temp = temp->next;
}
	while(temp != head);

}
//DELETE FUNCTION
void del(int value)
{
	if(head==NULL)
	{
		cout<< "List is empty"<< endl;
		return;
	}
	if(head->data == value)
	{
	//head delete
	//single noad ho agar
		if(head->next==head)
		{
		delete head;
		head=NULL;
		return;
	}
	//agar multiple nodes hon 
	Node* last=head;		//Last pointer----sirf last node dhundta hai
	while(last->next!=head)
	{
		last=last->next; 
	}
	Node* temp=head;		//Temp pointer-----sirf delete karne ke liye head save karta hai
	head=head->next;    
	last->next=head;
	delete temp;
	return;
}
	//agar kahin se bhi delete krna ho
	Node* prev=head;
	Node* curr=head->next;
	                                                                                                                              
	while(curr!= head){
		if(curr->data==value){
			prev->next=curr->next;      
			delete curr;
			break; 
		}
		prev=curr;
		curr=curr->next;
	}
}

//DISPLAY FUNCTION
void display(){
	if(head==NULL){
		cout <<"List is empty";
		return;
	}
	Node* temp=head;
	do{
		cout<< temp->data << " " << endl;
		temp=temp->next;
	}
	while(temp!=head);
}
int main(){
	insert(10);
	insert(20);
	insert(30);
	insertAtMid(4,100);
	//display();
	//search(30);
	del(20);
	display();
	return 0;
}
