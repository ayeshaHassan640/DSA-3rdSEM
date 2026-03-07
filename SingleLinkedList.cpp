#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
//Global declaration, shows that list is empty
Node* head=NULL;
	//INSERT FUNCTION AT LAST
void insert(int value){
	Node* newNode=new Node();  		// Memory allocate
	newNode->data=value;			// Data store
	newNode->next=NULL;				// Next NULL, kyunki ye last node banega
	//INSERT AT START
	if(head==NULL){
		head=newNode;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;			// Last node ka next newNode pe point kare
}
//INSERT AT MIDDLE
void insertAtMiddle(int pos, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
// Start pe insert karna ho
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    // Loop temp ko position-1 tak le jaata hai
    for(int i = 1; i < pos-1; i++){
        if(temp->next == NULL) //agar position list s bari hogi te temp last tk ajyga
		break; // agar end tak aa gaye
        temp = temp->next;
    }
	// Ab temp previous node pe hai
    newNode->next = temp->next;
    temp->next = newNode;
}
//SEARCH FUNCTION
void search(int value)
{
	if(head==NULL)
	{
		cout<< "List is empty";
	}
	Node*temp=head;
	int position=1;
	bool found=false;
	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			found=true;
			cout << "Value found at position " << position << endl;
			break;
		}
			temp=temp->next;
			position++;
		}
		if(!found){
			cout << "Value not found";
		}
}
//DELETE FUNCION
void del(int value)
{
	if(head==NULL)
	{
		cout << "List is empty";
		return;
	}
	//CASE 1: HEAD NODE DELETE
	Node* temp=head;
	if(temp->data==value){
		head=head->next;
		delete(temp);
		return;
	}
	//CASE 2: HEAD KE BAAD DELETE
	Node* prev=head;
	Node* current=head->next;
	while(current!=NULL)
	{
		if(value==current->data)
		{
		prev->next=current->next;
		delete(current);
		break;
	}
	prev=current;
	current=current->next;
}
}
//DISPLAY FUNCTION
void display(){
	Node* temp = head;  
	if(head==NULL){
		cout<< "List is empty";
	}
	while(temp!=NULL){
		cout<< temp-> data << " ";
		temp=temp->next;
	}
}
//REVERSE DISPLAY
void backwardDisplay()
{
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<< temp->data;
}
////Display using recursion
//void displayList(Node*temp){
//	if(temp==NULL){
//		return ;
//	}
//	cout<< temp->data << " ";
//	displayList(temp->next);
//}
////Reversre using recusrion
//void displayReverse(Node* temp){
//	if(temp==NULL){
//		return;
//	}
//	displayReverse(temp->next);
//	cout << temp->data << " ";
//}
int main(){
	insert(55);
	insert(50);
//	insertAtMiddle(2,15);
//	search(58);
	//del(55);		
	//display();
	backwardDisplay();
//	//displayList(head);
//	displayReverse(head);
	return 0;
}

