#include<iostream>
using namespace std;
int main(){
	#define SIZE 5
	int array[SIZE];
	for(int i=0;i<SIZE;i++){
		cin>>array[i];
	}
	for(int i=0;i<SIZE-1;i++){
		int min=i;
		for (int j=i+1;j<SIZE;j++){
			if(array[j]<array[min])
			min=j;
		}
	// swap
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}

// print array
for (int k=0;k<SIZE;k++) {
    cout << array[k]<< " ,";
}
}
