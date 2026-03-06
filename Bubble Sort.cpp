#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "Enter number of elements:" << endl;
	cin >> n;
	int array[n];
	cout << "Enter " << n << " number of elements" << endl;
	for(int i=0;i<n;i++){
		cin >> array[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	cout <<" Sorted array:";
	for(int k=0;k<n;k++){
		cout << array[k] << " ";
	}
	return 0;
}
