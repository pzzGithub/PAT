//
// Created by 44811 on 2019/5/22.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int *nums = malloc(sizeof(int) * n);
        int a = 0, b = 0, c = 0, e = 0;
        float d = 0.0;
        int bIndex = 1, dIndex = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        for (int j = 0; j < n; ++j) {
            switch (nums[j] % 5) {
                case 0:
                    if (nums[j] % 2 == 0)
                        a += nums[j];
                    break;
                case 1:
                    if (bIndex % 2 == 0)
                        b -= nums[j];
                    else
                        b += nums[j];
                    bIndex++;
                    break;
                case 2:
                    c++;
                    break;
                case 3:
                    d += nums[j];
                    dIndex++;
                    break;
                case 4:
                    if (nums[j] > e)
                        e = nums[j];
                    break;
            }
        }
        if (a == 0)
            printf("N ");
        else
            printf("%d ", a);
        if (bIndex == 1)
            printf("N ");
        else
            printf("%d ", b);
        if (c == 0)
            printf("N ");
        else
            printf("%d ", c);
        if (dIndex == 0)
            printf("N ");
        else
            printf("%.1f ", d / dIndex);
        if (e == 0)
            printf("N");
        else
            printf("%d", e);

    }
    return 0;
}
