#include <stdio.h>
int main()
{
    int LCM, GCD, a, b, n1, n2;

    printf("Enter a number: ");
    scanf("%d%d", &a, &b);
    n1 = a;
    n2 = b;
    while (b != 0)
    {

        int temp = b;
        b = a % b;
        a = temp;
    }
    GCD = a;
    LCM = (n1 * n2) / GCD;

    printf("GCD: %d\nLCM: %d", GCD, LCM);

    return 0;
}