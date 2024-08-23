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

int Delete(struct Array *arr)
{
    int index, x=-1;
    printf("Enter the index which you want to delete: ");
    scanf("%d", &index);
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(int i=index; i<arr->length-1; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    return x;
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    int x=Delete(&arr);
    if(x==-1)
    {
        printf("Invalid Index\n");
    }
    else
    {
        printf("The deleted element is: %d\n", x);
    }
    Display(arr);
}
