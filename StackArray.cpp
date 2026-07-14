#include<iostream>
using namespace std;
#define SIZE 5 	//preprocessor directive ( before program runs,Compiler SIZE ko 5 se replace kar deta hai)
int stack[SIZE];
int top=-1;		//top=last element ka index
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
void peek()
{
	if(top!=-1)
	{
		cout <<"Top: " << stack[top]<< endl;
	}
}
void display(){
	for(int i=top;i>=0;i--){
		cout <<stack[i];
	}
}
//DisplayUsingRecursion
void DisForRecur(int top)
{
	if(top<0)
	return;
	cout<< stack[top];
	DisForRecur(top-1);
}
//DisplayUsingRecursion
void DisBackRecur(int top)
{
	if(top<0)
	return;
	DisForRecur(top-1);
	cout<< stack[top];
}
int main() {
    push(10);
    push(20);
    push(30);
    pop();
    //display();
    peek();
    DisForRecur(top);
    DisBackRecur(top);

    return 0;
}











