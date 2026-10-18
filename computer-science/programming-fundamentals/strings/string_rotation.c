#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char str1[30];
    char str2[30];
    int len1, len2, isRotation = 1, count = 0;
    printf("Enter the first string: ");
    // fgets(str1, sizeof(str1), stdin);
    scanf("%s", str1);

    printf("Enter the second string: ");
    // fgets(str2, sizeof(str2), stdin);
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 != len2)
        isRotation = 0;

    char combined[30] = "\0";
    strcpy(combined, str1);
    strcat(combined, str1);
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len1 && combined[i + j] == str2[j]; j++)
        {
            if (str2[j] == str1[j])
                count++;
        }
        if (count != len1)
            isRotation = 0;
    }

    if (isRotation)
        printf("Is rotation\n");

    else
        printf("Not a Rotation\n");

    return 0;
}