#ifndef COMIDAS_H
#define COMIDAS_H

#include "estabelecimentos.h"

#define MAX_COMIDAS 500

typedef struct {
    int id;
    char nome[TAM_NOME];
    int idEstab;
    double preco;
    double somaNotas;
    int qtdAvaliacoes;
} Comida;

extern Comida comidas[MAX_COMIDAS];
extern int totalComidas;

void carregarComidas();
void salvarComidas();
int proximoIdComida();

void cadastrarComida();
void removerComida();
void listarComidas();
void listarComidasPorEstab();
void mostrarEstatisticas();

#endif
