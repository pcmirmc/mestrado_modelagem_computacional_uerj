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
void (*ptr) (float, float);
void sin_sum(float a, float b);
void cos_sum(float a, float b);
void sin_diff(float a, float b);
void cos_diff(float a, float b);
void tan_sum(float a, float b);
void tan_diff(float a, float b);
// instanciando métodos

// estrutura principal
int main() {

    printf("Bem Vindo a Calculadora de soma e diferença de arcos trigonométricos!!!\n\n");
    printf("Digite a opção Desejada:\n1 - Soma de seno\n2 - Soma de cosseno\n3 - Diferença de seno\n4 - Diferença de cosseno\n5 - Soma de Tangente\n6 - Diferença de Tangente\n");
    scanf("%c",&choice);
    read_values();
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

void read_values() {
    printf("Digite o valor do ângulo a: \n");
    scanf("%f",&a);
    printf("Digite o valor do ângulo b: \n");
    scanf("%f",&b);
}

void sin_sum(float a, float b) {

    result = (sin(a) * cos(b)) + (sin(b) * cos(a));
    printf("O resultado de sen( %f + %f ) é: %f",a,b,result);



}

void sin_diff(float a, float b) {

    result = (sin(a) * cos(b)) - (sin(b) * cos(a));
    printf("O resultado de sen( %f - %f ) é: %f",a,b,result);



}

void cos_sum(float a, float b) {

    result = (cos(a) * cos(b)) - (sin(a) * sin(b));
    printf("O resultado de cos( %f + %f ) é: %f",a,b,result);



}

void cos_diff(float a, float b) {

    result = (cos(a) * cos(b)) + (sin(a) * sin(b));
    printf("O resultado de cos( %f - %f ) é: %f",a,b,result);



}

void tan_sum(float a, float b) {
    result = (tan(a) + tan(b)) / (1 - (tan(a) * tan(b)));
    printf("O resultado de tan( %f + %f ) é: %f",a,b,result);

}

void tan_diff(float a, float b) {
    result = (tan(a) - tan(b)) / (1 + (tan(a) * tan(b)));
    printf("O resultado de tan( %f - %f ) é: %f",a,b,result);

}