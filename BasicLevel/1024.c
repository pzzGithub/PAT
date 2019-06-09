//
// Created by 44811 on 2019/5/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int exponent;
    char line[10000], *p = line;
    scanf("%[^E]E%d", line, &exponent);
    if (*p++ == '-')
        putchar('-');
    if (exponent >= 0) {
        putchar(*p);
        for (p += 2; exponent != 0; exponent--) {
            if (*p)
                putchar(*p++);
            else
                putchar('0');
        }
        if (*p) {
            putchar('.');
            while (*p)
                putchar(*p++);
        }
    }
    if (exponent < 0) {
        printf("0.");
        for (exponent++; exponent != 0; exponent++)
            putchar('0');
        for (; *p; p++) {
            if (*p != '.')
                putchar(*p);
        }
    }
    return 0;
}