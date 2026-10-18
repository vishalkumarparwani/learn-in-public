#include <stdio.h>

int recursion(int arr[][3], int i, int j, int count)
{
    if (i >= 3) 
    {
        return count;
    }

    if(j >= 3)
    {
        return recursion(arr, i + 1, 0, count);
    }

    if (arr[i][j] == 1) 
        count++;

    return recursion(arr, i, j + 1, count);
}

int main()
{
    int arr[3][3] = {
        {1, 0, 0},
        {0, 1, 1},
        {1, 0, 1}};

    int result = recursion(arr, 0, 0, 0);
    printf("Count of 1s along diagonal: %d\n", result);

    return 0;
}