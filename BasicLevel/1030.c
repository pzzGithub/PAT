#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, p, m = 0, M = 0, count = 0;
    scanf("%d %d", &N, &p);
    int *nums = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);

    for (int i = 0; i < N; i++) {
        if (nums[i] < m)
            m = nums[i];
        if (nums[i] > M)
            M = nums[i];
    }

    return 0;
}