#include <stdio.h>
#include <string.h>
#include "usuarios.h"
#include "util.h"

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;
const char *ARQ_USUARIOS = "dados/usuarios.txt";

void carregarUsuarios() {
    FILE *f = fopen(ARQ_USUARIOS, "r");
    totalUsuarios = 0;
    if (!f) return;
    while (!feof(f)) {
        Usuario u;
        if (fscanf(f, "%d;%49[^;];%49[^;];%d\n", &u.id, u.login, u.senha, &u.ehAdmin) == 4) {
            usuarios[totalUsuarios++] = u;
        }
    }
    fclose(f);
}

void salvarUsuarios() {
    FILE *f = fopen(ARQ_USUARIOS, "w");
    if (!f) return;
    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(f, "%d;%s;%s;%d\n", usuarios[i].id, usuarios[i].login, usuarios[i].senha, usuarios[i].ehAdmin);
    }
    fclose(f);
}

int proximoIdUsuario() {
    int maior = 0;
    for (int i = 0; i < totalUsuarios; i++)
        if (usuarios[i].id > maior) maior = usuarios[i].id;
    return maior + 1;
}

void cadastrarUsuario() {
    char login[50], senha[50];
    printf("\n=== CADASTRO DE USUÁRIO ===\n");
    printf("Login: "); lerLinha(login, 50);
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0) {
            printf("Usuário já existe!\n");
            return;
        }
    }
    printf("Senha: "); lerLinha(senha, 50);
    Usuario novo = { proximoIdUsuario(), "", "", 0 };
    strcpy(novo.login, login);
    strcpy(novo.senha, senha);
    usuarios[totalUsuarios++] = novo;
    salvarUsuarios();
    printf("Usuário cadastrado com sucesso! ID: %d\n", novo.id);
}

int loginUsuario(int *id) {
    char login[50], senha[50];
    printf("\nLogin: "); lerLinha(login, 50);
    printf("Senha: "); lerLinha(senha, 50);
    for (int i = 0; i < totalUsuarios; i++) {
        if (!usuarios[i].ehAdmin &&
            strcmp(usuarios[i].login, login) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0) {
            *id = usuarios[i].id;
            return 1;
        }
    }
    return 0;
}

int loginAdministrador(int *id) {
    char login[50], senha[50];
    printf("\nLogin (Admin): "); lerLinha(login, 50);
    printf("Senha: "); lerLinha(senha, 50);
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].ehAdmin &&
            strcmp(usuarios[i].login, login) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0) {
            *id = usuarios[i].id;
            return 1;
        }
    }
    return 0;
}

void listarUsuarios() {
    printf("\n=== LISTA DE USUÁRIOS ===\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d | Login: %s | Tipo: %s\n",
               usuarios[i].id,
               usuarios[i].login,
               usuarios[i].ehAdmin ? "Administrador" : "Comum");
    }
}
