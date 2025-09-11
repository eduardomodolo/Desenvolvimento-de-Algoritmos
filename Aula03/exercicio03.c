//verificar a idade de alguem e ver se essa pessoa possui a maioridade ou nao

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int idade;
    printf("Digite a sua idade:");
    scanf("%d", &idade);

    if (idade >= 18){
        printf("Voce possui a maioridade.\n");
    }
    else{
        printf("Voce nao possui a maioridade.\n");
    }
    return 0;
}
