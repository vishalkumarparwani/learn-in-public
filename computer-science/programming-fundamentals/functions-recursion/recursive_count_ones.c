#include <stdio.h>

int function(int i, int j, int count)
{
    int arr[3][3] =
        {
            {1, 0, 1},
            {0, 0, 1},
            {0, 1, 1}};
    if (i >= 3)
    {
        return count;
    }
    if (j >= 3)
    {
        return function(i + 1, 0, count);
    }
    if (arr[i][j] == 1)
    {
        count++;
    }
    return function(i, j + 1, count);
}

int main()
{
    int count = 0;

    count = function(0, 0, count);

    printf("No of 1s are = %d", count);

    return 0;
}