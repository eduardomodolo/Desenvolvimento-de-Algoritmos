#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedidos.h"
#include "util.h"

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;
const char *ARQ_PEDIDOS = "dados/pedidos.txt";

void carregarPedidos() {
    FILE *f = fopen(ARQ_PEDIDOS, "r");
    totalPedidos = 0;
    if (!f) return;
    while (!feof(f)) {
        Pedido p;
        if (fscanf(f, "%d;%d;%d;%d;%d;%d\n",
                   &p.id, &p.idUsuario, &p.idComida, &p.quantidade, &p.avaliado, &p.nota) == 6)
            pedidos[totalPedidos++] = p;
    }
    fclose(f);
}

void salvarPedidos() {
    FILE *f = fopen(ARQ_PEDIDOS, "w");
    if (!f) return;
    for (int i = 0; i < totalPedidos; i++) {
        fprintf(f, "%d;%d;%d;%d;%d;%d\n",
                pedidos[i].id, pedidos[i].idUsuario, pedidos[i].idComida,
                pedidos[i].quantidade, pedidos[i].avaliado, pedidos[i].nota);
    }
    fclose(f);
}

int proximoIdPedido() {
    int maior = 0;
    for (int i = 0; i < totalPedidos; i++)
        if (pedidos[i].id > maior) maior = pedidos[i].id;
    return maior + 1;
}

void fazerPedido(int idUsuario) {
    listarComidas();
    char buf[20];
    int idComida, qtd;
    printf("\nID da comida: ");
    lerLinha(buf, 20); idComida = atoi(buf);
    printf("Quantidade: ");
    lerLinha(buf, 20); qtd = atoi(buf);

    Pedido p = { proximoIdPedido(), idUsuario, idComida, qtd, 0, 0 };
    pedidos[totalPedidos++] = p;
    salvarPedidos();
    printf("Pedido realizado com sucesso! ID: %d\n", p.id);
}

void listarPedidosUsuario(int idUsuario) {
    printf("\n=== SEUS PEDIDOS ===\n");
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].idUsuario == idUsuario) {
            printf("Pedido %d | Comida %d | Qtd %d | Avaliado: %s\n",
                   pedidos[i].id, pedidos[i].idComida, pedidos[i].quantidade,
                   pedidos[i].avaliado ? "Sim" : "Não");
        }
    }
}

void excluirPedido(int idUsuario) {
    char buf[20];
    printf("ID do pedido a excluir: ");
    lerLinha(buf, 20);
    int id = atoi(buf), pos = -1;
    for (int i = 0; i < totalPedidos; i++)
        if (pedidos[i].id == id && pedidos[i].idUsuario == idUsuario)
            pos = i;
    if (pos == -1) {
        printf("Pedido não encontrado.\n");
        return;
    }
    for (int i = pos; i < totalPedidos - 1; i++)
        pedidos[i] = pedidos[i + 1];
    totalPedidos--;
    salvarPedidos();
    printf("Pedido excluído com sucesso!\n");
}

void avaliarPedido(int idUsuario) {
    char buf[20];
    printf("ID do pedido a avaliar: ");
    lerLinha(buf, 20);
    int id = atoi(buf);
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id && pedidos[i].idUsuario == idUsuario && !pedidos[i].avaliado) {
            printf("Nota (0 a 5): ");
            lerLinha(buf, 20);
            int nota = atoi(buf);
            pedidos[i].avaliado = 1;
            pedidos[i].nota = nota;

            // Atualiza nota da comida
            for (int j = 0; j < totalComidas; j++) {
                if (comidas[j].id == pedidos[i].idComida) {
                    comidas[j].somaNotas += nota;
                    comidas[j].qtdAvaliacoes++;
                }
            }
            salvarPedidos();
            salvarComidas();
            printf("Avaliação registrada!\n");
            return;
        }
    }
    printf("Pedido não encontrado ou já avaliado.\n");
}
