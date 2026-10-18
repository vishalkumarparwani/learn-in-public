#include <Stdio.h>
#include <string.h>
int main()
{
    int isPalindrome = 1;
    char str[25] = "\0";

    printf("Enter string: ");
    // fgets(str, sizeof(str), stdin);
    scanf("%s", str);

    int length = strlen(str);
    for (int i = 0; i < length / 2; i++, length--)
    {
        if (str[i] != str[length - 1])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("\nPalindrome");
    else
        printf("\nNot A Palindrome");

    return 0;
}