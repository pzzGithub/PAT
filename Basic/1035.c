//
// Created by 44811 on 12/29/2019.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int length = 0;
    scanf("%d", &length);
    int *origin = (int *) malloc(sizeof(int) * length);
    int *half = (int *) malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
        scanf("%d", origin + i);
    for (int i = 0; i < length; i++)
        scanf("%d", half + i);

    return 0;
}