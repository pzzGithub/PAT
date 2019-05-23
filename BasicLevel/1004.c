//
// Created by 44811 on 2019/5/9.
//
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[15];
    char number[15];
    int score;
};

int main() {
    int n;
    scanf("%d", &n);
    struct student *stus = malloc(sizeof(struct student) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", stus[i].name, stus[i].number, &stus[i].score);
    }
    int maxScore = -1, minScore = 101, maxIndex = 0, minIndex = 0;
    for (int j = 0; j < n; j++) {
        if (stus[j].score > maxScore) {
            maxScore = stus[j].score;
            maxIndex = j;
        }
        if (stus[j].score < minScore) {
            minScore = stus[j].score;
            minIndex = j;
        }
    }
    printf("%s %s\n", stus[maxIndex].name, stus[maxIndex].number);
    printf("%s %s\n", stus[minIndex].name, stus[minIndex].number);
    return 0;
}