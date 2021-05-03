/*  Lista : 1
    Exercício: 3
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>

//definindo temperatura em graus celsius
#define  celsius_1  5.0
#define  celsius_2  9.0
#define  celsius_3  32.0

float to_fahrenheit();
int main() {


    to_fahrenheit();


}
float to_fahrenheit(){

    // definindo a variavel fahrenheit usando celsius como input atraves da formula
    float fahrenheit1 = (celsius_1 * 9/5) + 32;
    float fahrenheit2 = (celsius_2 * 9/5) + 32;
    float fahrenheit3 = (celsius_3 * 9/5) + 32;

    printf("%.3f\n",fahrenheit1);
    printf("%.3f\n",fahrenheit2);
    printf("%.3f",fahrenheit3);
}