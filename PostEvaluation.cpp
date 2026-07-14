#include <iostream>
using namespace std;
#define SIZE 20
char stack[SIZE];
int top = -1;
void push(char ch)
{
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
        
    }
}
char pop()
{
    if (top == -1)
    {
        cout << " Stack underflow" << endl;
        return -1;
    }
    return stack[top--];
}
int precedence(char op)
{
    switch (op)
    {
    case '*':
    case '/':
    case '%':
        return 2; // higher precedence
    case '+':
    case '-':
        return 1; // lower precedence
    }
    return 0;
}
int  stackInt[SIZE];
int topInt = -1;
void pushInt(int n)
{
    if (topInt == SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        topInt++;
        stackInt[topInt] = n;
        
    }
}
int popInt()
{
    if (topInt == -1)
    {
        cout << " Stack underflow" << endl;
        return -1;
    }
    return stackInt[topInt--];
}
int postEvaluate(string postfix)
{
	for(int i=0;i<postfix.length();i++)
	{
	if (postfix[i] >= '0' && postfix[i] <= '9')
	{
			pushInt(postfix[i] - '0');   //convert char digit to int
	}
else if (postfix[i] != ' ') {
		int v1=popInt();
		int v2=popInt();
		switch(postfix[i])
		{
		case'+':
			pushInt(v2+v1);
			break;
				case'-':
				pushInt(v2-v1);
				break;
					case'*':
					pushInt(v2*v1);
					break;
						case'/':
						pushInt(v2/v1);
						break;
				}
			}
		}

return popInt();   // final result
}

int main()
{
    string postfix=" ";
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix += pop();
            }
            pop(); 				//remove '('
        }
        else
        {
            if (top == -1)
            {
                push(infix[i]);
            }
            else
            {
                while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                {
                    postfix += pop();
                }
                push(infix[i]);
            }
        }

    }
    while (top != -1)
    {
    	
        postfix += pop();
    }
    cout << "Postfix: " << postfix << endl;
    cout << "Result:  " << postEvaluate(postfix) << endl;  // evaluate bhi karo
    return 0;
}
