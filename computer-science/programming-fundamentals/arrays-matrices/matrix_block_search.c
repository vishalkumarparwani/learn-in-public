#include <stdio.h>
int main()
{
    int arr[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int count = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (count >= 3)
            {
                printf("\n2x2 block with 3+ ones found at [%d, %d]: ", i, j);
            }
        }
    }

    return 0;
}