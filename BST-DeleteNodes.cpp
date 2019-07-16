//Deleting a node from a Binary Search Tree.

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

BstNode *FindMin(BstNode *root)
{
    if (root == NULL)
        return root;

    BstNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

BstNode *Delete(BstNode *root, int data)
{
    if (root == NULL)
    {
        cout << "No deletion. The tree is empty.\n";
        return NULL;
    }
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        //Case 1: No Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One Child
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        else //Case 3: 2 Children
        {
            BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void InOrder(BstNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
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

    rootPtr = Delete(rootPtr, 8);
    rootPtr = Delete(rootPtr, 2);
    rootPtr = Delete(rootPtr, 1);
    rootPtr = Delete(rootPtr, 3);
    rootPtr = Delete(rootPtr, 10);
    rootPtr = Delete(rootPtr, 9);
    rootPtr = Delete(rootPtr, 11);

    //deleting an empty tree.
    rootPtr = Delete(rootPtr, 11);

    InOrder(rootPtr);
}