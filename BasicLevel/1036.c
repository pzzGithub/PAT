//
// Created by 44811 on 12/29/2019.
//

#include <stdio.h>

int main() {
    int N = 0;
    char C;
    scanf("%d %c", &N, &C);
    int row = N / 2 + N % 2;
    int column = N;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; ++j) {
            if (i == 0 || i == row - 1)
                printf("%c", C);
            else if (j == 0 || j == column - 1)
                printf("%c", C);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}