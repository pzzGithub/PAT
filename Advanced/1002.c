//
// Created by 44811 on 2020/1/2.
//

#include <stdio.h>
#include <math.h>

int main() {
    float a[1001] = {0.0}, b[1001] = {0.0};
    int K1, K2, K = 0, exponent;
    float coefficient;
    scanf("%d", &K1);
    for (int i = 0; i < K1; ++i) {
        scanf("%d %f", &exponent, &coefficient);
        a[exponent] = coefficient;
    }
    scanf("%d", &K2);
    for (int i = 0; i < K2; ++i) {
        scanf("%d %f", &exponent, &coefficient);
        b[exponent] = coefficient;
    }
    for (int i = 0; i < 1001; i++) {
        a[i] += b[i];
        if (fabs(a[i]) > 0.05)
            K++;
    }
    printf("%d", K);
    for (int i = 1000; i >= 0; i--) {
        if (fabs(a[i]) > 0.05)
            printf(" %d %.1f", i, a[i]);
    }
    return 0;
}