//ab new operator aaye, to stack ke sab stronger (ya equal) operators ko nikaal do, 
//phir new operator ko push karo.
//#include<iostream>
//#include <string>
//using namespace std;
//#define SIZE 5 	//preprocessor directive ( before program runs,Compiler SIZE ko 5 se replace kar deta hai)
//char stack[SIZE];
//int top=-1;
////PUSH
//void push(char value){
//	if(top==SIZE-1){
//		cout << "Stack overflow";
//		return;
//	}
//	top++;
//	stack[top]=value;
//	 //cout << value << " pushed\n";
//	 }
//char pop(){
//	if(top==-1){
//		cout << "Stack underflow";
//		return -1;
//	}
//	//cout << "Value Popped  " <<stack[top] << endl;
//	return stack[top--];		//Top wali value return karo aur usko stack se hata do
//}
//int precedence(char opr)
//{
//	switch(opr)
//	{
//		case '*':
//		case '/':
//		case '%':
//			return 2;
//				case '+':
//				case '-':
//					return 1;
//			
//	}
//}
//int main() {
//	string postfix="";
//	string infix;
//    cout<< "Enter Infix Expression:";
//    cin >> infix;
//    for(int i=0;i<infix.length();i++)
//    {
//    	if(infix[i]>='A'&& (infix[i]<='Z')){
//    		postfix+=infix[i];
//		}
//    	else if(infix[i]>='a'&& (infix[i]<='z')){
//    		postfix+=infix[i];
//		}
//    	else if(infix[i]>='0'&& (infix[i]<='9')){
//    		postfix+=infix[i];
//		}
//		else{
//			if(top==-1)
//			{
//				push(infix[i]);
//			}
//			else{
//				while(top!=-1&& precedence(stack[top])>=precedence(infix[i]))
//				{
//					postfix +=pop();
//				}
//				push(infix[i]);
//			}
//	}
//}
//while(top != -1){
//    postfix += pop();
//	}
//cout<< postfix;	
//}
//For Double Operators
#include<iostream>
#include<string>
using namespace std;
#define SIZE 20

// ========== OPERATOR STACK ==========
string opStack[SIZE];
int top = -1;

void push(string value){
    if(top == SIZE-1){ cout << "Stack overflow"; return; }
    opStack[++top] = value;
}

string pop(){
    if(top == -1){ cout << "Stack underflow"; return ""; }
    return opStack[top--];
}

// ========== PRECEDENCE ==========
int precedence(string opr)
{
    if(opr == "!")                             return 7;
    if(opr == "*" || opr == "/" || opr == "%") return 6;
    if(opr == "+" || opr == "-")               return 5;
    if(opr == "<" || opr == ">" ||
       opr == "<=" || opr == ">=")             return 4;
    if(opr == "==" || opr == "!=")             return 3;
    if(opr == "&&")                            return 2;
    if(opr == "||")                            return 1;
    if(opr == "(")                             return 0; // sabse kam
    return -1;
}

bool isOperator(string token){
    return precedence(token) != -1;
}

// ========== TOKENS ARRAY ==========
string tokens[SIZE*2];
int tokenCount = 0;

// ========== TOKENIZE ==========
void tokenize(string infix)
{
    int i = 0;
    while(i < infix.length())
    {
        // Space skip karo
        if(infix[i] == ' ')
        {
            i++;
            continue;
        }

        // Operand (letter ya digit)
        if((infix[i]>='A' && infix[i]<='Z') ||
           (infix[i]>='a' && infix[i]<='z') ||
           (infix[i]>='0' && infix[i]<='9'))
        {
            string operand = "";
            while(i < infix.length() &&
                 ((infix[i]>='A' && infix[i]<='Z') ||
                  (infix[i]>='a' && infix[i]<='z') ||
                  (infix[i]>='0' && infix[i]<='9')))
            {
                operand += infix[i];
                i++;
            }
            tokens[tokenCount] = operand;
            tokenCount++;
            
        }

        // 2 char operators
        else if(i+1 < infix.length() &&
               ((infix[i]=='<' && infix[i+1]=='=') ||
                (infix[i]=='>' && infix[i+1]=='=') ||
                (infix[i]=='=' && infix[i+1]=='=') ||
                (infix[i]=='!' && infix[i+1]=='=') ||
                (infix[i]=='&' && infix[i+1]=='&') ||
                (infix[i]=='|' && infix[i+1]=='|')))
        {
            string twoChar = "";
            twoChar += infix[i];      // pehla char
            twoChar += infix[i+1];    // dusra char
            tokens[tokenCount] = twoChar;
            tokenCount++;
            i += 2;
        }

        // 1 char operator
        else
        {
            string oneChar = "";
            oneChar += infix[i];
            tokens[tokenCount++] = oneChar;
            i++;
        }
    }
}

// ========== MAIN ==========
int main()
{
    string infix;
    string postfix = "";

    cout << "Enter Infix Expression: ";
    getline(cin, infix); //poori line input lega with spaces

    // Tokenize
    tokenize(infix);

    // Infix to Postfix
    for(int i = 0; i < tokenCount; i++)
    {
        string token = tokens[i];

        if(!isOperator(token)&& token != "(" && token != ")")          // Operand
        {
            postfix += token + " ";
        }
        else if(token == "(")          // Opening bracket
    {
        push(token);               // seedha push karo
    }
    else if(token == ")")          // Closing bracket
    {
        // jab tak ( na mile, nikalte jao
        while(top != -1 && opStack[top] != "(")
        {
            postfix += pop() + " ";
        }
        pop();                     // ( ko nikaalo — postfix mein mat daalo
    }
        else                            // Operator
        {
            if(top == -1)
            {
                push(token);
            }
            else
            {
                while(top != -1 && precedence(opStack[top]) >= precedence(token))
                {
                    postfix += pop() + " ";
                }
                push(token);
            }
        }
    }

    // Baaki operators nikaalo
    while(top != -1){
        postfix += pop() + " ";
    }

    cout << "Postfix: " << postfix;

    return 0;
}










