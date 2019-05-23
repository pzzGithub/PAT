//
// Created by 44811 on 2019/5/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[60], str2[60], str3[60], str4[60];
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);
    int len1, len2, len3, len4;
    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);
    len4 = strlen(str4);
    int count = 0;
    for (int i = 0; i < (len1 < len2 ? len1 : len2); ++i) {
        if (str1[i] == str2[i]) {
            if (count == 0 && str1[i] >= 'A' && str1[i] <= 'G') {
                count++;
                switch (str1[i]) {
                    case 'A':
                        printf("MON ");
                        break;
                    case 'B':
                        printf("TUE ");
                        break;
                    case 'C':
                        printf("WED ");
                        break;
                    case 'D':
                        printf("THU ");
                        break;
                    case 'E':
                        printf("FRI ");
                        break;
                    case 'F':
                        printf("SAT ");
                        break;
                    case 'G':
                        printf("SUN ");
                        break;
                }
            } else if (count != 0) {
                if ('0' <= str1[i] && str1[i] <= '9') {
                    printf("0%d:", str1[i] - '0');
                    break;
                } else if (str1[i] >= 'A' && str1[i] <= 'N') {
                    printf("%d:", str1[i] - 'A' + 10);
                    break;
                }
            }
        }
    }
    for (int j = 0; j < (len3 < len4 ? len3 : len4); ++j) {
        if (str3[j] == str4[j] && ((str3[j] >= 'a' && str3[j] <= 'z') || (str3[j] >= 'A' && str3[j] <= 'Z'))) {
            if (j >= 0 && j <= 9)
                printf("0");
            printf("%d", j);
            break;
        }
    }
    return 0;
}