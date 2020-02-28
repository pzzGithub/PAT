//
// Created by 44811 on 2020/1/30.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct formula {
    int exponent;
    float coefficient;
} formula;

int main() {
    int n1, n2;
    formula *polynomials1, *polynomials2;
    scanf("%d", &n1);
    polynomials1 = (formula *) malloc(sizeof(formula) * n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d %f", &polynomials1[i].exponent, &polynomials1[i].coefficient);
    }
    scanf("%d", &n2);
    polynomials1 = (formula *) malloc(sizeof(formula) * n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d %f", &polynomials2[i].exponent, &polynomials2[i].coefficient);
    }
    printf("%d %d", n1, n2);
    return 0;
}