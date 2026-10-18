#include <stdio.h>
int main()
{

    int arr[5];
    int smallest, secondsmallest = 0;

    for (int i = 0; i < 5; i++)
    {

        printf("Enter Value at index [%d] : ", i);
        scanf("%d", &arr[i]);

        if (arr[i] >= 9999)
        {
            printf("Value must be < 9999\n");
            return 1;
        }
    }
    if (arr[0] < arr[1])
    {
        smallest = arr[0];
        secondsmallest = arr[1];
    }
    else
    {
        smallest = arr[1];
        secondsmallest = arr[0];
    }

    for (int i = 2; i < 5; i++)
    {
        if (arr[i] < smallest)
        {
            secondsmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondsmallest && arr[i] != smallest)
        {
            secondsmallest = arr[i];
        }
    }

    printf("Second smallest number is = %d", secondsmallest);

    return 0;
}