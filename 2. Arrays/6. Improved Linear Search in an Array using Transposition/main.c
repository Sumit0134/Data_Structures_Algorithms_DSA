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

void swap(int *x, int *y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}

int ImprovedLinearSearch(struct Array *arr)
{
    int x, index;
    printf("Enter the element which you want to search: ");
    scanf("%d", &x);
    for(int i=0; i<arr->length; i++)
    {
        if(x==arr->A[i])
        {
            index=i;
            if(i>0)
            swap(&arr->A[i], &arr->A[i-1]);
            return index;
        }
    }
    return -1;
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    int x=ImprovedLinearSearch(&arr);
    if(x==-1)
    {
        printf("Element is not found.\n");
    }
    else
    {
        printf("Element is found and it is present at index: %d\n", x);
    }
    Display(arr);
}

