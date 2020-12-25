#include <stdio.h>

int main() {
    int c = 10;
    int* ponteiro;

    ponteiro = &c;

    printf("Ponteiro: %d, C:", *ponteiro);
    return 0;
}