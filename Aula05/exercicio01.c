//Declare um array de 5 inteiros
//Peça ao usuário para digitar os 5 valores
//Exiba todos os valores na ordem digitada

int main(int argc, char const *argv[])
{

    int tabela[5];

    for( int i = 0; i < 5; i++){
        printf("Digite o %d valor inteiro: ", i + 1);
        scanf("%d", &tabela[i]);
    }

    printf("Valores digitados na ordem: \n");
    for(int i = 0; i < 5; i++){
        printf("%d\n", tabela[i]);
    }

    return 0;
}
