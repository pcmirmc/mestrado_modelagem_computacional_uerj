/*  Lista : 2
    Exercício: 6
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */
#include <stdio.h>
#include <math.h>
float xant = 0;
float xn = 2.5;
float function;
float derivated_function;
int iteration = 0;

void newton_raphson();
void main() {


    newton_raphson();


}
void newton_raphson(){
    do {
    iteration += 1;
    xant = xn;
    function = (xant*xant*xant) - (9*xant) + 3;
    derivated_function = (3*xant*xant) -9;
    xn = xant - (function / derivated_function);
    }while(fabs(function) >= 0.0001);

    printf("numero da iteração: %d\n",iteration);
    printf("Valor de f(x): %f\n",fabs(function));
    printf("Valor de x: %f\n",xn);

    FILE *file_output;
    file_output = fopen("newton_raphson_result.dat", "w");
    fprintf(file_output, "ultima_iteracao,|f(x%d)|,x%d\n",iteration,iteration);
    fprintf(file_output, "%d,%f,%f",iteration,fabs(function),xn);
    fclose(file_output);
}
