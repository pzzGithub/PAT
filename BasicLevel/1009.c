#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[81], dstStr[81] = {'\0'};
    scanf("%[^\n]", str);
    int n = strlen(str);
    int head = n, tail = n;
    for (int i = n; i > 0; i--) {
        if (str[i] == ' ') {
            head = i;
            strncat(dstStr, str + head + 1, tail - head - 1);
            strcat(dstStr, " ");
            tail = head;
        }
    }
    strncat(dstStr, str, tail);
    printf("%s", dstStr);
    return 0;
}