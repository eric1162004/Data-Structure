//Check if a given binary tree is a BST by comparing the root node
//This is a high cost operation.

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

bool IsSubtreeLesser(BstNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value &&
        IsSubtreeLesser(root->left, value) &&
        IsSubtreeLesser(root->right, value))
        return true;
    return false;
}

bool IsSubtreeGreater(BstNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data > value &&
        IsSubtreeGreater(root->left, value) &&
        IsSubtreeGreater(root->right, value))
        return true;
    return false;
}

bool IsBST(BstNode *root)
{
    if (root == NULL)
        return true;
    if (IsSubtreeLesser(root->left, root->data) &&
        IsSubtreeGreater(root->right, root->data) &&
        IsBST(root->left) &&
        IsBST(root->right))
        return true;
    return false;
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

    if (IsBST(rootPtr))
        cout << "This is a Binary Search Tree.";
    else
        cout << "This is not a Binary Search Tree.";
}