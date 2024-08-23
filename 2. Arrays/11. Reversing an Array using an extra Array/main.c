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
        printf("Length is greater than size");
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

void Reverse(struct Array arr)
{
    int B[arr.length];
    for(int i=arr.length-1, j=0; i>=0; i--, j++)
    {
        B[j]=arr.A[i];
    }
    for(int i=0; i<arr.length; i++)
    {
        arr.A[i]=B[i];
    }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    Reverse(arr);
    printf("After reversing: ");
    Display(arr);
}
