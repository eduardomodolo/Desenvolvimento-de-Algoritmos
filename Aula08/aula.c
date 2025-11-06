#include <stdio.h>


int main(){
 FILE *f = fopen("arquivo.txt", "b");
 char linha[255];
 int cont = 0;
 // enquanto não chegar ao final do arquivo
 while (!feof(f)){
 fscanf(f, "%s", linha);
 printf("%d: %s\n", cont++, linha);
 }
}
