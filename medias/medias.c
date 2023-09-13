#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_TELEFONE 20
#define MAX_CURSO 100

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    char linha[1000];
    int contadorAlunos = 0; 

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[MAX_NOME], telefone[MAX_TELEFONE], curso[MAX_CURSO];
        double nota1, nota2;

        char *token = strtok(linha, ",");
        
        if (token == NULL) {
            fprintf(stderr, "Erro ao ler dados da linha\n");
            continue;
        }
        strcpy(nome, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Erro ao ler dados da linha\n");
            continue;
        }
        strcpy(telefone, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Erro ao ler dados da linha\n");
            continue;
        }
        strcpy(curso, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Erro ao ler dados da linha\n");
            continue;
        }
        nota1 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Erro ao ler dados da linha\n");
            continue;
        }
        nota2 = atof(token);

        double media = (nota1 + nota2) / 2.0;

        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        fprintf(saida, "%s,%.2lf,%s\n", nome, media, situacao);

        contadorAlunos++; 
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento finalizado. Total de %d alunos processados.\n", contadorAlunos);

    return 0;
}