#include <iostream>
using namespace std;
int main(){
	int array[]={5,2,1,3,47};
	int position=-1;
	int searchFor;
	cout<< "Enter searching element:";
	cin>> searchFor;
	int size=sizeof(array)/ sizeof(array[0]);
	for(int i=0;i<size;i++){
		if(array[i]==searchFor){
			position=i;
			break;
		}
	}
		if(position>=0){
			cout<<"Found at index "<<position;
		}
		else{
			cout<<"Not Found";
		}
	}
