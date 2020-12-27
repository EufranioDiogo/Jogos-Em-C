#include <stdio.h>
#include <stdlib.h>
#include "HeaderJogoFoge.h"
#define LINHAS 5
#define COLUNAS 10
char** mapa;
int linhas;
int colunas;

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

        } while (!acabou())

        liberarMapa();
    } else {
        printf("Erro abrindo o ficheiro Mapa do jogo foge\nNome: mapaFoge.txt");
        exit(1);
    }
    

    return 0;
}


void lerMapa(FILE* ficheiro) {
    fscanf(ficheiro, "%d %d", &linhas, &colunas);
    alocaMapa(linhas, colunas);
    processarMapa(ficheiro, linhas);
    fclose(ficheiro);
}

void alocaMapa() {
    mapa = malloc(sizeof(char*) * linhas);

    for (int i = 0; i < linhas; i++) {
        *(mapa + i) = malloc(sizeof(char) * colunas + 1);
    }
}

void processarMapa(FILE* ficheiro) {
    for (int i = 0; i < linhas; i++) {
        fscanf(ficheiro, "%s", mapa[i]);
    }
}

void liberarMapa() {
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

void imprimeMapa() {
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }
}

void acabou() {
    return 0;
}

void move(char comando) {
    int x;
    int y;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == '@') {
                y = i;
                x = j;
                break;
            }
        }
    }

    switch(comando) {
        case 'w':
            mapa[y - 1][x] = '@';
            break;
        case 'a':
            mapa[y][x - 1] = '@';
            break;
        case 's':
            mapa[y + 1][x] = '@';
            break;
        case 'd':
            mapa[y][x + 1] = '@';
            break;
        default:
            mapa[y][x] = ' ';
            break;
    }
}