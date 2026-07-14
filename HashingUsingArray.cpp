#include<iostream>
#include<climits>		//for using int_min
using namespace std;
#define SIZE 5
int hashTable[SIZE];		//sab kuch array ke ANDAR
//Initialize hash table
void initTable() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = INT_MIN;  // empty slot
}
//HashFunction use to define (key ko konse index p rkhna hay)
int hashFunction(int key){
	 return (key % SIZE + SIZE) % SIZE; 	//Safe for negative values and index ko range me rkhna
}
//By Linear Probing
void insertByLinear(int key){
	int index=hashFunction(key);
	int i=0;
	while(hashTable[(index + i) % SIZE] != INT_MIN){  //check if slot is empty
		i++;										//if not empty,then go to next index
        if(i == SIZE) {								//check if tabe is full
            cout << "Hash table full!\n";
            return; 
        }
    }
    hashTable[(index + i) % SIZE] = key;		//if not empy,then insert at that index
}
//By Quadratic Probing
void insertByQuad(int key){
	int index=hashFunction(key);
	int i=0;
	while(hashTable[(index+i*i)%SIZE]!=INT_MIN){
		i++;
		if(i==SIZE){
			cout<< "HashTable is full." << endl;
			return;
		}
	}
	hashTable[(index+i*i)% SIZE]=key;
}
//SEARCH
void searchByLinear(int key){
	int index=hashFunction(key);
	int i=0;
	while(i<SIZE){
		int newIndex = (index + i) % SIZE; 
		if(hashTable[newIndex]==key){
			cout << "Key Found.";
			return;
		}
		if(hashTable[newIndex]==INT_MIN){
			cout << "Slot is Empty.";
			return;
		}
		i++;
	}
}
//SEARCH
void searchByQuad(int key){
	int index=hashFunction(key);
	int i=0;
	while(i<SIZE){
		int newIndex=(index+i*i)%SIZE;
		if(hashTable[newIndex]==key){
			cout << "Key Found";
			return;
		}
		if(hashTable[newIndex]==INT_MIN){
			cout << "Slot is empty.";
			return;
		}
		i++;
	}
}
void display(){
    cout << "Hash Table:" << endl;
    for(int i = 0; i < SIZE; i++){
        if(hashTable[i] == INT_MIN)
            cout << i << " : " << "Empty" << endl;
        else
            cout << i << " : " << hashTable[i] << endl;
    }
}

int main(){
	initTable();          // Initialize the hash table
	insertByLinear(-3);
    insertByLinear(23);   // Now insertion will work
    display();      
}
