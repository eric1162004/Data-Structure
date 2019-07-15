#include <iostream>
#include <stack> //stack from standard template library
#include <cstring>
using namespace std;

void Reverse(char C[], int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }

    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    printf("Enter a string: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Reverse output: %s", C);
}