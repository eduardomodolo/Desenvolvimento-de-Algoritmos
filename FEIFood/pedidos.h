#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "comidas.h"
#include "usuarios.h"

#define MAX_PEDIDOS 300

typedef struct {
    int id;
    int idUsuario;
    int idComida;
    int quantidade;
    int avaliado;
    int nota;
} Pedido;

extern Pedido pedidos[MAX_PEDIDOS];
extern int totalPedidos;

void carregarPedidos();
void salvarPedidos();
int proximoIdPedido();

void fazerPedido(int idUsuario);
void listarPedidosUsuario(int idUsuario);
void excluirPedido(int idUsuario);
void avaliarPedido(int idUsuario);

#endif
