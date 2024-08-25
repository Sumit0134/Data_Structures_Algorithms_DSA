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

int isSorted(struct Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
    {
        if(arr->A[i]>arr->A[i+1])
        return 0;
    }
    return 1;
}

void Insert(struct Array *arr)
{
    if(isSorted(arr) && arr->length<arr->size)
    {
        int x, i, j;
        printf("Enter the element which you want to insert: ");
        scanf("%d", &x);
        for(i=0; i<arr->length; i++)
        {
            if(x<arr->A[i])
            {
                break;
            }
        }
        for(j=arr->length-1; j>=i; j--)
        {
            arr->A[j+1]=arr->A[j];
        }
        arr->A[i]=x;
        arr->length++;
    }
    else
    {
        printf("Either array is not sorted or there is no space for inserting any new element.\n");
        exit(1);
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    Insert(&arr);
    printf("After insertion: ");
    Display(arr);
}

