#include<stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of rows n: ");
    scanf("%d", &n);
    printf("Enter the number of columns m: ");
    scanf("%d", &m);

    if(n!=m)
    {
        printf("As the the number of rows is not equal to the number of columns, we cannot create a toeplitz matrix.");
        return 0;
    }

    int matrix[n][m];

    int s=2*n-1;
    int A[s];
    printf("Enter total of %d elements for a toeplitz matrix: ", s);
    for(int i=0; i<s; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==j)
            {
                matrix[i][j]=A[i-j];
            }
            else if(i<j)
            {
                matrix[i][j]=A[j-i];
            }
            else if(i>j)
            {
                matrix[i][j]=A[n+i-j-1];
            }
        }
    }

    printf("The toeplitz matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
