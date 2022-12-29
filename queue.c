#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Node *temp = front;
    if (front == NULL)
        return;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void Print()
{
    printf("List is: ");
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(2);
    Print();
    Enqueue(4);
    Print();
    Enqueue(6);
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
}