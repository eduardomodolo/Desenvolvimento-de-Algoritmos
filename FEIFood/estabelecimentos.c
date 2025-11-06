#include <stdio.h>
#include <string.h>
#include "estabelecimentos.h"
#include "util.h"

Estabelecimento estabs[MAX_ESTAB];
int totalEstabs = 0;
const char *ARQ_ESTAB = "dados/estabelecimentos.txt";

void carregarEstabs() {
    FILE *f = fopen(ARQ_ESTAB, "r");
    totalEstabs = 0;
    if (!f) return;
    while (!feof(f)) {
        Estabelecimento e;
        if (fscanf(f, "%d;%99[^\n]\n", &e.id, e.nome) == 2)
            estabs[totalEstabs++] = e;
    }
    fclose(f);
}

void salvarEstabs() {
    FILE *f = fopen(ARQ_ESTAB, "w");
    if (!f) return;
    for (int i = 0; i < totalEstabs; i++) {
        fprintf(f, "%d;%s\n", estabs[i].id, estabs[i].nome);
    }
    fclose(f);
}

int proximoIdEstab() {
    int maior = 0;
    for (int i = 0; i < totalEstabs; i++)
        if (estabs[i].id > maior) maior = estabs[i].id;
    return maior + 1;
}

void cadastrarEstabelecimento() {
    char nome[100];
    printf("\nNome do estabelecimento: ");
    lerLinha(nome, 100);
    Estabelecimento e = { proximoIdEstab(), "" };
    strcpy(e.nome, nome);
    estabs[totalEstabs++] = e;
    salvarEstabs();
    printf("Estabelecimento cadastrado com ID %d\n", e.id);
}

void listarEstabelecimentos() {
    printf("\n=== ESTABELECIMENTOS ===\n");
    for (int i = 0; i < totalEstabs; i++)
        printf("ID: %d | Nome: %s\n", estabs[i].id, estabs[i].nome);
}
