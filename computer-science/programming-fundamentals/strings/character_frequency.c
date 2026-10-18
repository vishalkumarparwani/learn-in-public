#include <stdio.h>

int countFrequency(char str[], char ch)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            count++;
    }
    return count;
}

int main()
{
    char str[35] = "\0";
    char ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character: ");
    scanf(" %c", &ch);

    int result = countFrequency(str, ch);

    if (result)
    {
        printf("\nThe given character %c appears %d times in the string.\n", ch, result);
    }

    else
    {
        printf("\nNot a single character of string matches with the given character.");
    }
    return 0;
}