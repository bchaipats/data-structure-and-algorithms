#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow, cannot push.");
        return;
    }
    A[++top] = data;
}

void Pop()
{
    if (top == -1)
    {
        printf("Stack is empty, cannot pop.");
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

bool IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Print()
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(8);
    Print();
    Pop();
    Print();
    Push(9);
    Print();
}