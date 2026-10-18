#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numStrings = 5;
    int maxLength = 7;

    char **strings = (char **)calloc(numStrings, sizeof(char *));

    if (strings == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < numStrings; i++)
    {
        strings[i] = (char *)calloc(maxLength, sizeof(char));
        if (strings == NULL)
        {
            printf("Memory allocation failed\n");
        }
    }

    strings[0] = "You ";
    strings[1] = "Are ";
    strings[2] = "The ";
    strings[3] = "Best ";
    strings[4] = "Person ";

    for (int i = 0; i < numStrings; i++)
    {
        printf("%s ", strings[i]);
    }

    for (int i = 0; i < numStrings; i++)
    {
        free(strings[i]);
    }

    free(strings);

    return 0;
}