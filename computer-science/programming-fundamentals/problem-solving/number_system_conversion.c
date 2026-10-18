#include <stdio.h>
#include <string.h>
#include <math.h>

int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);

int main()
{
    int num = 0;
    printf("Enter (1-6):\n1 to convert Binary To Decimal\n2 to convert from Decimal to Binary\n3 to convert Decimal to Hexadecimal\n4 to convert Hexadecimal to Decimal\n5 to convert Binary to Hexadecimal\n6 to convert Hexadecimal to Binary\n");
    scanf("%d", &num);

    if (num < 1 || num > 6)
    {
        printf("Enter number between 1-6\n");
        return 1;
    }
    else if (num == 1)
    {
        int binary;
        printf("Enter a binary number: ");
        scanf("%d", &binary);
        int decimal = BinaryToDecimal(binary);
        printf("Decimal: %d\n", decimal);
    }
    else if (num == 2)
    {
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        DecimalToBinary(decimal);
    }
    else if (num == 3)
    {
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        DecimalToHexadecimal(decimal);
    }
    else if (num == 4)
    {
        char hexNumber[20];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        HexadecimalToDecimal(hexNumber);
    }
    else if (num == 5)
    {
        int binary;
        printf("Enter a binary number: ");
        scanf("%d", &binary);
        BinaryToHexadecimal(binary);
    }
    else if (num == 6)
    {
        char hexNumber[20];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        HexadecimalToBinary(hexNumber);
    }

    return 0;
}

int BinaryToDecimal(int number)
{
    int result = 0, n = 0, last;

    while (number > 0)
    {
        last = number % 10;
        number /= 10;
        result += last * pow(2, n);
        n++;
    }
    return result;
}

int DecimalToBinary(int number)
{
    if (number == 0)
    {
        printf("0\n");
        return 0;
    }
    int arr[50];
    int j = 0;

    while (number > 0)
    {
        arr[j] = number % 2;
        number = number / 2;
        j++;
    }
    for (int i = j - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void DecimalToHexadecimal(int number)
{
    char hex[50];
    int i = 0;

    while (number > 0)
    {
        int remainder = number % 16;
        if (remainder < 10)
        {
            hex[i] = remainder + '0';
        }
        else
        {
            hex[i] = (remainder - 10) + 'A';
        }
        number /= 16;
        i++;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void BinaryToHexadecimal(int number)
{
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToDecimal(char hexNumber[])
{
    int decimal = 0;
    int base = 1;

    int len = 0;
    while (hexNumber[len] != '\0')
    {
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        int value;

        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
        {
            value = hexNumber[i] - '0';
        }
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
        {
            value = hexNumber[i] - 'A' + 10;
        }
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f')
        {
            value = hexNumber[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid hexadecimal input.\n");
            return;
        }

        decimal += value * base;
        base = base * 16;
    }

    printf("Decimal: %d\n", decimal);
}

void HexadecimalToBinary(char hexNumber[])
{
    int decimal = 0;
    int base = 1;

    int len = 0;
    while (hexNumber[len] != '\0')
    {
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        int value;

        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
        {
            value = hexNumber[i] - '0';
        }
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
        {
            value = hexNumber[i] - 'A' + 10;
        }
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f')
        {
            value = hexNumber[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid hexadecimal input.\n");
            return;
        }

        decimal += value * base;
        base *= 16;
    }

    DecimalToBinary(decimal);
}