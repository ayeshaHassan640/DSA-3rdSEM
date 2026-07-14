#include <iostream>
#include <climits>
using namespace std;
struct Node{
	int data;
	Node* next;
};
#define SIZE 10			//array ke BAHAR linked list hai
// pehlaa ele,emt bhi linked list me ==Node* HashTable[SIZE];		//easily grow hgi*	pointer array
							//Direct Array ? nodes pehle se bane hain ? grow nahi ho sakti
							//Pointer Array ? nodes malloc se bante hain ? freely grow hoti hai
							
Node HashTable[SIZE];				
//Initialize hash table
void initTable() {		//HashTable[i]->data se pehle HashTable[i] = new Node karna zaroori hai —
							//warna NULL pointer pe jaoge aur crash ho jaega! 			
    for(int i = 0; i < SIZE; i++){
       HashTable[i].data= INT_MIN;  // empty slot
        HashTable[i].next = NULL;
    }
}
//HashFunction use to define (key ko konse index p rkhna hay)
int hashFunction(int key){
	 return (key % SIZE + SIZE) % SIZE; 	//Safe for negative values and index ko range me rkhna
}
void insert(int key){
	int index=hashFunction(key);
	if(HashTable[index].data==INT_MIN){
		HashTable[index].data=key;
	}
	else{
		Node* temp= new Node;
		temp->data=key;
		temp->next=NULL;
		Node* curr=HashTable[index].next;
		if(curr==NULL){
			HashTable[index].next=temp;
		}
		else{
			while(curr->next!=NULL){
				curr=curr->next;
			}
			curr->next=temp;
		}
	}
}
void search(int key){
	int index=hashFunction(key);
	if(HashTable[index].data!=INT_MIN){
	if(HashTable[index].data==key){
	cout << "Value Found at index:" << index << endl;
	return;
	}
	else{
		Node*curr=HashTable[index].next;
		while(curr!=NULL){
			if(curr->data==key){
				cout << "Value Found " << endl;
			}
			curr=curr->next;
		}
	}
}
}
void display(){
	for(int i=0;i<SIZE;i++){
		cout << i<< ":";
		if(HashTable[i].data!=INT_MIN){
			cout << HashTable[i].data << "";
			Node* curr=HashTable[i].next;
			while (curr!=NULL){
				cout <<"->" << curr->data;
				curr=curr->next;
			}
		}
		cout <<endl;
	}
}
//Display using recursion
void disForRecur(Node* temp){
	if(temp==NULL){
		return;
	}
	cout<< temp->data<<" ";
	disForRecur(temp->next);
}

void disBackRecur(Node* temp){
	if(temp==NULL){
		return;
	}
	disBackRecur(temp->next);
	cout<< temp->data<<" ";
}
int main(){
	initTable();
	insert(10);
	insert(23);
	insert(20);
	insert(55);
	insert(125);
	insert(200);
	//search(10);

    cout << "Forward Display:" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << i << ": ";
        if(HashTable[i].data != INT_MIN){
            disForRecur(&HashTable[i]);  // bucket ka head pass karo
        }
        cout << endl;
    }

    cout << "\nBackward Display:" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << i << ": ";
        if(HashTable[i].data != INT_MIN){
            disBackRecur(&HashTable[i]);  // bucket ka head pass karo
        }
        cout << endl;
    }
}
