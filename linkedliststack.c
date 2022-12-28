#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top; // global variable, can be accessed anywhere.

void Push(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

void Pop()
{
    struct Node *temp = top;
    if (top == NULL)
        return;
    top = top->link;
    free(temp);
}

void Print()
{
    printf("List is: ");
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    top = NULL;
    Push(1);
    Print();
    Push(2);
    Print();
    Push(3);
    Print();
    Pop();
    Print();
    Push(4);
    Print();
}