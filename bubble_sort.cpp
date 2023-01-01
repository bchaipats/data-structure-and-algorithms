#include <iostream>
using namespace std;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3, 12};
    BubbleSort(A, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
}