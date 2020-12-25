#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HeaderJogoDaForca.h"
#define LIMITE_JOGADAS 5

int main() {
    int acertou = 0, enforcou = 0;
    char palavraSecreta[20];
    int indexLetrasReveladas[20];
    char letraChutada;
    int letraChutadaAcertada = 0;
    int quantErros = 0;
    int quantLetrasAcertadas = 0;
    FILE* ficheiro;

    ficheiro = fopen("JogoForcaBaseDeDados.txt", "r");

    if (ficheiro != 0) {
        escolhaPalavra(palavraSecreta, ficheiro);
        inicializarIndexLetrasReveladas(indexLetrasReveladas, palavraSecreta);
        abertura();

        do {
            leituraDaEntradaDoUsuario(&letraChutada);

            verificarLetraChutadaEmPalavraSecreta(palavraSecreta, indexLetrasReveladas, letraChutada, &quantLetrasAcertadas, &letraChutadaAcertada);
            verificarSeAcertou(letraChutadaAcertada, letraChutada);
            verificarSeVenceu(quantLetrasAcertadas, palavraSecreta, &acertou);
            verificarSeErrou(letraChutadaAcertada, &quantErros, letraChutada);
            imprimirPalavraSecreta(palavraSecreta, indexLetrasReveladas);
            verificarSePerdeu(quantErros, &enforcou);
            desenharForca(quantErros);
            printf("\n");
            letraChutadaAcertada = 0;
        } while (!acertou && !enforcou);

        if (acertou) {
            imprimirTrofeu();
        } else {
            imprimirCaveira(palavraSecreta);
        }
        if (acertou) {
            adicionarNovaPalavra(ficheiro);
        }
    } else {
        printf("\nAlgum erro ocorreu na abertura do ficheiro de base de dados.\nTERMINANDO PROGRAMA...");
        exit(1);
    }
    return 0;
}

void imprimirTrofeu() {

}


void imprimirCaveira(char palavraSecreta[]) {
    
}



void desenharForca(int quantErros) {
    printf("\n\n");
    printf(" _______ \n");
    printf(" |/    | \n");
    printf(" |    %c%c%c  \n", (quantErros >= 1 ? '(' : ' '),
    (quantErros >= 1 ? '_' : ' '),
    (quantErros >= 1 ? ')' : ' '));
    printf(" |    %c%c%c\n", (quantErros >= 2 ? '\\' : ' '),
    (quantErros >= 2 ? '|' : ' '),
    (quantErros >= 2 ? '/' : ' '));
    printf(" |     %c\n", (quantErros >= 3 ? '|' : ' '));
    printf(" |     %c\n", (quantErros >= 4 ? '|' : ' '));
    printf(" |    %c %c\n", (quantErros >= 5 ? '/' : ' '),
    (quantErros >= 5 ? '\\' : ' '));
    printf("_|___");
}


void adicionarNovaPalavra(FILE* ficheiro) {
    int desejaAdicionarPalavra = 0;

    printf("Deseja adicionar uma palavra na base de dados? (1) Sim, (2) Não: ");
    scanf("%d", &desejaAdicionarPalavra);

    if (desejaAdicionarPalavra != 0) {
        char novaPalavra[35];
        char palavraAux[35];
        int palavraExiste = 0;

        while (!palavraExiste) {
            printf("\nDigite a nova palavra(TODAS AS LETRAS EM MAÍUSCULA): ");
            scanf("%s", novaPalavra);

            ficheiro = fopen("JogoForcaBaseDeDados.txt", "r");

            if (ficheiro != 0) {
                int quantPalavras;

                fscanf(ficheiro, "%d", &quantPalavras);

                while (quantPalavras > 0) {

                    fscanf(ficheiro, "%s", palavraAux);

                    if (strlen(palavraAux) == strlen(novaPalavra)) {
                        palavraExiste = 1;

                        for (int i = 0; palavraAux[i] != '\0'; i++) {
                            if (palavraAux[i] != novaPalavra[i]) {
                                palavraExiste = 0;
                                break;
                            }
                        }
                        if (palavraExiste == 1) {
                            break;
                        }
                    }
                    quantPalavras--;
                }

                fclose(ficheiro);

                if (palavraExiste == 1) {
                    printf("A palavra %s já existe\nTENTE OUTRA VEZ\n", novaPalavra);
                    palavraExiste = 0;
                } else {
                    ficheiro = fopen("JogoForcaBaseDeDados.txt", "a");
                    fprintf(ficheiro, "\n%s", novaPalavra);
                    fclose(ficheiro);
                    aumentarNumeroDePalavrasNoBanco(ficheiro);
                    palavraExiste = 1;
                }
            } else {
                printf("Problema na abertura do programa.");
                exit(1);
            }
        }
    } else {
        printf("\nBeleza a gente se vê por aí.");
    }
}


void aumentarNumeroDePalavrasNoBanco(FILE* ficheiro) {
    ficheiro = fopen("JogoForcaBaseDeDados.txt", "r+");

    if (ficheiro != 0) {
        int quantidadeDePalavras;

        fscanf(ficheiro, "%04d", &quantidadeDePalavras);
        quantidadeDePalavras += 1;
        fseek(ficheiro, 0, 0);
        fprintf(ficheiro, "%d\n", quantidadeDePalavras);
        fclose(ficheiro);
    } else {
        printf("\nErro abrindo o ficheiro");
        exit(1);
    }
}

void verificarSeAcertou(int letraChutadaAcertada, char letraChutada) {
    if (letraChutadaAcertada == 1) {
        printf("Você acertou: a palavra tem a letra %c\n\n", letraChutada);
    }
}

void verificarLetraChutadaEmPalavraSecreta(char palavraSecreta[], int indexLetrasReveladas[], char letraChutada, int* quantLetrasAcertadas, int* letraChutadaAcertada) {

    for(int i = 0; palavraSecreta[i] != '\0'; i++) {
        if (palavraSecreta[i] == letraChutada) {
            if (indexLetrasReveladas[i] != i) {
                indexLetrasReveladas[i] = i;
                *quantLetrasAcertadas = *quantLetrasAcertadas + 1;
            }
            *letraChutadaAcertada = 1;
        }
    }
}


void verificarSeVenceu(int quantLetrasAcertadas, char palavraSecreta[], int* acertou) {
    if (quantLetrasAcertadas == strlen(palavraSecreta)) {
        *acertou = 1;
    }
}


void verificarSeErrou(int letraChutadaAcertada, int* quantErros, char letraChutada) {
    if (letraChutadaAcertada == 0) {
        *quantErros = *quantErros + 1;
        printf("\nVocê errou: a palavra NÃO tem a letra %c\nQuant erros: %d\n\n", letraChutada,*quantErros);
    }
}


void imprimirPalavraSecreta(char palavraSecreta[], int indexLetrasReveladas[]) {
    for (int j = 0; palavraSecreta[j] != '\0'; j++) {
        if (j == indexLetrasReveladas[j]) {
            printf("%c ", palavraSecreta[j]);
        } else {
            printf("_ ");
        }
    }
}


void verificarSePerdeu(int quantErros, int* enforcou) {
    if (quantErros >= LIMITE_JOGADAS) {
        printf("\nVocê Perdeu o Jogo;\n");
        *enforcou = 1;
    }
}

void leituraDaEntradaDoUsuario(char* letraChutada) {
    printf("\nChute uma letra: ");
    scanf(" %c", letraChutada);

    while (*letraChutada < 65 || *letraChutada > 90) {
        printf("\nChute uma letra(MAIUSCULA): ");
        scanf(" %c", letraChutada);
    }
}

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}


void escolhaPalavra(char palavraSecreta[], FILE* ficheiro) {
    int quantPalavrasNoFicheiro;

    fscanf(ficheiro, "%d", &quantPalavrasNoFicheiro);

    srand(time(NULL));
    int palavraSorteada = rand() % (quantPalavrasNoFicheiro - 0 + 1) + 0;

    while (palavraSorteada) {
        fscanf(ficheiro, "%s", palavraSecreta);
        palavraSorteada--;
    }

    fclose(ficheiro);
}


void inicializarIndexLetrasReveladas(int indexLetrasReveladas[], char palavraSecreta[]) {
    for (int i = 0; palavraSecreta[i] != '\0'; i++) {
        indexLetrasReveladas[i] = -1;
    }
}