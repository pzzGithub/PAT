//
// Created by 44811 on 2019/5/11.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, nums[100] = {0}, num;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            nums[num] = 1;
        }

        for (int i = 1; i <= 100; ++i) {
            if (nums[i]) {
                for (int j = i; j > 1;) {
                    if (j % 2)
                        j = (3 * j + 1) / 2;
                    else
                        j /= 2;
                    if (j <= 100 && nums[j]) {
                        nums[j] = 0;
                        if (j < i)
                            break;
                    }
                }
            }
        }

        for (int i = 100; i >= 1; i--) {
            if (nums[i] == 1)
                printf("%d ", i);
        }
        printf("\b");
    }
    return 0;
}