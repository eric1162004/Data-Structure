//Evaluation Of postfix Expression Example

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int EvaluatePostFix(string EXP);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsDigit(char C);

int main()
{
    string EXP;
    cout << "Enter Postfix Expression: \n";
    getline(cin, EXP);
    int result = EvaluatePostFix(EXP);
    cout << "Result = " << result << "\n";
}

int EvaluatePostFix(string EXP)
{
    stack<int> S;

    for (int i = 0; i < EXP.length(); i++)

        if (IsOperator(EXP[i]))
        {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            int result = PerformOperation(EXP[i], operand1, operand2);
            S.push(result);
        }
        else if (IsDigit(EXP[i]))
        {
            int operand = 0;
            while (i < EXP.length() && IsDigit(EXP[i]))
            {
                operand = (operand * 10) + (EXP[i] - '0');
                i++;
            }
            i--;
            S.push(operand);
        }
        else if (EXP[i] == ' ' || EXP[i] == ',')
            continue;
        else
        {
            cout << "Invalid Expression";
            return -1;
        }

    return S.top();
}

int PerformOperation(char operation, int operand1, int operand2)
{
    if (operation == '+')
        return operand1 + operand2;
    if (operation == '-')
        return operand1 - operand2;
    if (operation == '*')
        return operand1 * operand2;
    if (operation == '/')
        return operand1 / operand2;

    else
        cout << "Error \n";
    return -1;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}

bool IsDigit(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    return false;
}
