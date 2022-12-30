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
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    BstNode *newNode = GetNewNode(data);
    if (root == NULL)
        root = newNode;
    else if (newNode->data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
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

int FindMin(BstNode *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return root->data;
    else
        return FindMin(root->left);
}

int FindMax(BstNode *root)
{
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->data;
    else
        return FindMax(root->right);
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    int rootHeight = max(leftHeight, rightHeight) + 1;
    return rootHeight;
}

int main()
{
    BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 32);

    // Find height
    printf("Tree height is: %d\n", FindHeight(root));

    // Find min
    printf("Minimum is: %d\n", FindMin(root));

    // Find max
    printf("Maximum is: %d\n", FindMax(root));

    int number;
    cout << "Enter number to be searched\n";
    cin >> number;

    if (Search(root, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";
}