#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    char ch;
    scanf("%d", &num);
    while (getchar() != '\n');
    for (int i = 0; i < num; ++i) {
        int count[3] = {0}, pos = 0;
        while ((ch = getchar()) != '\n') {
            if (ch == 'A')
                count[pos]++;
            else if (ch == 'P' && pos == 0)
                pos = 1;
            else if (ch == 'T' && pos == 1)
                pos = 2;
            else
                break;
        }

        if (ch == '\n' && pos == 2 && count[1] && count[2] == count[1] * count[0])
            puts("YES");
        else
            puts("NO");

        if (ch != '\n')
            while (getchar() != '\n');
    }
    return 0;
}