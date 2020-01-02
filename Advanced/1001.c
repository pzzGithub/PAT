//
// Created by 44811 on 2020/1/2.
//

#include <stdio.h>

int main() {
    int a, b, sum, length;
    int str[7];
    scanf("%d %d", &a, &b);
    sum = a + b > 0 ? a + b : -a - b;
    for (int i = 0;; i++) {
        str[i] = sum % 10;
        sum /= 10;
        if (sum == 0) {
            length = i;
            break;
        }
    }
    if (a + b < 0)
        printf("-");
    for (int i = length; i >= 0; i--) {
        printf("%d", str[i]);
        if (i % 3 == 0 && i != 0)
            printf(",");
    }
    return 0;
}