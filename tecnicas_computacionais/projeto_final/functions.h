#ifndef __FUNCTIONS_H__
    #define __FUNCTIONS_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    //definiciao das variaveis globais
    // matriz de coeficientes A
    double matrix_a[25][25];
    // matriz para o x°
    double x_ini[25] = {100,100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,100,100,100,100,100,100,100,100,100};
    //matriz d
    double ans_vector[25] = {100,100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,100,100,100,100,100,100,100,100,100};
    //variaveis de iteração do método, x,r,p,g e epsilon (critério de aceite)
    double x_next[25],r_ini[25],p_ini[25],g_ini[25],a_ini=0,epsilon=0.01;
    //endereco do arquivo txt que contem a matriz
    char matrix_a_address[50];
    // outras variaveis usadas durante a iteracao
    int i,j;
    int iteration=1;

    //metodo para ler a matrix do arquivo txt e salvar em matrix_a (o arquivo é o matrix_sparse.txt)
    void read_matrix(){
        FILE *file;
        printf("Digite o caminho para o arquivo da matriz: \n");
        scanf("%s",&matrix_a_address);
        file = fopen(matrix_a_address, "r");
        if (file) {
            for(i=0;i<25;i++) {
                for(j=0;j<25;j++) {
                    fscanf(file, "%lf,", &matrix_a[i][j]);
                }
            }
            fclose(file);
        }
    }
    //metodo para criar as variaveis iniciais r°,p°
    void create_init_var(){
        float aux=0;
        float a_x[25];
        for (i=0;i<25;i++) {
            for (j=0;j<25;j++){
                aux += matrix_a[i][j] * x_ini[j];
            }
            a_x[i] = aux;
            aux = 0;
        }
        for (i=0;i<25;i++){
            r_ini[i] = ans_vector[i] - a_x[i];
            p_ini[i] = r_ini[i];
        }
    }

    // roda o metodo de gradientes conjugados
    void run_model(){
        // variáveis auxiliares para calcular a tolerância
        float aux_error=0,aux_error2=0;
        //laço do-while principal que faz um check na tolerância
        do
        {
            // variáveis auxiliares para o calculo das variáveis
            float aux=0;
            float aux2=0;
            // for loop para calculo do g
            for (i=0;i<25;i++){
                for (j=0;j<25;j++){
                    aux += matrix_a[i][j] * p_ini[j];
                }
                g_ini[i] = aux;
                aux = 0;
            }
            // for loop para o calculo do a
            for (i=0;i<25;i++){
                aux += r_ini[i] * r_ini[i];
                aux2 += p_ini[i] * g_ini[i];
            }
            a_ini = aux / aux2;
            // criacao do vetor auxiliar para calculo do proximo x
            float aux_vec[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            for (i=0;i<25;i++){
                aux_vec[i] = a_ini * p_ini[i];
                x_next[i] = x_ini[i] + aux_vec[i];
            }
            // for loop para o calculo da tolerância
            for (i=0;i<25;i++){
                aux_error2 = abs(x_next[i] - x_ini[i]);
                if(i==0){
                    aux_error = aux_error2;
                    continue;
                }
                if(aux_error2 > aux_error) {
                    aux_error = aux_error2;
                }
            }
            // for loop para o calculo do proximo r;
            float r_next[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            for (i=0;i<25;i++){
                r_next[i] = r_ini[i] - (a_ini * g_ini[i]);

            }
            // for loop para o calculo do próximo b
            float b = 0;
            aux = 0, aux2 = 0;
            for (i=0;i<25;i++){
                aux += r_next[i] * r_next[i];
                aux2 += r_ini[i] * r_ini[i];
            }
            b = aux / aux2;
            //for loop para o calculo do proximo p
            float p_next[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            for (i=0;i<25;i++){
            p_next[i] = r_next[i] + (b * p_ini[i]);
            }

            //reset das variaveis
            for (i=0;i<25;i++){
                x_ini[i] = x_next[i];
                r_ini[i] = r_next[i];
                p_ini[i] = p_next[i];
            }
            //print dos resultados obtidos
            printf("Resultado da %d iteração:\n",iteration);
            printf("Valor do Erro: %lf\n",aux_error);
            printf("Vetor de variáveis resposta:\n");
            printf("{");
            for(j=0;j<25;j++) {
                printf(" ");
                printf("%.4f",x_next[j]);
                printf(" ");
            }
            printf("}\n");
            iteration += 1;
        }while (aux_error > epsilon);
    }



#endif