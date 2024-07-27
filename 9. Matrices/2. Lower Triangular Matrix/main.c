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
      printf("As the number of rows is not equal to the number of columns, we cannot create a lower triangular matrix");
      return 0;
    }

    int matrix[n][m];

    int s=(n*(n+1))/2;
    int A[s], k;

    printf("Enter total of %d elements for a lower triangular matrix:\n", s);
    for(k=0; k<s; k++)
    {
        scanf("%d", &A[k]);
    }

    printf("The lower triangular matrix is:\n");
    k=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i>=j)
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
