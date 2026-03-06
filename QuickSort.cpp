#include<iostream>
using namespace std;
#define SIZE 10
int array[SIZE];
int setPivot(int L, int R){
    int p_idx= (L + R) / 2;
    //Right Side
    while(L<=R){
    while(R>=p_idx){
    	if(array[p_idx]>array[R]){
    		int temp=array[R];
    		array[R]=array[p_idx];
    		array[p_idx]=temp;
    		p_idx=R; 
    		break;
		}
		else
		{
		R--;
	}	
	}
	while(L<=p_idx){
		if(array[p_idx]<array[L]){
			int temp=array[L];
			array[L]=array[p_idx];
			array[p_idx]=temp;
			p_idx=L;
			break;
		}
		else
		{
			L++;
		}
	}
	
}
 return p_idx; // return final pivot position
}
void QuickSort(int L,int R){
		//BaseCase
	if(L<R){		
		int pivot=setPivot(L,R);
		QuickSort(L,pivot-1);
		QuickSort(pivot+1,R);	
	}
}
int main(){
	cout<< "Enter elements of an array:" << endl;
	for(int i=0;i<SIZE;i++)
	{
		cin >> array[i];
	}
	cout<< "Original Array:";
	for(int i=0;i<SIZE;i++)
	{
		cout << array[i] << "  ";
	}
	QuickSort(0,SIZE-1);
	cout<< endl<< "Sorted Array:";
	for(int i=0;i<SIZE;i++)
	{
		cout << array[i] << "  ";
	}
	return 0;
}

