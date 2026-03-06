#include<iostream>
using namespace std;
int main(){
#define SIZE 5
	int array[SIZE];
	for(int i=0;i<SIZE;i++){
		cin>>array[i];
	}
	//i=jisko sahi jaga insert krna hay start with 2nd place
	for(int i=1;i<SIZE;i++){
		int key=array[i];
		//j=left pointer which compares to the key
		int j=i-1;
		// Move elements greater than key
		while(j>=0 && array[j]>key){     
		//shift right
			array[j + 1] = array[j];
                j--;
		}
		//insert key  
		array[j+1]=key;
	}
	for(int k=0;k<SIZE;k++){
		cout << array[k]<< ",";
	}
}
