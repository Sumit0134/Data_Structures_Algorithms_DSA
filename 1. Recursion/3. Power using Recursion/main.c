#include<stdio.h>

int recursivePower(int, int);

int main()
{
    int m, n;
    printf("Enter the base m and power n: ");
    scanf("%d %d", &m, &n);
    printf("The answer of %d power %d is: %d", m, n, recursivePower(m, n));
}

/* int recursivePower(int m, int n)
 {
     if(n==0)
     return 1;
     else
     return m*recursivePower(m, n-1);
} */

// faster approach is below

int recursivePower(int m, int n)
{
    if(n==0)
    return 1;

    if(n%2==0)
    return recursivePower(m*m, n/2);
    else
    return m*recursivePower(m*m, (n-1)/2);
}
