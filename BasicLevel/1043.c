//
// Created by 44811 on 12/30/2019.
//

#include <stdio.h>

int main() {
    char ch, *str = "PATest";
    int count[128] = {0};
    while ((ch = getchar()) != '\n')
        count[ch]++;
    int flag = 0;
    for (int i = 0; i < 6; i++) {
        if (count[str[i]] > flag)
            flag = count[str[i]];
    }
    while (flag) {
        for (int i = 0; i < 6; i++) {
            if (count[str[i]]-- > 0)
                putchar(str[i]);
        }
        flag--;
    }

    return 0;
}