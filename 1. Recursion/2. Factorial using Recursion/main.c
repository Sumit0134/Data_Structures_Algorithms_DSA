#include<stdio.h>

int recursiveFactorial(int);

int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d", &n);
    printf("The factorial of %d is: %d", n, recursiveFactorial(n));
}

int recursiveFactorial(int n)
{
    if(n==0)
    return 1;
    else
    return recursiveFactorial(n-1)*n;
}
