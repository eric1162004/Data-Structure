//Finding height of a Binary Tree
//Height is the greatest distance from root to leaf

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

int getMax(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return getMax(leftHeight, rightHeight) + 1;
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

    cout << "The height of the Binary tree is: " << FindHeight(rootPtr);
}