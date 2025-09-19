int main(int argc, char const *argv[])
{
   
    int numeros[15];
    int pares, impares;
    int i, opcao;

    do {
        pares = 0;
        impares = 0;

        printf("Digite 15 numeros inteiros:\n");
        for (i = 0; i < 15; i++) {
            printf("Numero %d: ", i + 1);
            scanf("%d", &numeros[i]);

            if (numeros[i] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
        }

        printf("\nResultado:\n");
        printf("Quantidade de numeros pares: %d\n", pares);
        printf("Quantidade de numeros impares: %d\n", impares);

        printf("\nDeseja executar novamente?\n");
        printf("1 - Sim\n");
        printf("0 - Nao (Sair)\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

    } while (opcao != 0);

    printf("\nPrograma encerrado.\n");
    


    return 0;
}
