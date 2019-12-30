//
// Created by 44811 on 12/29/2019.
//

#include <stdio.h>
#include <string.h>

int main() {
    int count[128] = {0};
    char ch;
    char str1[1000], str2[1000];
    scanf("%s", str1);
    scanf("%s", str2);
    for (int i = 0; i < strlen(str1); i++)
        count[str1[i]]++;
    for (int i = 0; i < strlen(str2); i++)
        count[str2[i]]--;
    int sum1 = 0, sum2 = 0, tag = 1;
    for (int i = 0; i < 128; i++) {
        if (count[i] > 0 && tag == 1)
            sum1 += count[i];
        else if (tag == 1 && count[i] < 0) {
            tag = -1;
            sum2 += count[i];
        } else if (tag != 1 && count[i] < 0)
            sum2 += count[i];
    }
    if (tag == 1)
        printf("Yes %d", sum1);
    else
        printf("No %d", -sum2);
    return 0;
}