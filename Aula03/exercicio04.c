//implemente uma calculadora simples usando switch-case. O
//programa deve ler dois números e um operador (+, -, *, /)
//e realizar a operação correspondente. Inclua validação
//para divisão por zero e operadores inválidos usando
//default.

#include <stdio.h>

int main()
{
    float num1, num2, resultado;
    int operador;

    printf("Digite o primeiro numero:");
    scanf("%f", &num1);

    printf("Digite o segundo numero:");
    scanf("%f", &num2);

    printf("Digite o indicador da operacao: + = 1, - = 2, * = 3, / = 4: ");
    scanf("%d", &operador);

    switch (operador)
    {
    case 1:
        resultado = (num1 + num2);
        printf("O resultado da soma eh %f", resultado);
        break;

    case 2:
       resultado = (num1 - num2);
       printf("O resultado da subtracao eh %f", resultado);
       break;

    case 3:
       resultado = (num1 * num2);
       printf("O resultado da multiplicacao eh %f", resultado);
       break;

    case 4:
       resultado = (num1 / num2);
       printf("O resultado da multiplicacao eh %f", resultado);
       break;
    
    default:
    printf("Operador inválido. ");
    }

    return 0;
}
