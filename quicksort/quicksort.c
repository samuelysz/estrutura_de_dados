#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0;
    int trocas = 0;

    printf("Vetor de entrada:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n\n");

    qsort(arr, n, sizeof(char *), compare);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    printf("\nNumero de comparacoes: %d\n", comparacoes);
    printf("Numero de trocas: %d\n", trocas);

    const char *mediana = arr[n / 2];
    printf("\nMediana: %s\n", mediana);

    FILE *arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de saída");
        return 1;
    }

    fprintf(arquivo, "Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%s ", arr[i]);
    }
    fprintf(arquivo, "\n");
    fprintf(arquivo, "Numero de comparacoes: %d\n", comparacoes);
    fprintf(arquivo, "Numero de trocas: %d\n", trocas);
    fprintf(arquivo, "Mediana: %s\n", mediana);

    fclose(arquivo);

    return 0;
}
