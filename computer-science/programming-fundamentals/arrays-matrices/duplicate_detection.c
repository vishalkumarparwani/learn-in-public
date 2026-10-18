#include <stdio.h>
#include <stdbool.h>

bool hasDuplicates(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int duplicate = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[35], n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (hasDuplicates(arr, n))
        printf("\nDuplicates found.");

    else
        printf("\nNo duplicates.");

    return 0;
}