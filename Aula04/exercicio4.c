#include <stdio.h>

int main(int argc, char const *argv[])
{
    int opcao, num;
    do
    {
        printf("Opcao 1: Calcular o quadrado de um numero.\n");
        printf("Opcao 2: Calcualar o cubo de um numero.\n");
        printf("Opcao 3: Sair.\n");
        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
        printf ("Digite um numero:");
        scanf("%d", &num);
        printf("Quadrado de %d = %d\n", num, num * num);


        case 2:
        printf("Digite um numero:");
        scanf("%d", &num);
        printf("O cubo de %d = %d\n", num, num * num * num);


        case 3:
        printf("Saindo do programa.");
        break;

        default:
        printf ("Opcao invalida, tente novamente.");
        
    
    
    
    
    
    
    
    }




        
        
    } while (opcao !=3);
    
    return 0;
}
