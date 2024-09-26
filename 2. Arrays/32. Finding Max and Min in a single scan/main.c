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
    if(arr->size<arr->length)
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

void maxMin(struct Array arr)
{
    int max=arr.A[0], min=arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
        else if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    printf("The maximum element is %d and the minimum element is %d.\n", max, min);
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    maxMin(arr);
}

