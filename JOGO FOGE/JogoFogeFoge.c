#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

typedef mapa Mapa;
Mapa m;


int main() {
    FILE* ficheiro;

    ficheiro = fopen("mapaFoge.txt", "r");

    if (ficheiro != 0) {
        

        lerMapa(ficheiro, m);

        do {
            imprimeMapa(m);

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

void lerMapa(FILE* ficheiro, mapa m) {
    fscanf(ficheiro, "%d %d", &m.linhas, &m.colunas);
    alocaMapa(m);
    processarMapa(ficheiro, );
    fclose(ficheiro);
}

void processarMapa(FILE* ficheiro, mapa m) {
    for (int i = 0; i < m.linhas; i++) {
        fscanf(ficheiro, "%s", m.matriz[i]);
    }
}