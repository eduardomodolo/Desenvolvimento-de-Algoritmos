//Desenvolva um programa que simule um sistema de login
//simples. Leia um nome de usuário e senha. Use
// lógicos para verificar se ambos estão corretos
//(“admin” e “123456”). Exiba mensagens diferentes para:
//credenciais corretas, usuário incorreto, senha incorreta,
//ou ambos incorretos.

//NAO CONSEGUI FAZER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <stdio.h>

int main(){

    int login;
    printf("Digite seu login para acessar o sistema: ");
    scanf("%d", &login);

    int senha;
    printf("Digite sua senha de 6 digitos: ");
    scanf("%d", &senha);

    if ((login == "admin") && (senha == "123456"))
    {
        printf("Acesso concedido.");
    }
    else if ((login != "admin") || (senha != "123456"))
    {
        printf("Uma das credenciais estao erradas");
    }
    else{
        printf("Ambas as credenciais estao incorretas.");
    }
    
    




//NAO CONSEGUI FAZER 









    return 0;
}