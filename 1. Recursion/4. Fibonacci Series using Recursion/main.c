#include<stdio.h>

int recursiveFibonacci(int);

int main()
{
    int n, result;
    printf("Enter the term n: ");
    scanf("%d", &n);
    result=recursiveFibonacci(n);
    printf("The value of %d term is: %d", n, result);
}

int recursiveFibonacci(int n)
{
    if(n<=1)
    return n;
    else
    return recursiveFibonacci(n-2)+recursiveFibonacci(n-1);
}
