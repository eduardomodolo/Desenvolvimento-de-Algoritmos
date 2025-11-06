#ifndef ESTABELECIMENTOS_H
#define ESTABELECIMENTOS_H

#define MAX_ESTAB 100
#define TAM_NOME 100

typedef struct {
    int id;
    char nome[TAM_NOME];
} Estabelecimento;

extern Estabelecimento estabs[MAX_ESTAB];
extern int totalEstabs;

void carregarEstabs();
void salvarEstabs();
int proximoIdEstab();
void cadastrarEstabelecimento();
void listarEstabelecimentos();

#endif
