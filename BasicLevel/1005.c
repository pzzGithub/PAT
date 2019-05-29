//
// Created by 44811 on 2019/5/11.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, table[101] = {0}, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        table[num] = 1;
    }

    for (int i = 1; i <= 100; ++i) {
        if (table[i]) {
            for (int j = i; j > 1;) {
                if (j % 2)
                    j = (3 * j + 1) / 2;
                else
                    j /= 2;
                if (j <= 100 && table[j]) {
                    table[j] = 0;
                    n--;
                    if (j < i)
                        break;
                }
            }
        }
    }

    for (int i = 100; i >= 1; i--) {
        if (table[i] == 1)
            printf("%d%c", i, --n ? ' ' : '\0');
    }
    return 0;
}