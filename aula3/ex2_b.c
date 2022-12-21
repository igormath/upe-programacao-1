#include <stdio.h>

int main() {
    int numbers[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o número %d \n", (i + 1));
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numbers[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
