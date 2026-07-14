#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* front=NULL;
Node* rear=NULL;
void EnQueue(int value){
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	//Empty queue -> front = rear = NULL
	//One element -> front = rear
	//More elements -> front first pe, rear last pe
	if(rear==NULL){
		rear=front=newNode;
		return;
	}
	rear->next = newNode;
	rear=newNode;
}
void DeQueue(){
	if(front==NULL){
		cout << "Queue Empty";
		return;
	}
	Node* temp=front;
	front=front->next;
	cout << temp->data <<"DeQueued" << endl;		
	delete temp;
	
	if (front == NULL) {
        rear = NULL;
    }
}
void display(){
	if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
	EnQueue(50);
	EnQueue(500);
	EnQueue(5000);
	display();
	DeQueue();
	
}
