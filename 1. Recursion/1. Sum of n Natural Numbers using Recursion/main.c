#include<stdio.h>

int recursiveSum(int);

int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d", &n);
    printf("The sum of %d natural numbers is: %d", n, recursiveSum(n));
}

int recursiveSum(int n)
{
    if(n==0)
    return 0;
    else
    return recursiveSum(n-1)+n;
}
