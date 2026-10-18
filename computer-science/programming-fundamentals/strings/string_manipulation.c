#include <stdio.h>

void middleremove(char input[], char output[])
{
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (i == 0 || input[i] != input[i - 1])
        {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

int main()
{

    char input[50];
    char output[50];

    printf("Enter a word:");
    scanf("%s", input);

    middleremove(input, output);

    printf("Result: %s\n", output);

    return 0;
}