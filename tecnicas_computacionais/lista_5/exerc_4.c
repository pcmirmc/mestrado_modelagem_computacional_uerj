/*  Lista : 5
    Exercício: 1
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//definindo variaveis globais
float a,b,result;
char choice;
void read_values();
void sin_sum();
void cos_sum();
void sin_diff();
void cos_diff();
void tan_sum();
void tan_diff();
// instanciando métodos

// estrutura principal
int main() {

    printf("Bem Vindo a Calculadora de soma e diferença de arcos trigonométricos!!!\n\n");
    printf("Digite a opção Desejada:\n1 - Soma de seno\n2 - Soma de cosseno\n3 - Diferença de seno\n4 - Diferença de cosseno\n5 - Soma de Tangente\n6 - Diferença de Tangente\n");
    scanf("%c",&choice);
    switch (choice) {
        case '1':
            read_values();
            sin_sum();
            break;
        case '2':
            read_values();
            cos_sum();
            break;
        case '3':
            read_values();
            sin_diff();
            break;
        case '4':
            read_values();
            cos_diff();
            break;
        case '5':
            read_values();
            tan_sum();
            break;
        case '6':
            read_values();
            tan_diff();
            break;
        default:
            printf("O caracter %c não é uma opção válida!!!\n",choice);
            break;

    }
}

void read_values() {
    printf("Digite o valor do ângulo a: \n");
    scanf("%f",&a);
    printf("Digite o valor do ângulo b: \n");
    scanf("%f",&b);
}

void sin_sum() {

    result = (sin(a) * cos(b)) + (sin(b) * cos(a));
    printf("O resultado de sen( %f + %f ) é: %f",a,b,result);



}

void sin_diff() {

    result = (sin(a) * cos(b)) - (sin(b) * cos(a));
    printf("O resultado de sen( %f - %f ) é: %f",a,b,result);



}

void cos_sum() {

    result = (cos(a) * cos(b)) - (sin(a) * sin(b));
    printf("O resultado de cos( %f + %f ) é: %f",a,b,result);



}

void cos_diff() {

    result = (cos(a) * cos(b)) + (sin(a) * sin(b));
    printf("O resultado de cos( %f - %f ) é: %f",a,b,result);



}

void tan_sum() {
    result = (tan(a) + tan(b)) / (1 - (tan(a) * tan(b)));
    printf("O resultado de tan( %f + %f ) é: %f",a,b,result);

}

void tan_diff() {
    result = (tan(a) - tan(b)) / (1 + (tan(a) * tan(b)));
    printf("O resultado de tan( %f - %f ) é: %f",a,b,result);

}