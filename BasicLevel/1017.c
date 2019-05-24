//
// Created by 44811 on 2019/5/24.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    char A[1001], res[1001] = {'\0'}, *p = res;
    int B;
    int twodigit, remainder = 0;
    scanf("%s %d", A, &B);
    for (int i = 0; A[i]; ++i) {
        twodigit = remainder * 10 + (A[i] - '0');
        res[i] = twodigit / B + '0';
        remainder = twodigit % B;
    }
    if (res[0] == '0' && res[1] != '\0')
        p++;
    printf("%s %d", p, remainder);
    return 0;
}