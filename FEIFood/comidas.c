#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comidas.h"
#include "util.h"

Comida comidas[MAX_COMIDAS];
int totalComidas = 0;
const char *ARQ_COMIDAS = "dados/comidas.txt";

void carregarComidas() {
    FILE *f = fopen(ARQ_COMIDAS, "r");
    totalComidas = 0;
    if (!f) return;
    while (!feof(f)) {
        Comida c;
        if (fscanf(f, "%d;%99[^;];%d;%lf;%lf;%d\n",
                   &c.id, c.nome, &c.idEstab, &c.preco, &c.somaNotas, &c.qtdAvaliacoes) == 6) {
            comidas[totalComidas++] = c;
        }
    }
    fclose(f);
}

void salvarComidas() {
    FILE *f = fopen(ARQ_COMIDAS, "w");
    if (!f) return;
    for (int i = 0; i < totalComidas; i++) {
        fprintf(f, "%d;%s;%d;%.2f;%.2f;%d\n",
                comidas[i].id, comidas[i].nome, comidas[i].idEstab,
                comidas[i].preco, comidas[i].somaNotas, comidas[i].qtdAvaliacoes);
    }
    fclose(f);
}

int proximoIdComida() {
    int maior = 0;
    for (int i = 0; i < totalComidas; i++)
        if (comidas[i].id > maior) maior = comidas[i].id;
    return maior + 1;
}

void cadastrarComida() {
    if (totalComidas >= MAX_COMIDAS) {
        printf("Limite máximo atingido.\n");
        return;
    }
    char nome[100], buf[50];
    double preco;
    int idEstab;

    printf("\n=== CADASTRAR COMIDA ===\n");
    printf("Nome da comida: ");
    lerLinha(nome, 100);
    printf("Preço: ");
    lerLinha(buf, 50); preco = atof(buf);
    printf("ID do estabelecimento: ");
    lerLinha(buf, 50); idEstab = atoi(buf);

    Comida nova = { proximoIdComida(), "", idEstab, preco, 0, 0 };
    strcpy(nova.nome, nome);
    comidas[totalComidas++] = nova;
    salvarComidas();
    printf("Comida cadastrada com sucesso! ID: %d\n", nova.id);
}

void removerComida() {
    int id;
    char buf[20];
    printf("ID da comida para remover: ");
    lerLinha(buf, 20); id = atoi(buf);
    int pos = -1;
    for (int i = 0; i < totalComidas; i++)
        if (comidas[i].id == id) pos = i;
    if (pos == -1) {
        printf("Comida não encontrada.\n");
        return;
    }
    for (int i = pos; i < totalComidas - 1; i++)
        comidas[i] = comidas[i + 1];
    totalComidas--;
    salvarComidas();
    printf("Comida removida com sucesso!\n");
}

void listarComidas() {
    printf("\n=== LISTA DE COMIDAS ===\n");
    for (int i = 0; i < totalComidas; i++) {
        double media = (comidas[i].qtdAvaliacoes == 0) ? 0 : comidas[i].somaNotas / comidas[i].qtdAvaliacoes;
        printf("ID: %d | %s | R$ %.2f | Média: %.1f\n",
               comidas[i].id, comidas[i].nome, comidas[i].preco, media);
    }
}

void mostrarEstatisticas() {
    printf("\n=== ESTATÍSTICAS ===\n");
    printf("Total de comidas: %d\n", totalComidas);

    if (totalComidas == 0) return;

    Comida melhor = comidas[0], pior = comidas[0];
    double melhorMedia = 0, piorMedia = 10;

    for (int i = 0; i < totalComidas; i++) {
        double media = (comidas[i].qtdAvaliacoes == 0) ? 0 : comidas[i].somaNotas / comidas[i].qtdAvaliacoes;
        if (media > melhorMedia) { melhorMedia = media; melhor = comidas[i]; }
        if (media < piorMedia) { piorMedia = media; pior = comidas[i]; }
    }

    printf("Mais bem avaliada: %s (%.1f)\n", melhor.nome, melhorMedia);
    printf("Mais mal avaliada: %s (%.1f)\n", pior.nome, piorMedia);
}
