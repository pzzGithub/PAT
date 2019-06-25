#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        m = m % n;
        int *nums = malloc(n * sizeof(int));
        int temp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            if (i + m < n)
                nums[i + m] = temp;
            else
                nums[i + m - n] = temp;
        }
        for (int j = 0; j < n; j++) {
            printf("%d ", nums[j]);
        }
        printf("\b");
    }
    return 0;
}