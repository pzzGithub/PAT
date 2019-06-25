#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char N[1000] = {'\0'};
    int count[10] = {0};
    scanf("%s", N);
    int length = strlen(N);
    for (int i = 0; i < length; ++i)
    {
        count[N[i] - '0']++;
    }
    for (int j = 0; j < 10; ++j)
    {
        if (count[j] != 0)
            printf("%d:%d\n", j, count[j]);
    }
    return 0;
}