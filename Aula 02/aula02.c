#include <stdio.h>

int main() {
    int numeros[5];  // Vetor para armazenar os 5 números
    int soma = 0;

    // Solicita ao usuário os 5 números
    printf("Digite 5 numeros inteiros:\n");

    for(int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    // Exibe o resultado da soma
    printf("\nA soma dos numeros digitados é: %d\n", soma);

    return 0;
}
