#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, D;
    scanf("%d %d %d", &A, &B, &D);
    int sum = A + B;

    int power = 1;
    while (sum / D >= power)
        power *= D;
    while (power > 0)
    {
        printf("%d", sum / power);
        sum %= power;
        power /= D;
    }
    return 0;
}