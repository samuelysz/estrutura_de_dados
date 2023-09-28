#include "ponto.h"
#include <math.h>

float calcularAreaPoligono(Ponto *pontos, int numVertices) {
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        Ponto pontoAtual = pontos[i];
        Ponto proximoPonto = pontos[(i + 1) % numVertices]; 

        area += (pontoAtual.X * proximoPonto.Y) - (pontoAtual.Y * proximoPonto.X);
    }

    return fabs(area) / 2.0;
}

float calcularDistancia(Ponto ponto1, Ponto ponto2) {
    return sqrt(pow((ponto2.X - ponto1.X), 2) + pow((ponto2.Y - ponto1.Y), 2));
}
