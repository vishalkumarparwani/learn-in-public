#include <stdio.h>

const int rows = 5;
const int cols = 5;

char grid[5][5] = {
    {'.', 'T', 'X', '.', '.'},
    {'.', '.', '.', '.', 'T'},
    {'.', 'X', '.', '.', '.'},
    {'.', '.', 'T', 'X', '.'},
    {'.', 'X', '.', '.', 'P'}};

void displayGrid()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int *x, int *y, int newX, int newY)
{
    if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] == 'X')
    {
        printf("Invalid move!\n");
        return;
    }
    if (grid[newX][newY] == 'T')
    {
        printf("Item collected!\n");
    }
    grid[*x][*y] = '.';
    grid[newX][newY] = 'P';
    *x = newX;
    *y = newY;
}

int main()
{
    int playerX = 4, playerY = 4;
    char move;

    while (1)
    {
        displayGrid();
        printf("Enter move W for up, S for down, A for left, D for right, Q to quit the game: ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q')
        {
            printf("Game is Over!\n");
            break;
        }

        int newX = playerX, newY = playerY;
        if (move == 'W' || move == 'w')
            newX--;
        else if (move == 'S' || move == 's')
            newX++;
        else if (move == 'A' || move == 'a')
            newY--;
        else if (move == 'D' || move == 'd')
            newY++;
        else
        {
            printf("Invalid input!\n");
            continue;
        }

        movePlayer(&playerX, &playerY, newX, newY);
    }

    return 0;
}
