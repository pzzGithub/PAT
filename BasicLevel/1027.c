#include <stdio.h>
#include <stdlib.h>

#define ABS(X) ((X) >= 0 ? (X) : -(X))

int main()
{
    int charNum;
    char character;
    scanf("%d %c", &charNum, &character);
    int i = 1, charNeeded;
    while (i)

    {
        if (charNum >= 2 * i * i - 1 && charNum < 2 * (i + 1) * (i + 1) - 1)
        {
            charNeeded = 2 * i * i - 1;
            break;
        }
        i++;
    }

    for (int j = 0; j < 2 * i - 1; j++)
    {
        for (int k = 0; k < i - 1 - ABS(i - 1 - j); k++)
            putchar(' ');
        for (int k = 0; k < 2 * ABS(i - 1 - j) + 1; k++)
            putchar(character);
        putchar('\n');
    }

    printf("%d", charNum - charNeeded);

    return 0;
}