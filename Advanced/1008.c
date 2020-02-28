//
// Created by 44811 on 2020/1/30.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *requests, currentFloor = 0, time = 0;
    scanf("%d", &N);
    requests = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &requests[i]);
    for (int i = 0; i < N; i++) {
        if (requests[i] >= currentFloor)
            time += (requests[i] - currentFloor) * 6 + 5;
        else
            time += (currentFloor - requests[i]) * 4 + 5;
        currentFloor = requests[i];
    }
    printf("%d\n", time);
    return 0;
}