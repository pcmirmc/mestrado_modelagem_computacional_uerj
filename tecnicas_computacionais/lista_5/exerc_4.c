/*  Lista : 5
    Exercício: 4
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "trig.h"
//definindo variaveis globais
float a,b;
char choice;
// instanciando métodos
void read_values();
void (*ptr) (float, float);

// estrutura principal
int main() {

    printf("Bem Vindo a Calculadora de soma e diferença de arcos trigonométricos!!!\n\n");
    printf("Digite a opção Desejada:\n1 - Soma de seno\n2 - Soma de cosseno\n3 - Diferença de seno\n4 - Diferença de cosseno\n5 - Soma de Tangente\n6 - Diferença de Tangente\n");
    scanf("%c",&choice);
    read_values();
    // escolhe o tipo de calculo de acordo com a variavel choice do usuário
    switch (choice) {
        case '1':
            ptr = sin_sum;
            break;
        case '2':
            ptr = cos_sum;
            break;
        case '3':
            ptr = sin_diff;
            break;
        case '4':
            ptr = cos_diff;
            break;
        case '5':
            ptr = tan_sum;
            break;
        case '6':
            ptr = tan_diff;
            break;
        default:
            printf("O caracter %c não é uma opção válida!!!\n",choice);
            break;

    }

    (*ptr) (a,b);
}

// leitura dos angulos
void read_values() {
    printf("Digite o valor do ângulo a: \n");
    scanf("%f",&a);
    printf("Digite o valor do ângulo b: \n");
    scanf("%f",&b);
}