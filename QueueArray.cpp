//#include<iostream>
//using namespace std;
//#define SIZE 5
//int Queue[SIZE];
//int front=-1;			//index of fisrt element  ,abhii empty hy bilkul
//int rare=-1;			//index of last elements
//
//void EnQueue(int value){
//	if(rare==SIZE-1){
//		cout<< "Queue OverFlow";
//		return;
//	}
//	if(front==-1)
//	{
//		front=rare=0;
//	}
//	else{
//	rare++;
//}
//	Queue[rare]=value;
//	 cout << value << " enqueued\n";
//}
//void Dequeue(){
//	if(front==-1)
//	{
//		cout<< "Queue Underflow";
//	}
//		front++;
//
//}
//Display forward
//void display(){
//	if(front==-1)
//	{
//		cout<< "Queue is empty."<< endl;
//		return;
//	}
//	for(int i=front;i<=rear;i++)
//	{
//		cout<< queue[i]<< " ";
//		
//	}
//	cout<< endl;
//}
//Display Backward
//void displayBack(){
//	if(front==-1)
//	{
//		cout<< "Queue is empty."<< endl;
//		return;
//	}
//	for(int i=rear;i>=front;i--)
//	{
//			cout<< queue[i]<< " ";
//}
//	cout<< endl;
//}
//Display using Recursion
//void disForRecur(int front)
//{
//	if(front>rear)	//jb rear ko cross kr jaye..stop
//	{
//		return;
//	}
//	cout<< queue[front];
//	disForRecur(front+1);	
//}
//void disBackRecur(int rear)
//{
//	if(rear<front)	//jb front ko cross karjaye ...stop
//	{
//		return;
//	}
//	cout<< queue[rear];
//	disBackRecur(rear-1);
//	
//}
//int main(){
//	EnQueue(10);
//	EnQueue(100);
//	EnQueue(1000);
//	Dequeue();
//	display();
//	return 0;
//}


//================
//USING LINKEDLIST
//================
#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* front=NULL;
Node* rare=NULL;
void enQueue(int value)
{
	Node* newNode=new Node;
	newNode->data=value;
	newNode->next=NULL;
	if(rare==NULL) //abhi dono NULL hyn tw kisi ko bhi check krskty hayn
	{
		rare=front=newNode;
	}
	rare->next=newNode;
	rare=newNode;
}
void Dequeue()
{
	if(front==NULL)
	{
		cout<< "Queue underflow"<< endl;
		return;
	}
	Node* temp=front;
	front=front->next;
	delete(temp);
	cout<< "Value Dequeued"<< endl;
}
void display()
{
	if(front==NULL)
	{
		cout<< "Queue underflow";
		return;
	}
	Node* temp=front;
	while(temp!=NULL)
	{
		cout<< temp->data << "  ";
		temp=temp->next;
	}
}
//Display using Recursion
void disForRecur(Node* front){
	if(front==NULL)
	return;
	cout<< front->data;
	disForRecur(front->next);
}
void disBackRecur(Node* front){
	if(front==NULL)
	return;
	disForRecur(front->next);
	cout<< front->data;
}

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	Dequeue();
	display();
}
