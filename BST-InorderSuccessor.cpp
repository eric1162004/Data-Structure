//Finding Inorder Successor in a binary search tree

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

void InOrder(BstNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
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

BstNode *Search(BstNode *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

BstNode *GetSuccessor(BstNode *root, int data)
{
    //Search the Node
    BstNode *current = Search(root, data);
    if (current == NULL)
        return NULL;
    //Case 1: Node has right subtree
    if (current->right != NULL)
    {
        return FindMin(current->right);
    }
    //Case 2: No right subtree
    else
    {
        BstNode *successor = NULL;
        BstNode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
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

    cout << "This is the In-order Binary Search Tree in: \n";
    InOrder(rootPtr);

    int BSTvalue = 8;
    printf("\nThe In-order Successor of %d is %d.", BSTvalue, GetSuccessor(rootPtr, BSTvalue)->data);
}
