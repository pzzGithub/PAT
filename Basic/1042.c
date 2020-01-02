//
// Created by 44811 on 12/30/2019.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int count[128] = {0}, length = 0;
    char ch;
    int maxNum = 0, maxIndex = 0;

    while ((ch = getchar()) != '\n') {
        count[tolower(ch)]++;
        length++;
    }
    for (int i = 97; i < 123; i++) {
        if (count[i] > maxNum) {
            maxNum = count[i];
            maxIndex = i;
        }
    }
    printf("%c %d", (char) maxIndex, maxNum);
    return 0;
}