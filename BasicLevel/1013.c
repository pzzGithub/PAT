#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    int flag = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int prime[10000], count = 1;
    prime[0] = 2;
    while (count < 10000) {
        for (int i = 3; count < 10000; ++i) {
            if (isPrime(i)) {
                prime[count] = i;
                count++;
            }
        }
    }
    int nums = 0;
    for (int j = m - 1; j < n; ++j) {
        nums++;
        if (nums % 10) {
            if (j != n - 1)
                printf("%d ", prime[j]);
            else
                printf("%d", prime[j]);
        } else
            printf("%d\n", prime[j]);
    }
    return 0;
}