//Escreva um programa que leia dois números inteiros e
//determine qual é o maior usando apenas operadores de
//comparação. Se os números forem iguais, exiba uma
//mensagem apropriada.

int main(int argc, char const *argv[])
{
    float num1;
    printf("Digite o primeiro numero:");
    scanf("%f",&num1);

    float num2;
    printf("Digite o segundo numero:");
    scanf("%f",&num2);

    if (num1 > num2)
    {
        printf("%f eh maior que %f.\n", num1, num2);
    }

    else if (num2 > num1)
    {
        printf("%f eh maior que %f.\n", num2, num1);
    }

    else{
        printf("Os dois numeros sao iguais.");
    }

    return 0;
}

