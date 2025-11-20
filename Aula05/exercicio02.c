// Implemente um programa que:
// Leia 10 números inteiros para um array
// Calcule e exiba a soma de todos os elementos
// Exiba também quantos números são positivos

int main(int argc, char const *argv[])
{

    int numeros[10];
    int soma = 0;
    int positivos = 0;

    // Leitura dos 10 números
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i]; // acumula na soma
        if (numeros[i] > 0)
        {
            positivos++; // conta se for positivo
        }
    }

    // Exibindo os resultados
    printf("\nSoma de todos os elementos: %d\n", soma);
    printf("Quantidade de numeros positivos: %d\n", positivos);

    return 0;
}
