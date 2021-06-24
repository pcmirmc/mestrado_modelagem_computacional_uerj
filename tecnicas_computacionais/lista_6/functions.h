#ifndef __FUNCTIONS_H__
    #define __FUNCTIONS_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    // definindo variaveis globais
    int Count=0;
    int vector_a[10],vector_aux[10];
    int aux = 9;
    int i;
    // definindo funções
    int count_digits(int n);
    void create_vector();
    int reverse_vector(int vector[]);
    void return_reverse_vector();

    // funcao para contar dititos
    /* uso da divisao por 10 e recursividade
    para contagem de casa decimal */
    int count_digits(int n) {
        if (n > 0) {
            n = n / 10;
            n = n;
            Count += 1;
            count_digits(n);
        }
        return Count;
    }
    //funcao para criar um vetor a partir da entrada do usuario
    void create_vector() {
        for (i=0;i<10;i++) {
            printf("\n Entre com o valor %d para seu vetor:\n",i);
            scanf("%d", &vector_a[i]); 
        }
    }
    // funcao para imprimir o vetor inverso
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
    //funcao para criar um vetor inverso a partir de outro usando recursividade
    int reverse_vector(int vector[]) {

        if (aux >= 0) {

            vector_aux[9-aux] = vector[aux];
            aux -= 1;
            reverse_vector(vector);
   
        }
    }

#endif