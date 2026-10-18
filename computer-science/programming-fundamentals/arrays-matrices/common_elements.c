#include <stdio.h>

int alreadyPrint(int temp[], int integer, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (temp[i] == integer)
            return 1;
    }
    return 0;
}

void findCommonElements(int arr1[], int arr2[], int size)
{
    int temp[25] = {0}, k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (!alreadyPrint(temp, arr1[i], k))
                {
                    temp[k] = arr1[i];
                    k++;
                    printf("Common Element: %d\n", arr1[i]);
                }
                break;
            }
        }
    }
}

int main()
{
    int arr1[25], arr2[25], size = 10;

    printf("Enter elements of first array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of first array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr2[i]);
    }

    findCommonElements(arr1, arr2, size);

    return 0;
}