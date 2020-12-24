#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE_JOGADAS 5

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

int main() {
    int acertou = 0, enforcou = 0;
    char palavraSecreta[] = {'M', 'E', 'L', 'A', 'N', 'C', 'I', 'A'};
    int indexRevelados[] = {-1, -1, -1, -1, -1, -1, -1, -1};
    char letraChutada;
    int letraChutadaAcertada = 0;
    int quantPerdidas = 0;
    int quantLetrasAcertadas = 0;

    abertura();

    do {
        printf("\nChute uma letra: ");
        scanf(" %c", &letraChutada);

        for(int i = 0; palavraSecreta[i] != '\0'; i++) {
            if (palavraSecreta[i] == letraChutada) {
                if (indexRevelados[i] != i) {
                    indexRevelados[i] = i;
                    quantLetrasAcertadas++;
                }
                letraChutadaAcertada = 1;
            }
        }

        if (quantLetrasAcertadas == strlen(palavraSecreta)) {
            acertou = 1;
        }

        if (letraChutadaAcertada == 0) {
            quantPerdidas++;
            printf("ERROU\nJá Errou: %d vez(es)\n", quantPerdidas);
        }

        for (int j = 0; palavraSecreta[j] != '\0'; j++) {
            if (j == indexRevelados[j]) {
                printf(" %c ", palavraSecreta[j]);
            } else {
                printf("_ ");
            }
        }

        if (quantPerdidas >= LIMITE_JOGADAS) {
            printf("\nVocê Perdeu o Jogo;\n");
            enforcou = 1;
        }

        printf("\n");
        letraChutadaAcertada = 0;
    } while (!acertou && !enforcou);


    return 0;
}