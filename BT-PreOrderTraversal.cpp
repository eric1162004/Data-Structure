//Binary tree - Depth first Pre-order Traversal

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

void PreOrder(BstNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    BstNode *rootPtr = NULL;

    rootPtr = Insert(rootPtr, 8);
    rootPtr = Insert(rootPtr, 2);
    rootPtr = Insert(rootPtr, 1);
    rootPtr = Insert(rootPtr, 3);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 9);
    rootPtr = Insert(rootPtr, 11);

    PreOrder(rootPtr);
}