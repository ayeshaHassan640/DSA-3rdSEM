//Merge 2 sorted linked list
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
//Global declaration, shows that list is empty
Node* head=NULL;
Node* head1=NULL;
void insert(Node*& headRef, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (headRef == NULL) {
        headRef = newNode;
        return;
    }

    Node* temp = headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* mergeList(Node* h1,Node* h2){
	Node* dummyNode=new Node();
	dummyNode->next=NULL;
	Node* current=dummyNode;
	while(h1!=NULL && h2!=NULL){
		if(h1->data<h2->data){
			current->next=h1;
			h1=h1->next;
		}
		else{
			current->next=h2;
			h2=h2->next;
		}
		current=current->next;
	}
	while(h1!=NULL){
		current->next=h1;
		h1=h1->next;
		current=current->next;
	}
	while(h2!=NULL){
		current->next=h2;
		h2=h2->next;
		current=current->next;
	}
	return dummyNode->next;
}
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
int main(){
	insert(head,5);
	insert(head,10);
	insert(head,15);
	insert(head,20);
	display(head);
	insert(head1,25);
	insert(head1,30);
	insert(head1,35);
	
	Node* dumm=mergeList(head,head1);
	display(dumm);
}
