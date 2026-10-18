#include <stdio.h>
int main()
{
    int fib = 0, a = 1;
    int num;

    printf("Enter a number upto 10000\n");
    scanf("%d", &num);

    if (num > 0 && num <= 10000)
    {
        printf("Fibonacci series upto %d terms:\n", num);
        for (int i = 1; i <= num; i++)
        {
            printf("%d ", fib);

            int temp = fib + a;

            a = fib;

            fib = temp;
        }
    }
    else
    {
        printf("Please enter a valid number between 1 and 10000.\n");
    }

    return 0;
}