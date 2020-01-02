//
// Created by 44811 on 12/29/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K, count[101] = {0};
    scanf("%d", &N);
    int *scores = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
        count[scores[i]]++;
    }
    scanf("%d", &K);
    int *search = (int *) malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++) scanf("%d", &search[i]);
    for (int i = 0; i < K; i++)
        printf("%d%c", count[search[i]], i == K - 1 ? '\n' : ' ');
    return 0;
}