#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 3, cols = 4;
    int **matrix;

    matrix = (int **)calloc(rows, sizeof(int *));
    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Memory allocation failed for row %d!\n", i);
            return 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i * cols + j;
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
    
    printf("Matrix memory freed.\n");

    return 0;
}