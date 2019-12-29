//
// Created by 44811 on 2019/8/5.
//
#include <stdio.h>

struct fraction {
    long numerator;
    long denominator;
};


//寻找最大公约数
long findGreatestCommonDivisor(long a, long b) {
    long temp;
    while (a != 0) {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

//分数求和
struct fraction calculateSum(struct fraction a, struct fraction b) {
    struct fraction result;
    result.denominator = a.denominator * b.denominator;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    return result;
}

//分数求差
struct fraction calculateDifference(struct fraction a, struct fraction b) {
    b.numerator = -b.numerator;
    return calculateSum(a, b);
}

//分数求积
struct fraction calculateProduct(struct fraction a, struct fraction b) {
    struct fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

//分数求商
struct fraction calculateQuotient(struct fraction a, struct fraction b) {
    long temp = b.numerator;
    b.numerator = b.denominator;
    b.denominator = temp;
    return calculateProduct(a, b);
}

void printFraction(struct fraction fraction) {
    if (fraction.denominator == 0) {
        printf("Inf");
        return;
    }
    int tag = 1;

    if (fraction.numerator < 0) {
        fraction.numerator = -fraction.numerator;
        tag *= -1;
    }
    if (fraction.denominator < 0) {
        fraction.denominator = -fraction.denominator;
        tag *= -1;
    }

    long gcd = findGreatestCommonDivisor(fraction.numerator, fraction.denominator);
    fraction.numerator /= gcd;
    fraction.denominator /= gcd;

    if (tag < 0) printf("(-");
    if (fraction.numerator / fraction.denominator && fraction.numerator % fraction.denominator)
        printf("%ld %ld/%ld", fraction.numerator / fraction.denominator, fraction.numerator % fraction.denominator,
               fraction.denominator);
    else if (fraction.numerator % fraction.denominator)
        printf("%ld/%ld", fraction.numerator % fraction.denominator, fraction.denominator);
    else
        printf("%ld", fraction.numerator / fraction.denominator);
    if (tag < 0) printf(")");
}

int main() {
    struct fraction num1, num2;
    scanf("%ld/%ld %ld/%ld", &num1.numerator, &num1.denominator, &num2.numerator, &num2.denominator);
    struct fraction sum = calculateSum(num1, num2);
    struct fraction difference = calculateDifference(num1, num2);
    struct fraction product = calculateProduct(num1, num2);
    struct fraction quotient = calculateQuotient(num1, num2);
    char op[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        printFraction(num1);
        switch (op[i]) {
            case '+':
                printf(" + ");
                printFraction(num2);
                printf(" = ");
                printFraction(sum);
                break;
            case '-':
                printf(" - ");
                printFraction(num2);
                printf(" = ");
                printFraction(difference);
                break;
            case '*':
                printf(" * ");
                printFraction(num2);
                printf(" = ");
                printFraction(product);
                break;
            case '/':
                printf(" / ");
                printFraction(num2);
                printf(" = ");
                printFraction(quotient);
                break;
        }
        printf("\n");
    }
    return 0;
}
