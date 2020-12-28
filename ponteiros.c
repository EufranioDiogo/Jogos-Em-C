#include <stdio.h>

int main() {
    /*
    int valor = 10;
    int* pointer = &valor;
    int* pointerOfPointer = pointer;

    printf("Valor: %d\n", valor);
    printf("Valor Pointer: %d\n", *pointer);
    printf("Valor of pointerOfPointer: %d\n", *pointerOfPointer);

    *pointerOfPointer = 2;

    printf("\nmemory address of Valor: %p\n", &valor);
    printf("memory address saved at pointer: %p\n", pointer);

    printf("\n\nmemory address of the pointer: %p\n", &pointer);
    printf("\n-----------------------------------");
    printf("\nValor: %d\n", valor);
    printf("Valor Pointer: %d\n", *pointer);
    printf("Valor of pointerOfPointer: %d\n", *pointerOfPointer);*/

    int linha = 2;
    int coluna = 3;
    int matriz[linha][coluna];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            **(matriz + (i * coluna) + j) = 1;
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", **(matriz + (i * coluna) + j));
        }
        printf("\n");
    }

/*
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", **(matriz + (i * j + j) + sizeof(int*)));
        }
        printf("\n");
    }*/
    /*
    int vector[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vector[i] = i + 1;
    }

    printf("\nBase address of the array %p", vector);
    if ((vector + 4) == &vector[4]) {
        printf("\nÉ verdade: (vector + i) == &vector[i]\n");
    }
    int* pointer = vector; 

    printf("\nPointer address: %p \nAddress of the last pos of the array: %p\n", pointer, &vector);
    pointer++;
    *pointer = 3;
    printf("\nPointer address: %p \nAddress of the last pos of the array: %p", pointer, &vector);

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vector + i));
    }*/

}