//Crie um programa que leia três notas de um aluno e
//calcule a média. Use estruturas condicionais if-else
//para determinar se o aluno foi aprovado (média >= 7.0),
//ficou em recuperação (média >= 5.0 e < 7.0) ou foi
//reprovado (média < 5.0).


#include <stdio.h>

int main(int argc, char const *argv[])
{
    float nota1;
    printf("Digite a sua primeira nota:");
    scanf("%f", &nota1);

    float nota2;
    printf("Digite a sua segunda nota:");
    scanf("%f", &nota2);

    float nota3;
    printf("Digite a tercieta nota:");
    scanf("%f", &nota3);

    float media = (nota1 + nota2 + nota3) / 3;

    if (media >= 7)
    {
        printf("Voce foi aprovado.\n");
    }

    else if ((media >= 5) && (media < 7))
    {
        printf("Voce esta de recuperacao.\n");
    }

    else{
        printf("Voce esta reprovado.\n");
    }
    
    return 0;
}
