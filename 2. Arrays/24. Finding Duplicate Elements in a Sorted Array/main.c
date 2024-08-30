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
        printf("Length is greater than the size.\n");
        free(arr->A);
        exit(1);
    }
    printf("Enter toatl of %d elements of an array in a sorted manner: ", arr->length);
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

void Duplicates(struct Array arr)
{
   int lastDuplicate=0;
   printf("The duplicate elements present in an array are: ");
   for(int i=0; i<arr.length-1; i++)
   {
       if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate)
       {
           printf("%d, ", arr.A[i]);
           lastDuplicate=arr.A[i];
       }
   }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    Duplicates(arr);
}
