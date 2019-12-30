//
// Created by 44811 on 12/30/2019.
//

#include <stdio.h>
#include <string.h>

typedef struct Info {
    char id[17];
    int testNum;
    int examNum;
} info;

int main() {
    int N, M;
    scanf("%d", &N);
    info allStu[1001];
    int testNum;
    char id[16];
    int examNum;
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d", id, &testNum, &examNum);
        strcpy(allStu[testNum].id, id);
        allStu[testNum].testNum = testNum;
        allStu[testNum].examNum = examNum;
    }

    scanf("%d", &M);
    int searchTestNum;
    for (int i = 0; i < M; i++) {
        scanf("%d", &searchTestNum);
        printf("%s %d\n", allStu[searchTestNum].id, allStu[searchTestNum].examNum);
    }
    return 0;
}