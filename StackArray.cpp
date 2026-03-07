#include<iostream>
using namespace std;
#define SIZE 5 	//preprocessor directive ( before program runs,Compiler SIZE ko 5 se replace kar deta hai)
int stack[SIZE];
int top=-1;
//PUSH
void push(int value){
	if(top==SIZE-1){
		cout << "Stack overflow";
		return;
	}
	top++;
	stack[top]=value;
	 cout << value << " pushed\n";
	 }
void pop(){
	if(top==-1){
		cout << "Stack underflow";
		return;
	}
	cout << "Value Popped  " <<stack[top] << endl;
	top--;
}
void display(){
	for(int i=top;i>=0;i--){
		cout <<stack[i];
	}
}
int main() {
    push(10);
    push(20);
    push(30);
    pop();
    //display();

    return 0;
}














