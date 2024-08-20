#include<stdio.h>

int recursiveFibonacci(int);
int Fib[100];

int main()
{
    int n, result;
    printf("Enter the term n: ");
    scanf("%d", &n);
    for(int i=0; i<=n; i++)
    {
        Fib[i]=-1;
    }
    result=recursiveFibonacci(n);
    printf("The value of %dth term is: %d", n, result);
}

int recursiveFibonacci(int n)
{
    if(n<=1)
    {
        Fib[n]=n;
        return n;
    }
    else
    {
        if(Fib[n-2]==-1)
        {
            Fib[n-2]=recursiveFibonacci(n-2);
        }
        if(Fib[n-1]==-1)
        {
            Fib[n-1]=recursiveFibonacci(n-1);
        }
        return Fib[n-2]+Fib[n-1];
    }
}
