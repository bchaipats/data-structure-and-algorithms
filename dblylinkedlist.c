#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head; // global variable, can be accessed anywhere.

struct Node *GetNewNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int data)
{
    struct Node *newNode = GetNewNode(data);

    // empty linked list
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void Print()
{
    printf("List is: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node *temp = head;
    if (temp == NULL)
        return; // empty list, exit

    // go to the last node.
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // traverse back to the first node and print along the way.
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtHead(4);
    Print();
    ReversePrint();
    InsertAtHead(6);
    Print();
    ReversePrint();
}