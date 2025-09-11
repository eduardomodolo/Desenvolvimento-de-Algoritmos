//Crie um programa que leia três números e determine o
//maior e o menor valor usando operadores lógicos AND e OR
//combinados com estruturas condicionais if-else.

#include <stdio.h>

int main(){

    float num1, num2, num3;
    float maior, menor;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &num3);


    //descobrir o maior numero 
    if ((num1 >= num2) && (num1 >= num3))
    {
        maior = num1;
    }
    else if ((num2 >= num1) && (num2 >=num3))
    {
        maior = num2;
    }
    else{
        maior = num3;
    }

    
    //descobrir o menor numero
    if ((num1 <= num2) && (num1 <= num3))
    {
        menor = num1;
    }
    else if ((num2 <= num1) && (num2 <= num3))
    {
        menor = num2;
    }
    else{
        menor = num3;
    }

    printf("O maior numero eh %f.\n", maior);
    printf("O menor numero eh %f.\n", menor);

    return 0;
}