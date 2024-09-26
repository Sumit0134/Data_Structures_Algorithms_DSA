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

void pairSum(struct Array arr)
{
    int k, found=0;
    printf("Enter the sum value for which you want the pair: ");
    scanf("%d", &k);
    printf("The pair of elements are: ");
    for(int i=0; i<arr.length-1; i++)
    {
        for(int j=i+1; j<arr.length; j++)
        {
            if(k==arr.A[i]+arr.A[j])
            {
                printf("%d + %d=%d\n", arr.A[i], arr.A[j], k);
                found=1;
            }
        }
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

