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

void countingDuplicates(struct Array arr)
{
   printf("The duplicate elements present in an array are:\n");
   for(int i=0; i<arr.length-1; i++)
   {
       int count=1;
       if(arr.A[i]!=-1)
       {
           for(int j=i+1; j<arr.length; j++)
           {
               if(arr.A[i]==arr.A[j])
               {
                   count++;
                   arr.A[j]=-1;
               }
           }
           if(count>1)
           {
               printf("%d for %d times\n", arr.A[i], count);
           }
       }
   }
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    countingDuplicates(arr);
}
