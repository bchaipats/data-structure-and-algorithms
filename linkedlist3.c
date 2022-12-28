#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Insert(struct Node *head, int data)
{
    // insert data at the end of the linked list.
    // a node for new data
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    // empty linked list.
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    // non-empty linked list.
    struct Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}

void Print(struct Node *head)
{
    printf("List is: ");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *Reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;

    while (curr != NULL)
    {
        struct Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head);
    Print(head);
}