#include <stdio.h>
#include <stdlib.h>

int main() {
    long A, B;
    int DA, DB, numA = 0, numB = 0, PA = 0, PB = 0;
    scanf("%ld %d %ld %d", &A, &DA, &B, &DB);
    while (1) {
        if (A == 0 && B == 0)
            break;
        if (A != 0) {
            if (A % 10 == DA)
                numA++;
            A = A / 10;
        }
        if (B != 0) {
            if (B % 10 == DB)
                numB++;
            B = B / 10;
        }
    }
    while (1) {
        if (numA == 0 && numB == 0)
            break;
        if (numA != 0) {
            PA = PA * 10 + DA;
            numA--;
        }
        if (numB != 0) {
            PB = PB * 10 + DB;
            numB--;
        }
    }
    printf("%d\n", PA + PB);
    return 0;
}