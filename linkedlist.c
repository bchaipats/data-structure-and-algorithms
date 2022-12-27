#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void Insert(struct Node **head, int x)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
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

int main()
{
    struct Node *head = NULL;
    int n, i, x;

    printf("How many numbers?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number\n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
}
