#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *numA = (int *)a;
    int *numB = (int *)b;
    return *numA - *numB;
}

int ascendingOrder(int num)
{
    int nums[4], res = 0;
    for (int i = 0; i < 4; i++)
    {
        nums[i] = num % 10;
        num = num / 10;
    }
    qsort(nums, 4, sizeof(nums[0]), compare);
    for (int j = 0; j < 4; ++j)
    {
        res = res * 10 + nums[j];
    }
    return res;
}

int descendingOrder(int num)
{
    int nums[4], res = 0;
    for (int i = 0; i < 4; i++)
    {
        nums[i] = num % 10;
        num = num / 10;
    }
    qsort(nums, 4, sizeof(nums[0]), compare);
    for (int j = 3; j >= 0; j--)
    {
        res = res * 10 + nums[j];
    }
    return res;
}

int main()
{
    int num;
    scanf("%d", &num);
    while (1)
    {
        printf("%04d - %04d = %04d\n", descendingOrder(num), ascendingOrder(num),
               descendingOrder(num) - ascendingOrder(num));
        num = descendingOrder(num) - ascendingOrder(num);
        if (num == 0 || num == 6174)
            break;
    }
    return 0;
}