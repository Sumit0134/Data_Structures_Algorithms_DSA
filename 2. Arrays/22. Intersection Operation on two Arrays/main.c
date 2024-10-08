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
    printf("Enter total of %d elements of an array in a sorted manner: ", arr->length);
    for(int i=0; i<arr->length; i++)
    {
        scanf("%d", &arr->A[i]);
    }
}

void Display(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Intersection(struct Array *arr1, struct Array *arr2)
{
    int arr3[arr1->length+arr2->length], i=0, j=0, k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            i++;
        }
        else if(arr1->A[i]>arr2->A[j])
        {
            j++;
        }
        else
        {
            arr3[k++]=arr1->A[i++];
            j++;
        }
    }
    printf("After performing Intersection operation, the elements of an array is: ");
    for(int l=0; l<k; l++)
    {
        printf("%d ", arr3[l]);
    }
}

int main()
{
    struct Array arr1, arr2;
    printf("Creation of first array:\n");
    Create(&arr1);
    printf("Creation of second array:\n");
    Create(&arr2);
    printf("The elements of the first array is: ");
    Display(arr1);
    printf("The elements of the second array is: ");
    Display(arr2);
    Intersection(&arr1, &arr2);
}

