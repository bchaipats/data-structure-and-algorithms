#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *Find(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (root->data > data)
        return Find(root->left, data);
    else
        return Find(root->right, data);
}

Node *FindMin(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *GetSuccessor(Node *root, int data)
{
    Node *current = Find(root, data);
    if (current == NULL)
        return current;
    else if (current->right != NULL)
        return FindMin(current->right);
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (ancestor->data > current->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

// Function to visit nodes in Inorder
void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);       // Visit left subtree
    printf("%d ", root->data); // Print data
    Inorder(root->right);      // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main()
{
    /*Code To Test the logic
      Creating an example tree
                        5
               / \
              3   10
             / \   \
            1   4   11
    */
    Node *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    // Print Nodes in Inorder
    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << "\n";

    // Find Inorder successor of some node.
    struct Node *successor = GetSuccessor(root, 1);
    if (successor == NULL)
        cout << "No successor Found\n";
    else
        cout << "Successor is " << successor->data << "\n";
}