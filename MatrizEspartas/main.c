#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz A, B, C, D;

    const char *nomeArquivoA = "matriz_A.txt";
    const char *nomeArquivoB = "matriz_B.txt";

    FILE *arquivoA = fopen(nomeArquivoA, "r");
    FILE *arquivoB = fopen(nomeArquivoB, "r");

    if (arquivoA == NULL) {
        perror("houve um erro ao tentar abrir o arquivo A");
        return 1;
    }

    if (arquivoB == NULL) {
        perror("houve um erro ao tentar abrir o arquivo B");
        fclose(arquivoA); 
        return 1;
    }

    A = leMatriz(arquivoA);
    B = leMatriz(arquivoB);

    printf("matriz A:\n");
    imprimeMatriz(A);

    printf("\nmatriz B:\n");
    imprimeMatriz(B);

    C = somaMatrizes(A, B);

    printf("\nmatriz C (soma da matriz A e B):\n");
    imprimeMatriz(C);

    D = multiplicaMatrizes(A, B);

    printf("\nmatriz D (produto da matriz A e B):\n");
    imprimeMatriz(D);

    fclose(arquivoA);
    fclose(arquivoB);

    return 0;
}
