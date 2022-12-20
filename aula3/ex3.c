#include <stdio.h>

int main() {
    int productCode = 0, productQuantity = 0;
    float totalPrice = 0;

    do {
        printf("Digite o código e quantidade do produto no formato código coluna: \n");
        scanf("%d %d", &productCode, &productQuantity);

        switch (productCode) {
            case (1):
                totalPrice += (productQuantity * 2.98);
                break;
            case (2):
                totalPrice += (productQuantity * 4.5);
                break;
            case (3):
                totalPrice += (productQuantity * 9.98);
                break;
            case (4):
                totalPrice += (productQuantity * 4.49);
                break;
            case (5):
                totalPrice += (productQuantity * 6.87);
                break;
            default:
                if (!(productCode == 0 && productQuantity == 0)) {
                    printf("Produto não encontrado! \n");
                }
                break;
        }
    } while ((productCode != 0) && (productQuantity != 0));

    printf("\n");
    printf("Valor total: %.2f \n", totalPrice);

    return 0;
}
