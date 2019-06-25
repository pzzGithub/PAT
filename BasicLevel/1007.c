#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
    int flag = 1;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 3; i < n; ++i)
    {
        if (isPrime(i))
        {
            if (isPrime(i + 2) && (i + 2) <= n)
            {
                sum++;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}