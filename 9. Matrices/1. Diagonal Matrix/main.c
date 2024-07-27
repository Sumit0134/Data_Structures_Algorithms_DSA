#include<stdio.h>

int main()
{
    int n, m;

    printf("Enter the number of rows n: ");
    scanf("%d", &n);

    printf("Enter the number of columns m: ");
    scanf("%d", &m);

    int matrix[n][m], A[n];

    if(n!=m)
    {
        printf("As the number of rows is not equal to the number of columns, we cannot create a diagonal matrix.");
        return 0;
    }
    else
    {
        printf("Enter total of %d diagonal elements for a diagonal matrix: ", n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &A[i]);
        }
    }

    printf("The diagonal matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==j)
            {
                printf("%d ", A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
