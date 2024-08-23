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

int Get(struct Array arr)
{
    int index, x=-1;
    printf("Enter the index for which you want to get the value: ");
    scanf("%d", &index);
    if(index>=0 && index<arr.length)
    {
        printf("The value present at the %d index is: %d.\n", index, arr.A[index]);
    }
    else
    {
        printf("Invalid index.\n");
    }
}

void Set(struct Array *arr)
{
    int index, x;
    printf("Enter the index in which you want to set the value: ");
    scanf("%d", &index);
    if(index>=0 && index<arr->length)
    {
        printf("Enter the value which you want to set: ");
        scanf("%d", &x);
        arr->A[index]=x;
    }
    else
    {
        printf("Invalid index.\n");
    }
}

void Average(struct Array arr)
{
    double total=0;
    for(int i=0; i<arr.length; i++)
    {
        total=total+arr.A[i];
    }
    printf("The average value of all the elements of an array is: %lf.\n", total/arr.length);
}

void Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    printf("The maximum element in an array is: %d.\n", max);
}

void Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    printf("The minimum element in an array is: %d.\n", min);
}

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    Get(arr);
    Set(&arr);
    Display(arr);
    Average(arr);
    Max(arr);
    Min(arr);
}
