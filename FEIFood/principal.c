#include <stdio.h>
#include "usuarios.h"
#include "estabelecimentos.h"
#include "comidas.h"
#include "pedidos.h"
#include "util.h"

int main() {
    carregarUsuarios();
    carregarEstabs();
    carregarComidas();
    carregarPedidos();

    // cria admin padrao se nao existir
    int temAdmin = 0;
    for (int i = 0; i < totalUsuarios; i++)
        if (usuarios[i].ehAdmin) temAdmin = 1;
    if (!temAdmin) {
        Usuario adm = { proximoIdUsuario(), "admin", "admin", 1 };
        usuarios[totalUsuarios++] = adm;
        salvarUsuarios();
        printf("Administrador padrao criado: login=admin, senha=admin\n");
    }

    char op[10];
    while (1) {
        printf("\n== FEIFOOD ==\n");
        printf("1 - Cadastrar novo usuario\n");
        printf("2 - Login como usuario\n");
        printf("3 - Login como administrador\n");
        printf("0 - Sair\nOpcao: ");
        lerLinha(op, 10);

        if (op[0] == '1') cadastrarUsuario();
        else if (op[0] == '2') {
            int idUser;
            if (loginUsuario(&idUser)) {
                printf("\nLogin efetuado!\n");
                while (1) {
                    printf("\n1 - Fazer pedido\n");
                    printf("2 - Ver meus pedidos\n");
                    printf("3 - Excluir pedido\n");
                    printf("4 - Avaliar pedido\n");
                    printf("0 - Sair\nOpcao: ");
                    lerLinha(op, 10);
                    if (op[0] == '0') break;
                    else if (op[0] == '1') fazerPedido(idUser);
                    else if (op[0] == '2') listarPedidosUsuario(idUser);
                    else if (op[0] == '3') excluirPedido(idUser);
                    else if (op[0] == '4') avaliarPedido(idUser);
                }
            } else printf("Falha no login.\n");
        }
        else if (op[0] == '3') {
            int idAdm;
            if (loginAdministrador(&idAdm)) {
                printf("\nLogin de administrador realizado.\n");
                while (1) {
                    printf("\n=== MENU ADMIN ===\n");
                    printf("1 - Cadastrar estabelecimento\n");
                    printf("2 - Cadastrar comida\n");
                    printf("3 - Remover comida\n");
                    printf("4 - Listar comidas\n");
                    printf("5 - Listar usuarios\n");
                    printf("6 - Estatisticas do sistema\n");
                    printf("0 - Sair\nOpcao: ");
                    lerLinha(op, 10);
                    if (op[0] == '0') break;
                    else if (op[0] == '1') cadastrarEstabelecimento();
                    else if (op[0] == '2') cadastrarComida();
                    else if (op[0] == '3') removerComida();
                    else if (op[0] == '4') listarComidas();
                    else if (op[0] == '5') listarUsuarios();
                    else if (op[0] == '6') mostrarEstatisticas();
                }
            } else printf("Login incorreto.\n");
        }
        else if (op[0] == '0') break;
    }

    printf("\nSaindo do sistema...\n");
    return 0;
}
