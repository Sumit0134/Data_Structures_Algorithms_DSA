#include<stdio.h>

void TOH(int, int, int, int);

int main()
{
    int n;
    printf("Enter the number of discs n: ");
    scanf("%d", &n);
    TOH(n, 1, 2, 3);
}

void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("(%d, %d)\n", A, C);
        TOH(n-1, B, A, C);
    }
}
