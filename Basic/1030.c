//
// Created by 44811 on 2019/8/3.
// 1030 完美数列
//
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int N, p, m = 0, M = 0, count = 0;
    scanf("%d %d", &N, &p);
    int *nums = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &nums[i]);

    qsort(nums, N, sizeof(int), cmp);
    int first, last, max = 0;
    for (first = 0, last = 0; last < N && max < N - first; first++) {
        while (last < N && nums[last] <= 1L * p * nums[first])
            last++;
        if (max < last - first)
            max = last - first;
    }
    printf("%d", max);

    return 0;
}