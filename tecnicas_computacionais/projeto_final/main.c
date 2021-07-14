/*  Projeto Final
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

// inclusão das bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
// inclusao de variaveis globais
struct timeval stop, start;
// estrutura principal
int main() {
    
    read_matrix();
    // grava o time inicial
    gettimeofday(&start, NULL);
    create_init_var();
    run_model();
    //grava o time final
    gettimeofday(&stop, NULL);
    //printa a diferença em microsegundos
    printf("Levou %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); 
    return 0;
   
}