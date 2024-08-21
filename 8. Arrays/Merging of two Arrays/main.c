#include<stdio.h>

void mergeArrays(int A[], int B[], int n, int m)
{
    printf("The merged array is: ");
    int i=0, j=0, C[n+m], k=0;

    while(i<n && j<m)
    {
        if(A[i]<B[j])
        {
            C[k++]=A[i++];
        }
        else
        {
            C[k++]=B[j++];
        }
    }
    for(; i<n; i++)
    {
        C[k++]=A[i];
    }
    for(; j<m; j++)
    {
        C[k++]=B[j];
    }

    for(k=0; k<n+m; k++)
    {
        printf("%d ", C[k]);
    }
}

int main()
{
    int n, m;

    printf("Enter the size of the first array n: ");
    scanf("%d", &n);
    printf("Enter the size of the second array m: ");
    scanf("%d", &m);

    int A[n], B[m];

    printf("Enter the %d elements for the first array: ", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the %d elements for the second array: ", m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &B[i]);
    }

    mergeArrays(A, B, n, m);
}
