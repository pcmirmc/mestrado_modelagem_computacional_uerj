#ifndef __NEWTON_H__
    #define __NEWTON_H__
    #include <math.h>
    #include <stdio.h>

// declaroando variaveis que vao ser usadas no metodo de newton
    int iteration = 0;
    float function;
    float derivated_function;
    // funcao para o metodo de newton 
    void newton_raphson(float xant,float xn){
        do {
        iteration += 1;
        xant = xn;
        function = (xant*xant*xant) - (9*xant) + 3;
        // calculando a derivada de function
        derivated_function = (3*xant*xant) -9;
        // aplicando a otimizacao de newton raphson
        xn = xant - (function / derivated_function);
        // repita o processo enquanto f(x) seja maior ou iguak a 0.0001
        }while(fabs(function) >= 0.0001);

        // printa os resultados na tela
        printf("numero da iteração: %d\n",iteration);
        printf("Valor de f(x): %f\n",fabs(function));
        printf("Valor de x: %f\n",xn);

        // salva em um arquivo .dat "newton_raphson_result.dat"
        FILE *file_output;
        file_output = fopen("newton_raphson_result.dat", "w");
        fprintf(file_output, "ultima_iteracao,|f(x%d)|,x%d\n",iteration,iteration);
        fprintf(file_output, "%d,%f,%f",iteration,fabs(function),xn);
        fclose(file_output);
    }

#endif