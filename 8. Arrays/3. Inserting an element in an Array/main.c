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

void Insert(struct Array *arr)
{
    int index;
    printf("Enter the index where you want to insert an element: ");
    scanf("%d", &index);
    if(index>=0 && index<=arr->length)
    {
        int x, i;
        printf("Enter the element which you want to insert at index %d: ", index);
        scanf("%d", &x);
        for(i=arr->length; i>index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[i]=x;
        arr->length++;
    }
    else
    {
        printf("Invalid index or no space for inserting a new element.\n");
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Insert(&arr);
    Display(arr);
}
