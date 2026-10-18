#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char reverseString(char str[])
{
    char temp[25];
    int length = strlen(str);

    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        temp[j] = str[i];
    }
    for (int i = 0; i < length; i++)
    {
        str[i] = temp[i];
    }

    return '0';
}

int consonantCount(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) &&
            !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'))
        {
            count++;
        }
    }
    return count;
}

int vowelCount(char str[])
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
            count++;
        }

    return count;
}

int main()
{
    char str[25], reversed[25];

    printf("Enter string: ");
    scanf("%s", str);

    strcpy(reversed, str);

    reverseString(reversed);

    if (strcmp(str, reversed) == 0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a Palindrome\n");
    }

    printf("Number of vowels: %d\n", vowelCount(str));

    printf("Number of consonants: %d\n", consonantCount(str));

    return 0;
}