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
        printf("As the number of rows is not equal to the number of columns, we cannot create a upper triangular matrix.");
        return 0;
    }

    int matrix[n][m], s;
    s=(n*(n+1))/2;
    int A[s], k=0;

    printf("Enter total of s matrix elements for a upper triangular matrix: ");
    for(int i=0; i<s; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("The upper triangular matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i<=j)
            {
                matrix[i][j]=A[k++];
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

}
