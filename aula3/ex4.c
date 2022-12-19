#include <stdio.h>

int main() {
    int withdrawValue = 0, leftover = 0;
    int count50 = 0, count20 = 0, count10 = 0, count5 = 0, count1 = 0;

    printf("Digite um valor para saque: \n");
    scanf("%d", &withdrawValue);

    do {
        if (withdrawValue >= 50) {
            leftover = withdrawValue - 50;
            count50++;
        } else if (withdrawValue >= 20) {
            leftover = withdrawValue - 20;
            count20++;
        } else if (withdrawValue >= 10) {
            leftover = withdrawValue - 10;
            count10++;
        } else if (withdrawValue >= 5) {
            leftover = withdrawValue - 5;
            count5++;
        } else if (withdrawValue >= 1) {
            leftover = withdrawValue - 1;
            count1++;
        }
        withdrawValue = leftover;

    } while (leftover != 0);

    printf("Valor lido: %d \n", withdrawValue);
    printf("Cédulas: \n");
    if (count50 != 0) {
        printf("    %d de R$ 50 \n", count50);
    }
    if (count20 != 0) {
        printf("    %d de R$ 20 \n", count20);
    }
    if (count10 != 0) {
        printf("    %d de R$ 10 \n", count10);
    }
    if (count5 != 0) {
        printf("    %d de R$ 5 \n", count5);
    }
    if (count1 != 0) {
        printf("    %d de R$ 1 \n", count1);
    }

    return 0;
}
