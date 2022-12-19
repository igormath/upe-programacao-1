#include <stdio.h>

int main() {
    int numberOfLines = 0;

    printf("Digite o numero de linhas desejado: \n");
    scanf("%d", &numberOfLines);

    for (int i = 1; i <= numberOfLines; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (int k = 1; k <= numberOfLines; k++) {
        for (int l = numberOfLines; l >= k; l--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
