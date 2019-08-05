//
// Created by 44811 on 2019/8/5.
// 1033 旧键盘打字
//
#include <stdio.h>
#include <ctype.h>

int main() {
    //ASCII code match
    int bad[128] = {0};
    char c;
    while ((c = getchar()) != '\n')
        bad[toupper(c)] = 1;
    while ((c = getchar()) != '\n') {
        if (!bad[toupper(c)] && !(isupper(c) && bad['+']))
            putchar(c);
    }
    return 0;
}