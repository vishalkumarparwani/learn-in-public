#include<stdio.h>

void recursive(int arr[], int size, int i)
{
    if(size == 0)
    {
        printf("\nEnter size: ");
        scanf("%d", &size);
    }

    if(i < size)
    {
        printf("Enter elements of array: ");

        scanf("%d", &arr[i]);
        return recursive(arr, size, i+1);
    }
    i = 0;
    printf("OUTPUT : %d ", arr[i]);
    return recursive(arr, size, i++);
}

int main()
{
    int arr[20];

    recursive(arr, 0, 0);

    return 0;
}