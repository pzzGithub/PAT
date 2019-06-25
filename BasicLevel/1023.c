#include <stdio.h>
#include <stdlib.h>

int main() {
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
        scanf("%d", &count[i]);
    for (int i = 1; i < 10; i++) {
        if (count[i] != 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] != 0) {
            while (count[i] > 0) {
                printf("%d", i);
                count[i]--;
            }
        }
    }
    return 0;
}