#include <stdio.h>
#include <string.h>

void SaveInOrder(char txt[10][100], char Local[][100])
{
    int index = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; txt[i][j] != '\0'; j++)
        {

            if (txt[i][j] == 'o' && txt[i][j + 1] == 'n' && txt[i][j + 2] == 'e')
            {

                strcpy(Local[index], txt[i]);
                txt[i][0] = '\0';
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; txt[i][j] != '\0'; j++)
        {

            if (txt[i][j] == 't' && txt[i][j + 1] == 'w' && txt[i][j + 2] == 'o')
            {
                strcpy(Local[index++], txt[i]);
                txt[i][0] = '\0';
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; txt[i][j] != '\0'; j++)
        {
            if (txt[i][j] == 't' && txt[i][j + 1] == 'h' && txt[i][j + 2] == 'r' && txt[i][j + 3] == 'e' && txt[i][j + 4] == 'e')
            {
                strcpy(Local[index++], txt[i]);
                txt[i][0] = '\0';
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; txt[i][j] != '\0'; j++)
        {
            if (txt[i][0] != '\0')
            {
                strcpy(Local[index++], txt[i]);
                txt[i][0] = '\0';
            }
        }
    }

    return;
}

int main()
{
    char txt[10][100];
    strcpy(txt[0], "this sentence contains two");
    strcpy(txt[1], "one is so easy");
    strcpy(txt[2], "what is two");
    strcpy(txt[3], "this cannot be three");
    strcpy(txt[4], "why is this not true");
    strcpy(txt[5], "no numbers here");

    char Local[10][100];

    SaveInOrder(txt, Local);

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", Local[i]);
    }

    return 0;
}