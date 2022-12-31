#define INT_MIN -999999
#define INT_MAX  999999

#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->data > minValue &&
        root->data <= maxValue && // handle duplicate gracefully
        IsBstUtil(root->left, minValue, root->data) &&
        IsBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node *root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

Node *Insert(Node *root, int data)
{
    // this function builds BST.
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
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

int main()
{
    Node *root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 9);
    root = Insert(root, 6);
    root = Insert(root, 12);
    root = Insert(root, 1);
    root = Insert(root, 3);

    bool ret = IsBinarySearchTree(root);
    if (ret)
        printf("%s\n", "It's a binary search tree (as expected)");
    else
        printf("%s\n", "It's not a binary search tree");
}