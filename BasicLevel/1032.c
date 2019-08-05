//
// Created by 44811 on 2019/8/5.
// 1032 挖掘机技术哪家强
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, num, score;
    scanf("%d", &N);
    int *totalScore = malloc(sizeof(int) * N);
    memset(totalScore, 0, N * sizeof(int));

    for (int i = 0; i < N; ++i) {
        totalScore[i] = 0;
    }

    for (int j = 0; j < N; ++j) {
        scanf("%d %d", &num, &score);
        totalScore[num - 1] += score;
    }
    int maxScoreIndex = 0;
    for (int k = 0; k < N; ++k) {
        if (totalScore[k] > totalScore[maxScoreIndex]) {
            maxScoreIndex = k;
        }
    }
    printf("%d %d", maxScoreIndex + 1, totalScore[maxScoreIndex]);
    return 0;
}