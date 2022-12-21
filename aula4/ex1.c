#include <stdio.h>
#include <string.h>

int main() {
    char names[100][100];
    long rgArray[100];
    int i = 0, op = 0, searchRg = 0, rgIndex = 101;
    char *p;

    do {
        printf("Digite o nome: \n");
        fgets(names[i], sizeof(names), stdin);
        printf("Digite o cpf: \n");
        scanf("%d", &rgArray[i]);
        i++;
        printf("Digite 1 para continuar e 0 para sair. \n");
        scanf("%d", &op);
        while (getchar() != '\n')
            ;
    } while (op != 0);

    printf("Digite o número do RG para busca: \n");
    scanf("%d", &searchRg);

    for (int i = 0; i <= 99; i++) {
        if (searchRg == rgArray[i]) {
            rgIndex = i;
            break;
        }
    }

    if (rgIndex != 101) {
        printf("Nome vinculado ao RG: ");
        puts(names[rgIndex]);
    } else {
        printf("Nome não encontrado!");
    }

    return 0;
}
