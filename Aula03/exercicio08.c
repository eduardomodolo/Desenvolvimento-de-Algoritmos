//Implemente um menu interativo usando switch-case que
//ofereça as seguintes opções:
//1) Calcular área do círculo
//2) Calcular área do retângulo
//3) Calcular área do triângulo
//) Sair.
//Para cada opção, leia os dados necessários e realize o
//cálculo apropriado. Use break corretamente em cada case.

#include <stdio.h>

int main(){

    float areaCirculo, areaRetangulo, areaTriangulo;
    float base, altura;
    float raio;

    int opcao;
    printf("Digite o que quer que seja feito:\n 1 = Calcular area do circulo: \n 2 = Calcular area do retangulo: \n 3 = calcular area do triangulo:");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Digite o raio do circulo: ");
        scanf("%f", &raio);
        areaCirculo = 3.14 * (raio * raio);
        printf("A area do circulo eh: %f ", areaCirculo);
        break;

    case 2:
        printf("Digite a base do retangulo: ");
        scanf("%f", &base);
        printf("Digite a altura do retangulo: ");
        scanf("%f", &altura);
        areaRetangulo = (base * altura);
        printf("A area do retangulo eh: %f", areaRetangulo);
        break;

    case 3:
        printf("Digite a base do triangulo: ");
        scanf("%f", &base);
        printf("Digite a altura do triangulo: ");
        scanf("%f", &altura);
        areaTriangulo = ((base * altura) / 2);
        printf("A area do triangulo eh: %f", areaTriangulo);
        break;

    
    default:
    printf("Voce nao digitou uma opcao valida.");
        break;
    }


    return 0;
}