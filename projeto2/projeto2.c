#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct EpidemicData {
    long registerDate;
    long cases;
    int cityCode;
    int stateCode;
    struct EpidemicData *pointer_;
};

struct EpidemicData *list = NULL;  // Inicia o comeco da lista em nulo (cria uma lista vazia)

int addFinalList(struct EpidemicData item);

int addFinalList(struct EpidemicData item) {  // Add uma nova struct no fim da lista dinamica
    struct EpidemicData *newNode = malloc(sizeof(struct EpidemicData));

    if (newNode != NULL) {
        *newNode = item;
        newNode->pointer_ = NULL;

        if (list == NULL) {
            list = newNode;
        } else {
            struct EpidemicData *currentNode = NULL;

            currentNode = list;
            while (currentNode->pointer_ != NULL) {
                currentNode = currentNode->pointer_;
            }

            currentNode->pointer_ = newNode;
        }

        return 1;
    } else {
        return 0;
    }
}

long timeNowEpoch() {  // Obtem o horario atual e retorna este convertido em Epoch
    time_t now;
    time(&now);
    return now;
}

void readCsv(char fileName[]) {  // Le o arquivo fonte externo.
    FILE *sourceCsv = fopen(fileName, "r");
    FILE *historyOutput = fopen("historico_cargas.csv", "a");
    struct EpidemicData *currentNode = list;
    long loadDate = timeNowEpoch();  // DataCarga pedido. criado antes das escritas para padronizar o valor recebido na funcao timeNowEpoch().

    if (sourceCsv != NULL && historyOutput != NULL) {
        struct EpidemicData red;

        while (!feof(sourceCsv)) {
            fscanf(sourceCsv, "%ld;%d;%d;%ld\n", &red.registerDate, &red.cityCode, &red.stateCode, &red.cases);
            fprintf(historyOutput, "%ld;%d;%d;%ld;%ld\n", red.registerDate, red.cityCode, red.stateCode, red.cases, loadDate);

            int foundDummy = 0;

            while (currentNode != NULL) {
                if (red.cityCode == currentNode->cityCode && red.stateCode == currentNode->stateCode) {
                    currentNode->cases += red.cases;
                    if (red.registerDate >= currentNode->registerDate) {
                        currentNode->registerDate = red.registerDate;
                    }
                    foundDummy = 1;  // Altera a variavel foundDummy se achar uma ocorrencia do mesmo numero de cidade/estado na lista
                    break;
                }
                currentNode = currentNode->pointer_;
            }

            if (!foundDummy) {  // Caso a varialvel permaneca como foi inicializada ela nao existe na lista, logo um novo no eh criado
                addFinalList(red);
            }

            currentNode = list;
        }

        fclose(sourceCsv);
        fclose(historyOutput);
    } else {
        puts("Nao foi possivel abrir ou escrever o arquivo\n");
    }
}

void writeConsolidatedCsv() {  // Escreve os dados consolidados apos soma das ocorrencias de cidadaes e estados iguais na lista dinamica.
    char fileName[23] = "dados_consolidados.csv";
    FILE *consolidatedOutput = fopen(fileName, "w");
    struct EpidemicData *currentNode = list;

    if (consolidatedOutput != NULL) {
        while (currentNode != NULL) {
            fprintf(consolidatedOutput, "%d;%d;%ld;%ld", currentNode->cityCode, currentNode->stateCode, currentNode->cases, currentNode->registerDate);
            if (currentNode->pointer_ != NULL) {
                fprintf(consolidatedOutput, "\n");
            }
            currentNode = currentNode->pointer_;
        }

        fclose(consolidatedOutput);
        printf("-------------------------\n");
        printf("Arquivo de dados consolidados criado com sucesso!\n");
        printf("-------------------------\n");
    } else {
        puts("ERRO!!! Não foi possivel criar arquivo!\n");
    }
}

void convertEpochTime(long DataRegistro) {  // Recebe uma data em Epoch e converte no formato DD/MM/YYYY.
    time_t now = DataRegistro;
    struct tm ts;
    char buf[80];

    ts = *localtime(&now);

    strftime(buf, sizeof(buf), "%d/%m/%Y", &ts);

    printf("       %s\n", buf);
}

void stateReport(int state) {  // Gera relatorio de acordo com o numero da UF informada.
    long count = 0;
    int dummy = 0;
    struct EpidemicData *currentNode = list;

    while (currentNode != NULL) {
        if (state == currentNode->stateCode) {
            count += currentNode->cases;
            dummy = 1;
        }
        currentNode = currentNode->pointer_;
    }

    currentNode = list;

    if (dummy == 0) {
        printf("Estado não encontrado!\n");
    } else {
        printf("********* RELATÓRIO ESTADUAL **********\n");
        printf("Codigo Estado: %d\n", state);
        printf("Total de casos no estado: %ld casos\n", count);
        printf("CIDADE QTD CASOS    ULTIMA ATUALIZACAO\n");
        printf("--------------------------------------\n");
        while (currentNode != NULL) {
            if (state == currentNode->stateCode) {
                printf("%5d%9ld", currentNode->cityCode, currentNode->cases);
                convertEpochTime(currentNode->registerDate);
            }
            currentNode = currentNode->pointer_;
        }
    }
}

int main(void) {
    int op = -1;
    do {
        int uf;
        char sourcePath[80];
        printf("Escolha uma opcao: \n");
        printf("1 - Fazer uma carga de dados\n");
        printf("2 - Acessar relatorio\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        if (op == 1) {
            printf("Digite o caminho para o arquivo CSV externo: \n");
            scanf("%s", sourcePath);
            readCsv(sourcePath);
            writeConsolidatedCsv();
        } else if (op == 2) {
            printf("Digite o numero da UF:\n");
            scanf("%d", &uf);
            stateReport(uf);
        }
    } while (op != 0);
    return 0;
}
