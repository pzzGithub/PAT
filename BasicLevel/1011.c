#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long a, b, c;
    for (int i = 1; i <= n; ++i) {
        scanf("%ld %ld %ld", &a, &b, &c);
        if ((a / 2.0) + (b / 2.0) > (c / 2.0))
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}