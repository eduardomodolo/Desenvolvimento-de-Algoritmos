#include <stdio.h>
#include <string.h>
#include "util.h"

void lerLinha(char *buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
}

void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    char tmp[256];
    fgets(tmp, sizeof(tmp), stdin);
}
