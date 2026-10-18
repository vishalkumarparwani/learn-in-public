#include <stdio.h>

void matrixAdd(int mat1[][10], int mat2[][10], int result[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matrixSubtract(int mat1[][10], int mat2[][10], int result[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void matrixMultiply(int mat1[][10], int mat2[][10], int result[][10], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void inputMatrix(int mat[][10], int m, int n)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[10][10], mat2[10][10], result[10][10];
    int m, n, p;
    int choice;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &p, &n);

    if (m != p && (choice == 3))
    {
        printf("Matrix multiplication isn't possible with these dimensions\n");
        return 0;
    }

    printf("Enter matrix 1:\n");
    inputMatrix(mat1, m, n);

    printf("Enter matrix 2:\n");
    inputMatrix(mat2, p, n);

    printf("Choose operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        if (m == p)
        {
            matrixAdd(mat1, mat2, result, m, n);
            printf("Result of Matrix Addition:\n");
            displayMatrix(result, m, n);
        }
        else
        {
            printf("Matrix addition isn't possible with different dimensions.\n");
        }
        break;

    case 2:
        if (m == p)
        {
            matrixSubtract(mat1, mat2, result, m, n);
            printf("Result of Matrix Subtraction:\n");
            displayMatrix(result, m, n);
        }
        else
        {
            printf("Matrix subtraction isn't possible with different dimensions.\n");
        }
        break;

    case 3:
        if (n == p)
        {
            matrixMultiply(mat1, mat2, result, m, n, p);
            printf("Result of Matrix Multiplication:\n");
            displayMatrix(result, m, p);
        }
        else
        {
            printf("Matrix multiplication is not possible as number of columns in matrix 1 does not equal number of rows in matrix 2.\n");
        }
        break;

    default:
        printf("Invalid operation.\n");
    }

    return 0;
}
