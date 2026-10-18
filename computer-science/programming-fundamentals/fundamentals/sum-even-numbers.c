#include <stdio.h>

int sumEvenNumbers(int start, int end)
{
    int sum = 0;
    if (start % 2 != 0)
        start++;

    for (int i = start; i <= end; i += 2)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int a, b, result;

    printf("Enter start and end:\n");
    scanf("%d %d", &a, &b);

    result = sumEvenNumbers(a, b);

    if (result > 100)
        printf("The sum exceeds 100.\n");

    printf("The sum is: %d", result);
}