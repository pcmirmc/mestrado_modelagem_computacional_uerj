/*  Lista : 6
    Exercício: 7
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "vector.h"


// estrutura principal
int main() {
    printf("Configurando primeiro vetor: \n");
    // criando vetor 1 a partir da entrada do usuario
    create_vector_a_coordinates();
    // acessando e imprimindo na tela o vetor 1
    access_coordinates(vector_a);
    printf("Configurando segundo vetor: \n");
     // criando vetor 2 a partir da entrada do usuario
    create_vector_b_coordinates();
    // acessando e imprimindo na tela o vetor 2
    access_coordinates(vector_b);
    // calculo do produto escalar
    result = scalar_product(vector_a,vector_b);
    printf("O resultado do produto escalar dos vetores é: %f\n",result);
    printf("O resultado do produto vetorial dos vetores é:\n");
    //calculo do produto vetorial
    vectorial_product(vector_a,vector_b);
    printf("\n");

}

