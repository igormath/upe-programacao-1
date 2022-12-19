#include <stdio.h>

int main() {
    int number1 = 0, number2 = 0, number3 = 0, number4 = 0, number5 = 0;

    printf("Digite o primeiro número: \n");
    scanf("%d", &number1);
    printf("Digite o segundo número: \n");
    scanf("%d", &number2);
    printf("Digite o terceiro número: \n");
    scanf("%d", &number3);
    printf("Digite o quarto número: \n");
    scanf("%d", &number4);
    printf("Digite o quinto número: \n");
    scanf("%d", &number5);

    for (int i = 1; i <= number1; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i <= number2; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i <= number3; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i <= number4; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i <= number5; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}
