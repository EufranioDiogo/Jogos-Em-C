#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMITE_TENTATIVAS_JOGADAS 6

int main() {
    int numerSorteado = -1;
    int limiteSuperiorSorteio = -1;
    int limiteInferiorSorteio = 1;
    int quantTentativasJogadas = 1;
    int numeroChutado = 0;
    int numeroChutadoAnterior = -1;


    printf("       P /_\\ P\n");
    printf("     /_\\_|_|_/_\\ \n");
    printf(" n_n | ||. .|| | n_n \tBem-vindo ao\n");
    printf(" |_|_|nnnn nnnn|_|_| \tJogo da Advinhação!\n");
    printf("|\"  \" |  |_|  |\"  \" |\n");
    printf("|_____| ' _ ' |_____|\n");
    printf("      \\__|_|__/\n");

    printf("Defina o seu limite Inferior: ");
    scanf("%d", &limiteInferiorSorteio);
    
    while(limiteSuperiorSorteio <= limiteInferiorSorteio) {
        printf("\nDefina o seu limite Superior: ");
        scanf("%d", &limiteSuperiorSorteio);
        if (limiteSuperiorSorteio <= limiteInferiorSorteio) {
            printf("\nDefina um limite superior maior que %d", limiteInferiorSorteio);
        }
    }

    int querContinuarJogar = 1;

    while (querContinuarJogar) {
        srand(time(NULL));
        numerSorteado = rand() % (limiteSuperiorSorteio - limiteInferiorSorteio + 1) + limiteInferiorSorteio;

        while (quantTentativasJogadas <= LIMITE_TENTATIVAS_JOGADAS && numerSorteado != numeroChutado) {
        printf("\n-> Tentativa %d de %d\n", quantTentativasJogadas, LIMITE_TENTATIVAS_JOGADAS);
        printf("Chute um número: ");
        scanf("%d", &numeroChutado);

        while (numeroChutado == numeroChutadoAnterior) {
            printf("Digite um número diferente que %d porque já foi sorteado anteriormente", numeroChutadoAnterior);
            scanf("%d", &numeroChutado);
        }

        if (numeroChutado <= 0) {
            printf("\nVocê não pode chutar números negativos ou igual a 0\n");
            continue;
        }

        int acertou = numeroChutado == numerSorteado;

        if (acertou) {
            printf("\n\nVocê Vênceu Parabéns!\nNúmero sorteado = %d, Número Chutado = %d\n", numerSorteado, numeroChutado);
            break;
        } else {
            numeroChutadoAnterior = numeroChutado;
            int descer = numeroChutado > numerSorteado;

            if (descer) {
                printf("\nTenta descer mais\n");
            } else {
                printf("\nTenta subir mais\n");
            }
        }
        quantTentativasJogadas++;
        }

        if (quantTentativasJogadas > LIMITE_TENTATIVAS_JOGADAS) {
            printf("Você vacilou cara, perdeu o jogo!\n");
        } else {
            printf("              OOOOOOOOOOO\n");
            printf("          OOOOOOOOOOOOOOOOOOO\n");
            printf("        OOOOOO OOOOOOOOO OOOOOO\n");
            printf("      OOOOOO     OOOOO     OOOOOO\n");
            printf("    OOOOOOOO  #  OOOOO  #  OOOOOOOO\n");
            printf("   OOOOOOOOOO   OOOOOOO   OOOOOOOOOO\n");
            printf("  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
            printf("  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
            printf("  OOOO OOOOOOOOOOOOOOOOOOOOOOOOO OOOO\n");
            printf("   OOOO OOOOOOOOOOOOOOOOOOOOOOO OOOO\n");
            printf("    OOOO OOOOOOOOOOOOOOOOOOOO OOOO\n");
            printf("      OOOOO OOOOOOOOOOOOOOO OOOO\n");
            printf("        OOOOOO OOOOOOOOO OOOOOO\n");
            printf("         OOOOOO         OOOOOO\n");
            printf("              OOOOOOOOOOO\n");
            printf("\n");
        }
        printf("\nQuer continuar a jogar? (1) Sim, (0) Não: ");
        scanf("%d", &querContinuarJogar);

        if (querContinuarJogar == 0) {
            printf("Jogo terminado");
            break;
        }

        quantTentativasJogadas = 1;
        numeroChutadoAnterior = -1;
        numeroChutado = 0;
        limiteInferiorSorteio = 1;
        limiteSuperiorSorteio = -1;


        printf("Defina o seu limite Inferior: ");
        scanf("%d", &limiteInferiorSorteio);
        

        while(limiteSuperiorSorteio <= limiteInferiorSorteio) {
            printf("\nDefina o seu limite Superior: ");
            scanf("%d", &limiteSuperiorSorteio);
            if (limiteSuperiorSorteio <= limiteInferiorSorteio) {
                printf("\nDefina um limite superior maior que %d", limiteInferiorSorteio);
            }
        }
    }
    printf("\n");

    

    return 0;
}