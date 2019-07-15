//Converting Infix to Postfix (Has not been fully tested!!)
//legal operators: +,-,*,/,(,)

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool hasHigherPres(char operator1, char operator2);
bool IsOperator(char C);
bool IsDigit(char C);
int getPrec(char op);
string InfixToPostfix(string EXP);

int main()
{
    string EXP;
    while (EXP != "q")
    {
        cout << "Enter Infix Expression: \n";
        getline(cin, EXP);
        string result = InfixToPostfix(EXP);
        cout << result << "\n";
    }
}

string InfixToPostfix(string EXP)
{
    stack<int> S;
    string PostEXP = "";

    for (int i = 0; i < EXP.length(); i++)
    {
        if (EXP[i] == ' ')
            continue;

        else if (IsDigit(EXP[i]))
        {
            while (IsDigit(EXP[i]))
            {
                PostEXP += EXP[i];
                i++;
            }
            PostEXP += ' ';
            i--;
        }

        else if (IsOperator(EXP[i]))
        {
            while (!S.empty() &&
                   hasHigherPres(S.top(), EXP[i]) &&
                   S.top() != '(')
            {
                PostEXP += S.top();

                S.pop();
            }
            PostEXP += ' ';
            S.push(EXP[i]);
        }

        else if (EXP[i] == '(')
        {
            S.push(EXP[i]);
        }

        else if (EXP[i] == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                PostEXP += S.top();
                S.pop();
            }
            S.pop();
        }

        else
        {
            return "Invalid Infix Expression\n";
        }
    }

    while (!S.empty())
    {
        PostEXP += S.top();
        S.pop();
    }

    return "Postfix Expression: " + PostEXP + " \n";
}

bool IsDigit(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    return false;
}

bool hasHigherPres(char operator1, char operator2)
{
    int op1 = getPrec(operator1);
    int op2 = getPrec(operator2);

    if (op1 >= op2)
        return true;
    return false;
}

int getPrec(char op)
{
    int order;

    switch (op)
    {
    case ('+'):
    case ('-'):
        order = 2;
        break;
    case ('*'):
    case ('/'):
        order = 3;
        break;
    case ('('):
        order = 1;
    }
    return order;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}
