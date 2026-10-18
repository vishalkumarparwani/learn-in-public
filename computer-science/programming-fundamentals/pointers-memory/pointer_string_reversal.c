#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reversed(const char * str)
{
    int len = strlen(str);

    char *rev = (char*)malloc((len + 1) * sizeof(char));

    char temp;

    for(int i = 0; i < len; i++)
    {
        rev[i] = str[len - 1 - i];
    }

    return rev;
}

int main()
{
    char *str = "Hello World, I'm Vishal";

    char *rev = reversed(str);

    printf("\n%s\n", rev);
    free(rev);

    return 0;
}