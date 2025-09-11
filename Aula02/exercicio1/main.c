#include <stdio.h>
#include "biblioteca.h"

int main()
{
    float a = 10.0, b = 3.0;

    printf("Os dois numeros sao a = %f e b = %f.\n", a, b);
    printf("A soma dos dois numeros e = %f.\n", soma(a, b));
    printf("A subtracao dos dois numeros e = %f.\n", subtracao(a, b));
    printf("A divisao dos dois numeros e = %f.\n", divisao(a, b));

    return 0;
}
