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
    arr->A=(int *)malloc(arr->size*sizeof(int));
    printf("Enter the length of an array: ");
    scanf("%d", &arr->length);
    if(arr->length>arr->size)
    {
        printf("Length is greater than the size.");
        free(arr->A);
        exit(1);
    }
    printf("Enter total of %d elements (positive & negative) of an array: ", arr->length);
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

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Segregating(struct Array *arr)
{
    int i=0, j=arr->length-1;
    while(i<j)
    {
        while(i<arr->length && arr->A[i]<0)
        {
            i++;
        }
        while(j>=0 && arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    Segregating(&arr);
    printf("After segregating: ");
    Display(arr);
}
