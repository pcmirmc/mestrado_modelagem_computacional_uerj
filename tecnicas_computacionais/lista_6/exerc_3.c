/*  Lista : 6
    Exercício: 3
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//definindo variaveis globais
int Number, Reminder, Count=0, Result;
// instanciando métodos
void store_number();
int count_digits(int n);
// estrutura principal
int main() {
    

    store_number();
    Result = count_digits(Number);
    printf("\n O número de dígitos do valor é: %d\n", Result);
    return 0;
   
}

// leitura dos angulos
void store_number() {

    printf("\n Entre com um número inteiro:\n");
    scanf("%d", &Number);

}

int count_digits(int n) {
    if (n > 0) {
        n = n / 10;
        n = n;
        Count += 1;
        count_digits(n);
    }
    return Count;
}