#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int size;
    int length;
    int *A;
};

void Create(struct Array *arr)
{
    printf("Enter the size of an array: ");
    scanf("%d", &arr->size);
    arr->A=(int *)malloc(sizeof(int)*arr->size);
    printf("Enter the length of an array: ");
    scanf("%d", &arr->length);
    if(arr->length>arr->size)
    {
        printf("Length is greater than the size.\n");
        free(arr->A);
        exit(1);
    }
    printf("Enter total of %d elements of an array: ", arr->length);
    for(int i=0; i<arr->length; i++)
    {
        scanf("%d", &arr->A[i]);
    }
}

void Display(struct Array arr)
{
    printf("The elements of an array is: ");
    for(int i=0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int Maximum(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}

void pairSum(struct Array arr)
{
    int k, found=0;
    printf("Enter the sum value for which you want the pair: ");
    scanf("%d", &k);
    int max=Maximum(arr);
    int hashArray[max];
    for(int i=0; i<max; i++)
    {
        hashArray[i]=0;
    }
    printf("The pair of elements are: ");
    for(int i=0; i<arr.length; i++)
    {
        int complement=k-arr.A[i];
        if(complement>=0 && complement<=max && hashArray[k-arr.A[i]]!=0)
        {
            printf("%d + %d=%d\n", arr.A[i], k-arr.A[i], k);
            found=1;
        }
        hashArray[arr.A[i]]++;
    }
    if(found==0)
    {
        printf("No such pair is found with sum %d.\n", k);
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    pairSum(arr);
}
