#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void alocaMapa(mapa m) {
    m.matriz = malloc(sizeof(char*) * m.linhas);

    for (int i = 0; i < m.linhas; i++) {
        *(m.matriz + i) = malloc(sizeof(char) * m.colunas + 1);
    }
}

void liberarMapa(mapa m) {
    for (int i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void imprimeMapa(mapa m) {
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}
