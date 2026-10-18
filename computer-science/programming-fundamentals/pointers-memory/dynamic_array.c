#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *arr = (float *)malloc(4 * sizeof(float));

    if (arr == NULL)
    {
        printf("Memory Allocation Failed!\n");

        return 1;
    }

    int count = 4;

    printf("Enter elements of array:\n");

    for (int i = 0; i < 4; i++)
    {
        scanf("%f", &arr[i]);
    }

    arr = (float *)realloc(arr, 8 * sizeof(float));

    if (arr == NULL)
    {
        printf("Memory Reallocation Failed!\n");

        return 1;
    }

    printf("Enter the 5th element of the array: ");

    scanf("%f", &arr[4]);

    count = 5;

    for (int i = 0; i < count; i++)
    {
        printf("%.1f ", arr[i]);
    }

    arr = (float *)realloc(arr, count * sizeof(float));

    if (arr == NULL)
    {
        printf("Memory Reallocation Failed!\n");
        return 1;
    }

    free(arr);

    return 0;
}