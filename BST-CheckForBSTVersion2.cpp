//Check if a given binary tree is a BST by comparing the parent node

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

bool IsBSTUtil(BstNode *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data > minVal &&
        root->data < maxVal &&
        IsBSTUtil(root->left, minVal, root->data) &&
        IsBSTUtil(root->right, root->data, maxVal))
        return true;
    return false;
}

//pass the root node to IsBSTUtil()
bool IsBST(BstNode *root)
{
    //maximum or minimum limit value
    return (IsBSTUtil(root, INT_MIN, INT_MAX));
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
        cout << "\nThis is a Binary Search Tree.\n";
    else
        cout << "\nThis is not a Binary Search Tree.\n";
}
