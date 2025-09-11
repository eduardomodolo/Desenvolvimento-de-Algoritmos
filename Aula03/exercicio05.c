//Escreva um programa que leia um número de 1 a 7 e use
//switch-case para exibir o dia da semana correspondente
//(1=Domingo, 2=Segunda, etc.). Use break adequadamente e
//inclua tratamento para números inválidos.


#include <stdio.h>

int main(){

    int NumSema;
    printf("Digite um numero entre 1 e 7, que ira corresponder a um dia da semana: ");
    scanf("%d", &NumSema);

    switch (NumSema)
    {
    case 1:
        printf("Voce digitou 1, portanto: Domingo.");
        break;
    case 2:
        printf("Voce digitou 2, portanto: Segunda.");
        break;
    case 3:
        printf("Voce digitou 3, portanto: Terca-Feira.");
        break;
    case 4:
        printf("Voce digitou 4, portanto: Quarta-Feira.");
        break;
    case 5:
        printf("Voce digitou 5, portanto: Quinta-Feira.");
        break;
    case 6:
        printf("Voce digitou 6, portanto: Sexta-Feira.");
        break;
    case 7:
        printf("Voce digitou 7, portanto: Sabado.");
        break;

    default:
        printf("Voce nao digitou um numero valido.");
       
    }

    return 0;
}