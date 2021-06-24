/*  Lista : 6
    Exercício: 5
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"


// estrutura principal
int main() {
    // criando o vetor
    create_vector();
    // criando outro vetor com os valores inversos do vetor inicial
    reverse_vector(vector_a);
    // imprimindo novo vetor na tela
    return_reverse_vector();
   
}
