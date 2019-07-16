//Binary Search Tree Example

#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }

    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int main()
{
    BstNode *rootPtr = NULL;

    rootPtr = Insert(rootPtr, 1);
    rootPtr = Insert(rootPtr, 2);
    rootPtr = Insert(rootPtr, 3);
    rootPtr = Insert(rootPtr, 4);
    rootPtr = Insert(rootPtr, 5);
    rootPtr = Insert(rootPtr, 6);

    int number;
    while (number != 911)
    {
        cout << "Enter a number to be searched (enter 911 to quit):\n";
        cin >> number;
        if (number == 911)
        {
            cout << "Search Ended.\n";
            break;
        }
        else if (Search(rootPtr, number))
            cout << "Found \n";
        else
            cout << "Not found.\n";
    }
}
