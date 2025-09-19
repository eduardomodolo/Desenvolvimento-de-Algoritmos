int main(int argc, char const *argv[])
{
    int numeros[8];
    int i, maior, menor, posMaior, posMenor;

    // Leitura dos 8 números
    for (i = 0; i < 8; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializando maior e menor com o primeiro valor
    maior = menor = numeros[0];
    posMaior = posMenor = 0;

    // Verificando maior e menor
    for (i = 1; i < 8; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    return 0;
}
