#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularAreaPoligono(Ponto *pontos, int numVertices);
float calcularDistancia(Ponto ponto1, Ponto ponto2);

#endif
