/*  Lista : 1
    Exercício: 2
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
float to_fahrenheit();
int main() {


    to_fahrenheit();


}
float to_fahrenheit(){
    //definindo temperatura em graus celsius
    float celsius = 24.2;
    // definindo a variavel fahrenheit usando celsius como input atraves da formula
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.3f",fahrenheit);
}