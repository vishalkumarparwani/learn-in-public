#include <stdio.h>
int main()
{
    int arr[50] = {0};
    int i, n = 5;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *p = &arr[n - 1];

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", *p);
        p--;
    }

    return 0;
}