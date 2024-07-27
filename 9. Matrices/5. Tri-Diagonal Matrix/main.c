#include<stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of rows n: ");
    scanf("%d", &n);
    printf("Enter the number of column m: ");
    scanf("%d", &m);

    if(n!=m)
    {
        printf("As the number of rows is not equal to the number of columns, we cannot create a tri-diagonal matrix.");
        return 0;
    }

    int matrix[n][m];

    int s;
    s=3*n-2;
    printf("Enter total of %d elements for a tri-diagonal matrix: ", s);
    int A[s], k=0;
    for(int i=0; i<s; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("The tri-diagonal matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i-j==1)
            {
                matrix[i][j]=A[k++];
                printf("%d ", matrix[i][j]);
            }
            else if(i==j)
            {
                matrix[i][j]=A[k++];
                printf("%d ", matrix[i][j]);
            }
            else if(i-j==-1)
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
