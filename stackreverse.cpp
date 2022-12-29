#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void Print()
{
    Node *temp = head;

    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReverseLinkedList()
{
    if (head == NULL)
        return;
    stack<Node *> S;
    Node *temp = head;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = S.top();
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Print();
    ReverseLinkedList();
    Print();
}