//
// Created by 44811 on 12/29/2019.
//

#include <stdio.h>

typedef struct Currency {
    int galleon;
    int sickle;
    int knut;
} currency;

int main() {
    int tag = 1;
    currency P, A;
    scanf("%d.%d.%d %d.%d.%d", &P.galleon, &P.sickle, &P.knut, &A.galleon, &A.sickle, &A.knut);
    int change = (A.galleon * 17 + A.sickle) * 29 + A.knut - (P.galleon * 17 + P.sickle) * 29 - P.knut;
    if (change < 0) {
        change = -change;
        tag = -1;
    }
    currency changeCurrency;
    changeCurrency.knut = change % 29;
    change /= 29;
    changeCurrency.sickle = change % 17;
    change /= 17;
    changeCurrency.galleon = change;
    if (tag < 0)
        printf("-%d.%d.%d", changeCurrency.galleon, changeCurrency.sickle, changeCurrency.knut);
    else
        printf("%d.%d.%d", changeCurrency.galleon, changeCurrency.sickle, changeCurrency.knut);
    return 0;
}