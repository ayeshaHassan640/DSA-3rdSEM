//#include<iostream>
//using namespace std;
//#define SIZE 10
//int Queue[SIZE];
//int front=-1;
//int rear=-1;
//void EnQueue(int value){
//	if((rear + 1) % SIZE == front ){
//		cout<< "Queue full";
//		return;
//	}
//	if(front==-1){
//		front=rear=0;
//	}
//	// Normal case - move rear circularly
//	else{
//    rear = (rear + 1) % SIZE;
//    Queue[rear] = value ;
//}
//}
//void DeQueue(){
//	//check if queue==empty
//	if(front==-1){
//		cout << "Queue is empty.";
//		return;
//	}
//	cout << "Removed: " << Queue[front] << endl;
//	// Only one element in queue
//    if(front == rear) {
//        front = rear = -1; // queue becomes empty
//        return;
//    }
//    //wrap kro
//    front = (front + 1) % SIZE;		//Array me element actually delete nahi hota, bas front aage move hota hai.
//}
//void displayFront(){
//	if(front==-1){
//		cout<<"Queue empty";
//		return;
//	}
//	//circular queue me front se rear tk elements print hongyy bs
//	int i = front;
//	while (true) {
//    cout << Queue[i] << "  ";
//    if (i == rear)
//	 break;
//    i = (i + 1) % SIZE;  // circular move
//}
//void displayBack(){
//	if(rear==-1){
//		cout<<"Queue empty";
//		return;
//	}
//	//circular queue me front se rear tk elements print hongyy bs
//	int i = rear;
//	while (true) {
//    cout << Queue[i] << "  ";
//    if (i == front)
//	 break;
//    i = (i - 1+SIZE) % SIZE;  // circular move
//}
//Display Using Recursion
void disForRecur(int front){
	if(front>rear)
	{
		return;
	}
	cout<< Queue[front];
	disForRecur(front+1);
}
void disBackRecur(int front){
	if(front>rear)
	{
		return;
	}
	disBackRecur(front+1);
	cout<< Queue[front];
}
//int main(){
//	EnQueue(10);
//	EnQueue(20);
//	EnQueue(30);
//	EnQueue(40);
//	EnQueue(50);
//	EnQueue(60);
//	EnQueue(70);
//	EnQueue(80);
//	EnQueue(90);
//	EnQueue(100);
//	DeQueue();
//	display();
//}
//using linkedList
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* front=NULL;
Node* rare=NULL;

void EnQueue(int value)
{
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	if(rare==NULL)
	{
		front=rare=newNode;
		newNode->next=front;
		return;
	}
	rare->next=newNode;
	newNode->next=front;
	rare=newNode;
}
void DeQueue()
{	
		if(front==NULL)
		{
			cout<<"Queue Undeflow.";
			return;
		}
		if(front==rare)
	{
		delete(front);
		front=rare=NULL;
		return;
		}
		Node* temp=front;
		front=front->next;
		delete(temp);
		rare->next=front;
		return;
}
void display()
{
	if(front==NULL)
	{
		cout<< "Queue UnderFlow.";
		return;
	}
		Node* temp = front;   // front ko mat chhuo

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } 
	while(temp != front);   // ek chakkar poora hone pe ruko

    cout << endl;
}
//Display Using Recursion
void disForRecur(Node* front)
{
	if(rare->next==front)
	{
		cout<< rare->data;
		return;
	}
	cout<< front->data<<"  ";
	disForRecur(front->next);	
}
void disBackRecur(Node* front)
{
	if(rare->next==front)
	{
		cout<< rare->data<<" ";
		return;
	}
	disBackRecur(front->next);
	cout<< front->data;
}
int main()
{
	EnQueue(10);
	EnQueue(20);
	DeQueue();
	display();
}

