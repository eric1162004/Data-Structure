//Binary tree - Breadth first(level order) Traversal

#include <iostream>
#include <queue>
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

void LevelOrder(BstNode *root)
{
    if (root == NULL)
        return;
    queue<BstNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        BstNode *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
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

    LevelOrder(rootPtr);
}