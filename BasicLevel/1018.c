#include <stdio.h>
#include <stdlib.h>

char getMax(int C, int B, int J) {
    if (C > B && C >= J)
        return 'C';
    if (B >= C && B >= J)
        return 'B';
    return 'J';
}

int main() {
    int N;
    int AWinC = 0, AWinB = 0, AWinJ = 0, BWinC = 0, BWinB = 0, BWinJ = 0;
    char a, b;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %c %c", &a, &b);
        if (a == 'C' && b == 'J')
            AWinC++;
        if (a == 'B' && b == 'C')
            AWinB++;
        if (a == 'J' && b == 'B')
            AWinJ++;
        if (b == 'C' && a == 'J')
            BWinC++;
        if (b == 'B' && a == 'C')
            BWinB++;
        if (b == 'J' && a == 'B')
            BWinJ++;
    }
    printf("%d %d %d\n", AWinC + AWinB + AWinJ, N - AWinC - AWinB - AWinJ - BWinC - BWinB - BWinJ,
           BWinC + BWinB + BWinJ);
    printf("%d %d %d\n", BWinC + BWinB + BWinJ, N - AWinC - AWinB - AWinJ - BWinC - BWinB - BWinJ,
           AWinC + AWinB + AWinJ);
    printf("%c %c", getMax(AWinC, AWinB, AWinJ), getMax(BWinC, BWinB, BWinJ));
    return 0;
}