//Finding Min and Max element in Binary Search Tree

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

int FindMax(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty. \n";
        return -1;
    }

    BstNode *current = root;

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current->data;
}

int FindMin(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty. \n";
        return -1;
    }

    BstNode *current = root;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->data;
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

    int min = FindMin(rootPtr);
    cout << "Min:" << min << "\n";

    int max = FindMax(rootPtr);
    cout << "Max:" << max << "\n";
}