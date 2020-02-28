//
// Created by 44811 on 2020/1/6.
//

#include <stdio.h>

int main() {
    char *int2en[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char nums[101];
    int sum = 0, sumNum[3] = {0}, length = 0;
    scanf("%s", nums);
    for (int i = 0;; i++) {
        if (nums[i] == '\0')
            break;
        sum += nums[i] - '0';
    }
    for (int i = 0; sum % 10 != 0; i++) {
        sumNum[i] = sum % 10;
        sum /= 10;
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        printf("%s", int2en[sumNum[i]]);
        i == 0 ?: printf(" ");
    }

    return 0;
}