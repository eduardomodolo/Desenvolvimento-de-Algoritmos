//pedir 5 numeros decimais para o usuario e mostra a soma
//no terminal ao inves de colocar 5,2 se coloca 5.2


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float n1;
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    float n2;
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    float n3;
    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);

    float n4;
    printf("Digite o quarto numero: ");
    scanf("%f", &n4);

    float n5;
    printf("Digite o quinto numero: ");
    scanf("%f", &n5);

    float soma = (n1 + n2 + n3 + n4 + n5);
    printf("A soma eh: %f", soma);





    return 0;
}
