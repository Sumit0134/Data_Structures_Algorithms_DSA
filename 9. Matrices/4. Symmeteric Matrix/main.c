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
        printf("As the number of rows is not equal to the number of columns, we cannot create a symmetric matrix.");
        return 0;
    }

    int matrix[n][m];

    int option;
    printf("Enter the choice:\n");
    printf("1. Representation using lower triangular elements\n");
    printf("2. Representation using upper triangular elements.\n");
    scanf("%d", &option);

    if(option!=1 && option!=2)
    {
        printf("Wrong choice.");
        return 0;
    }

    int s, k=0;
    s=(n*(n+1))/2;
    int A[s];
    printf("Enter total of %d elements for symmetric matrix: ", s);
    for(int i=0; i<s; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i>=j)
            {
                matrix[i][j]=A[k++];
                matrix[j][i]=matrix[i][j];
            }

        }
    }

    printf("The symmetric matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
