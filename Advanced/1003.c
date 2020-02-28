//
// Created by 44811 on 2020/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Inf INT_MAX

//数组填充
void arrayFill(int *array, int len, int val) {
    int i;
    for (i = 0; i < len; i++) array[i] = val;
}

void Dijkstra(int graph[500][500], int *teamNums, int n, int source, int destination) {
    int *pathNum = (int *) malloc(sizeof(int) * n);//路径数量
    int *shortestDistance = (int *) malloc(sizeof(int) * n);//最短路径长度
    int *maxTeamNums = (int *) malloc(sizeof(int) * n);//最大救援队数量
    int *mark = (int *) malloc(sizeof(int) * n);//是否被访问
    arrayFill(pathNum, n, 0);
    arrayFill(mark, n, 0);
    arrayFill(shortestDistance, n, Inf);
    arrayFill(maxTeamNums, n, 0);
    int minDistance, vertex;
    //初始化
    shortestDistance[source] = 0;
    maxTeamNums[source] = teamNums[source];
    pathNum[source] = 1;

    while (1) {
        minDistance = Inf;
        vertex = -1;
        //找出到未标记节点的最短路径
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                if (shortestDistance[i] < minDistance) {
                    minDistance = shortestDistance[i];
                    vertex = i;
                }
            }
        }
        if (vertex == -1) break;
        mark[vertex] = 1;
        //更新最短路径
        for (int i = 0; i < n; i++) {
            if (!mark[i] && graph[vertex][i] != Inf) {
                if (shortestDistance[vertex] + graph[vertex][i] < shortestDistance[i]) {
                    shortestDistance[i] = shortestDistance[vertex] + graph[vertex][i];
                    maxTeamNums[i] = maxTeamNums[vertex] + teamNums[i];
                    pathNum[i] = pathNum[vertex];
                } else if (shortestDistance[vertex] + graph[vertex][i] == shortestDistance[i]) {
                    pathNum[i] += pathNum[vertex];
                    if (maxTeamNums[vertex] + teamNums[i] > maxTeamNums[i])
                        maxTeamNums[i] = maxTeamNums[vertex] + teamNums[i];
                }
            }
        }
    }

    //output
    printf("%d %d", pathNum[destination], maxTeamNums[destination]);
}

int main() {
    int N, M, C1, C2, *teamNums;
    int graph[500][500];
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            graph[i][j] = Inf;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    teamNums = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &teamNums[i]);
        graph[i][i] = 0;
    }
    int source, destination, distance;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &source, &destination, &distance);
        graph[source][destination] = distance;
        graph[destination][source] = distance;
    }
    Dijkstra(graph, teamNums, N, C1, C2);
    return 0;
}
//