//
// Created by 44811 on 2019/5/29.
//
#include <stdio.h>
#include <stdlib.h>

struct info {
    float storage;
    float totalPrice;
    float price;
};

int compare(const void *a, const void *b) {
    struct info *infoA = (struct info *) a;
    struct info *infoB = (struct info *) b;
    return infoA->price > infoB->price ? -1 : 1;
}

int main() {
    int num, needed;
    float totalPrice = 0.0;
    scanf("%d %d", &num, &needed);
    struct info *infos = malloc(sizeof(struct info) * num);
    for (int i = 0; i < num; ++i)
        scanf("%f", &infos[i].storage);
    for (int i = 0; i < num; ++i) {
        scanf("%f", &infos[i].totalPrice);
        infos[i].price = infos[i].totalPrice / infos[i].storage;
    }
    qsort(infos, num, sizeof(infos[0]), compare);
    int max = 0;
    while (needed > 0 && max <= num) {
        if (needed - infos[max].storage > 0) {
            totalPrice += infos[max].totalPrice;
            needed -= infos[max].storage;
            max++;
        } else {
            totalPrice += infos[max].price * needed;
            needed = 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}