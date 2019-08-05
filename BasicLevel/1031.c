//
// Created by 44811 on 2019/8/3.
// 1031 查验身份证
//
#include <stdio.h>

int main() {
    int n;
    int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char Z2M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char id[19];
    int sum, count = 0, j;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", id);
        for (j = 0, sum = 0; j < 17 && id[j] >= '0' && id[j] <= '9'; j++)
            sum += (id[j] - '0') * weights[j];
        if (j == 17 && id[17] == Z2M[sum % 11])
            count++;
        else
            puts(id);
    }

    if (count == n)
        puts("All passed");
    return 0;
}
