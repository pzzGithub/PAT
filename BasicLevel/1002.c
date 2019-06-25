#include <stdio.h>

int main() {
    char num[100];
    while (scanf("%s", num) != EOF) {
        int sum = 0;
        int i = 0;
        while (1) {
            if (num[i] == '\0')
                break;
            else {
                sum += num[i] - '0';
                i++;
            }
        }
        char *pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
        if (sum / 100)
            printf("%s ", pinyin[sum / 100]);
        if (sum / 10)
            printf("%s ", pinyin[sum / 10 % 10]);
        printf("%s", pinyin[sum % 10]);
    }
    return 0;
}