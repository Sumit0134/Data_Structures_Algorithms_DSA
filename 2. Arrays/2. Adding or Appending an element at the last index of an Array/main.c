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
    printf("Enter total of %d elements to store in an array: ", arr->length);
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

void Add(struct Array *arr)
{
    if(arr->length<arr->size)
    {
        int x;
        printf("Enter the element you want to add: ");
        scanf("%d", &x);
        arr->A[arr->length]=x;
        arr->length++;
    }
    else
    {
        printf("No space for adding a new element.\n");
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Add(&arr);
    Display(arr);
}
