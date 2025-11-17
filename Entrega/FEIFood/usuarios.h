#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_USUARIOS 200
#define TAM_LOGIN 50
#define TAM_SENHA 50

typedef struct {
    int id;
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int ehAdmin; // 1 = administrador, 0 = usuário
} Usuario;

extern Usuario usuarios[MAX_USUARIOS];
extern int totalUsuarios;

void carregarUsuarios();
void salvarUsuarios();
int proximoIdUsuario();

void cadastrarUsuario();
int loginUsuario(int *id);
int loginAdministrador(int *id);
void listarUsuarios();

#endif
