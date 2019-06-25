#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, hundred, ten, bit;
    char res[30];
    while (scanf("%d", &n) != EOF)
    {
        memset(res, 0, 30);
        hundred = n / 100;
        ten = (n - hundred * 100) / 10;
        bit = n % 10;
        int i = 0;
        for (int j = 0; j < hundred; j++)
        {
            res[i] = 'B';
            i++;
        }
        for (int j = 0; j < ten; j++)
        {
            res[i] = 'S';
            i++;
        }
        for (int j = 1; j <= bit; j++)
        {
            res[i] = '0' + j;
            i++;
        }
        printf("%s\n", res);
    }
    return 0;
}