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
    printf("Enter total of %d elements of an array in a sorted manner: ", arr->length);
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

int BinarySearch(struct Array arr)
{
    int x, low, mid, high;
    low=0;
    high=arr.length-1;
    printf("Enter the element which you want to search: ");
    scanf("%d", &x);
    int RecursiveBinarySearch(int low, int high)
    {
        if(low<=high)
        {
            mid=(low+high)/2;
            if(x==arr.A[mid])
            {
                return mid;
            }
            else if(x>arr.A[mid])
            {
                return RecursiveBinarySearch(mid+1, high);
            }
            else
            {
                return RecursiveBinarySearch(low, mid-1);
            }
        }
        return -1;
    }
    return RecursiveBinarySearch(low, high);
}

// int RecursiveBinarySearch(int arr[], int low, int high, int x)
// {
//     int mid;
//     if(low<=high)
//     {
//         mid=(low+high)/2;
//         if(x==arr[mid])
//         {
//             return mid;
//         }
//         else if(x>arr[mid])
//         {
//             return RecursiveBinarySearch(arr, mid+1, high, x);
//         }
//         else
//         {
//             return RecursiveBinarySearch(arr, low, mid-1, x);
//         }
//     }
//     return -1;
// }

// int BinarySearch(struct Array arr)
// {
//     int x, low, high;
//     low=0;
//     high=arr.length-1;
//     printf("Enter the element which you want to search: ");
//     scanf("%d", &x);
//     return RecursiveBinarySearch(arr.A, low, high, x);
// }

int main()
{
    struct Array arr;
    Create(&arr);
    Display(arr);
    int x=BinarySearch(arr);
    if(x==-1)
    {
        printf("Element is not present.\n");
    }
    else
    {
        printf("Element is present and it is found at index: %d", x);
    }
}

