/*  Lista : 6
    Exercício: 5
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//definindo variaveis globais
int i;
int vector_a[10],vector_aux[10];
int aux = 9;
// instanciando métodos
void create_vector();
int reverse_vector(int vector[]);
void return_reverse_vector();
// estrutura principal
int main() {
    create_vector();
    reverse_vector(vector_a);
    return_reverse_vector();
   
}

// leitura dos angulos


void create_vector() {
    for (i=0;i<10;i++) {
        printf("\n Entre com o valor %d para seu vetor:\n",i);
        scanf("%d", &vector_a[i]); 
    }
}

int reverse_vector(int vector[]) {

    if (aux >= 0) {

        vector_aux[9-aux] = vector[aux];
        aux -= 1;
        reverse_vector(vector);
   
    }
}

void return_reverse_vector() {
    printf("| ");
    for (i=0;i<10;i++) {
        printf("%d",vector_aux[i]);
        if (i < 9) {
            printf(",");
        }
    }
    printf(" |");
}