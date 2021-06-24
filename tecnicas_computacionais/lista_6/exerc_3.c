/*  Lista : 6
    Exercício: 3
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

//definindo variaveis globais
int Number, Result;
// instanciando métodos
void store_number();
// estrutura principal
int main() {
    

    store_number();
    // chamada da função para contar digitos
    Result = count_digits(Number);
    printf("\n O número de dígitos do valor é: %d\n", Result);
    return 0;
   
}

// leitura do numero inteiro
void store_number() {

    printf("\n Entre com um número inteiro:\n");
    scanf("%d", &Number);

}