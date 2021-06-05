/*  Lista : 5
    Exercício: 1
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//definindo variaveis globais
double LX,LY,DT,G;
int NX = 4;
int NY = 4;
int N; 
int i,j;
float DX,DY,b,c,a;
float matrix_a [16][16];
void init();
void write_matrix_c_var();
void write_matrix_b_var();
void write_matrix_a_var();
void save_matrix();
// instanciando métodos

// estrutura principal
int main() {

    init();
    write_matrix_c_var();
    write_matrix_b_var();
    write_matrix_a_var();
    save_matrix();



}

void init() {
    N = NX * NY;
    printf("Digite o valor para LX:\n");
    scanf("%lf",&LX);

    printf("Digite o valor para LY:\n");
    scanf("%lf",&LY);

    printf("Digite o valor para DT:\n");
    scanf("%lf",&DT);

    printf("Digite o valor para G:\n");
    scanf("%lf",&G);

    DX = LX / NX;
    DY = LY / NY;
    b = 1 / (DX * DX);
    c = 1 / (DY * DY);

}

void write_matrix_c_var() {

     
     for(i=0;i<N;i++) {
	    for(j=0;j<N;j++) {
            if (j >= 4 && i == (j - 4)) {
                matrix_a[i][j] = c;
            }
            else if (i >= 4 && j == (i - 4)) {
                matrix_a[i][j] = c;
            }
            else {
                matrix_a[i][j] = 0;
            }
        }
    }
}

void write_matrix_b_var() {

     int aux_1 = 0;
     int aux_2 = 0;
     for(i=0;i<N;i++) {
	    for(j=0;j<N;j++) {
            if (j >= 1 && i == (j - 1)) {
                if (aux_1 != 3) {
                    matrix_a[i][j] = b;
                    aux_1 += 1;
                }
                else {
                    aux_1 = 0;
                }
            }
            else if (i >= 1 && j == (i - 1)) {
                if (aux_2 != 3) {
                matrix_a[i][j] = b;
                aux_2 += 1;
                }
                else {
                    aux_2 = 0;
                }
            }
            
        }
    }
}

void write_matrix_a_var() {
    float base_a = G / DT;
     
     for(i=0;i<N;i++) {
        a = base_a;
	    for(j=0;j<N;j++) {
            a += matrix_a[i][j];
        }
        matrix_a[i][i] = a;
    }
}

void save_matrix() {
    FILE *file_output;
    file_output = fopen("result_matrix.txt", "w");
    printf("A matrix resultante é:\n");
    for(i=0;i<N;i++) {
        printf("|");
        fprintf(file_output,"|");
		for(j=0;j<N;j++) {
            printf(" ");
			printf("%.2f",matrix_a[i][j]);
            printf(" ");
            fprintf(file_output, "%.2f,",matrix_a[i][j]);
        }
  		printf("|\n");
        fprintf(file_output,"|\n");
	}
    printf("Você pode encontrá-la em: result_matrix.txt\n");
    fclose(file_output);
}