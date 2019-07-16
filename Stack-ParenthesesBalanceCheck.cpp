#include <iostream>
#include <stack> //stack from standard template library
#include <cstring>
using namespace std;

string checkParam(char Eqn[], int n)
{
    stack<char> paramStack;

    for (int i = 0; i < n; i++)
    {
        if (Eqn[i] == '(' || Eqn[i] == '[' || Eqn[i] == '{')
        {
            paramStack.push(Eqn[i]);
        }
        else if (Eqn[i] == ')')
        {
            if (paramStack.empty() || paramStack.top() != '(')
            {
                return "\nUnbalance Equation";
            }
            else
            {
                paramStack.pop();
            }
        }
        else if (Eqn[i] == ']')
        {
            if (paramStack.empty() || paramStack.top() != '[')
            {
                return "\nUnbalance Equation";
            }
            else
            {
                paramStack.pop();
            }
        }
        else if (Eqn[i] == '}')
        {
            if (paramStack.empty() || paramStack.top() != '{')
            {
                return "\nUnbalance Equation";
            }
            else
            {
                paramStack.pop();
            }
        }
    }

    return "\nBalanced Equation";
}

int main()
{
    char C[50];
    printf("Enter an equation: ");
    gets(C);
    cout << checkParam(C, strlen(C));
}
