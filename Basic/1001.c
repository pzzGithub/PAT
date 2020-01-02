#include <stdio.h>

int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        int i = 0;
        while (1)
        {
            if (num == 1)
                break;
            if (num % 2 == 0)
            {
                num = num / 2;
                i++;
            }
            else
            {
                num = (3 * num + 1) / 2;
                i++;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}