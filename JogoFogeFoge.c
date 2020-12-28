#include <stdio.h>
#include <stdlib.h>
#include "HeaderJogoFoge.h"
#include "fogefoge.h"
#define LINHAS 5
#define COLUNAS 10

typedef struct mapa MAPA;
MAPA m;


int main() {
    FILE* ficheiro;

    ficheiro = fopen("mapaFoge.txt", "r");

    if (ficheiro != 0) {
        

        lerMapa(ficheiro);

        do {
            imprimeMapa();

            char comando;
            scanf(" %c", &comando);
            move(comando);

        } while (!acabou());

        liberarMapa();
    } else {
        printf("Erro abrindo o ficheiro Mapa do jogo foge\nNome: mapaFoge.txt");
        exit(1);
    }
    

    return 0;
}


void lerMapa(FILE* ficheiro) {
    fscanf(ficheiro, "%d %d", &m.linhas, &m.colunas);
    alocaMapa();
    processarMapa(ficheiro);
    fclose(ficheiro);
}

void alocaMapa() {
    m.matriz = malloc(sizeof(char*) * m.linhas);

    for (int i = 0; i < m.linhas; i++) {
        *(m.matriz + i) = malloc(sizeof(char) * m.colunas + 1);
    }
}

void processarMapa(FILE* ficheiro) {
    for (int i = 0; i < m.linhas; i++) {
        fscanf(ficheiro, "%s", m.matriz[i]);
    }
}

void liberarMapa() {
    for (int i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void imprimeMapa() {
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

int acabou() {
    return 0;
}

void move(char comando) {
    int x;
    int y;
    int letraErrada = 0;

    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            if (m.matriz[i][j] == '@') {
                y = i;
                x = j;
                break;
            }
        }
    }

    switch(comando) {
        case 'w':
            m.matriz[y - 1][x] = '@';
            break;
        case 'a':
            m.matriz[y][x - 1] = '@';
            break;
        case 's':
            m.matriz[y + 1][x] = '@';
            break;
        case 'd':
            m.matriz[y][x + 1] = '@';
            break;
        default:
            letraErrada = 1;
    }
    if (!letraErrada) {
        m.matriz[y][x] = ' ';
    }
}