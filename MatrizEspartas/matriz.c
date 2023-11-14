#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz criaMatriz(int nlin, int ncol) {
    Matriz matriz;
    matriz.cabeca = (Celula *)malloc(sizeof(Celula));
    matriz.cabeca->linha = -1;
    matriz.cabeca->coluna = -1;
    matriz.nlin = nlin;
    matriz.ncol = ncol;
    matriz.cabeca->direita = matriz.cabeca;
    matriz.cabeca->abaixo = matriz.cabeca;
    return matriz;
}

void insere(Matriz *matriz, int linha, int coluna, float valor) {

    if (linha < 0 || linha >= matriz->nlin || coluna < 0 || coluna >= matriz->ncol) {
        printf("As coordenadas estao fora dos limites da matriz. Linha: %d, Coluna: %d\n", linha, coluna);
        printf("Os limites da matriz sao: Linhas: 0 a %d, Colunas: 0 a %d\n", matriz->nlin - 1, matriz->ncol - 1);
        exit(1);
    }


    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));

    if (novaCelula == NULL) {
        printf("Falha na alocação de memória, o valor esta NULL.\n");
        exit(1);
    }

    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;

    Celula *atual = matriz->cabeca;
    while (atual->direita != matriz->cabeca && atual->direita->coluna < coluna) {
        atual = atual->direita;
    }

    while (atual->abaixo != matriz->cabeca && atual->abaixo->linha < linha) {
        atual = atual->abaixo;
    }

    novaCelula->direita = atual->direita;
    atual->direita = novaCelula;

    novaCelula->abaixo = atual->abaixo;
    atual->abaixo = novaCelula;
}

float buscaValor(Matriz M, int linha, int coluna) {
    Celula *atual = M.cabeca->direita;

    while (atual != M.cabeca) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->valor;
        }
        atual = atual->direita;
    }

    return 0.0;
}

void imprimeMatriz(Matriz A) {
    for (int i = 0; i < A.nlin; i++) {
        for (int j = 0; j < A.ncol; j++) {
            Celula *atual = A.cabeca->direita;

            printf("%.2f ", buscaValor(A, i, j));

            if (atual == A.cabeca) {
                printf("0.00 ");
            }
            
        }
        printf("\n");
    }
}

Matriz leMatriz(FILE *arquivo) {
    int nlin, ncol;
    fscanf(arquivo, "%d, %d\n", &nlin, &ncol);
    Matriz matriz = criaMatriz(nlin, ncol);

    int linha, coluna;
    float valor;

    while (fscanf(arquivo, "%d, %d, %f", &linha, &coluna, &valor) == 3) {
        // printf("Linha %d, Coluna %d, Valor %.2f\n", linha, coluna, valor);
        insere(&matriz, linha, coluna, valor);
    }

    return matriz;
}

Matriz somaMatrizes(Matriz A, Matriz B) {

    if (A.nlin != B.nlin || A.ncol != B.ncol) {
        printf("As dimensões das matrizes são distintas. Ajuste e tente novamente.\n");
        exit(1);
    }

    Matriz C = criaMatriz(A.nlin, A.ncol);

    for (int i = 0; i < A.nlin; i++) {
        for (int j = 0; j < A.ncol; j++) {
            float valorA = 0, valorB = 0;

            valorA = buscaValor(A, i, j);

            valorB = buscaValor(B, i, j);

            if (valorA != 0 || valorB != 0) {
                insere(&C, i, j, valorA + valorB);
            }
            
        }
    }
    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    if (A.ncol != B.nlin) {
        printf("Para realizar a multiplicação de matrizes, o número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz. Ajuste e tente novamente.\n");
        exit(1);
    }

    Matriz C = criaMatriz(A.nlin, B.ncol);

    for (int i = 0; i < A.nlin; i++) {
        for (int j = 0; j < B.ncol; j++) {
            float valor = 0;

            for (int k = 0; k < A.ncol; k++) {

                float valorA = buscaValor(A, i, k);

                float valorB = buscaValor(B, k, j);

                valor += valorA * valorB;
            }
            
            if(valor != 0) {
                insere(&C, i, j, valor);
            }
            
        }
    }

    return C;
}