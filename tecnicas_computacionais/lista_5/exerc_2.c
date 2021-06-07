/*  Lista : 5
    Exercício: 2
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//definindo variaveis globais
double LX,LY,DT,G;
int NX,NY;
int N; 
int i,j;
float DX,DY,b,c,a;
float **matrix_a;
char variables_address [50];
// instanciando métodos
void init();
void create_matrix_with_dynamic_allocation();
void write_matrix_c_var();
void write_matrix_b_var();
void write_matrix_a_var();
void save_matrix();

// estrutura principal
int main() {

    init();
    create_matrix_with_dynamic_allocation();
    write_matrix_c_var();
    write_matrix_b_var();
    write_matrix_a_var();
    save_matrix();



}

// metodo inicial, le o arquivo de variaveis e calcula as variaveis secundarias,n,dx,dy,b,c
void init() {
    FILE *file;
    printf("Digite o caminho para o arquivo com as variáveis LX,LY,DT,G,NX e NY separadas por vírgula: \n");
    scanf("%s",&variables_address);
    file = fopen(variables_address, "r");
    if (file) {
        
        fscanf(file, "%lf,%lf,%lf,%lf,%i,%i",&LX,&LY,&DT,&G,&NX,&NY);
    }
    fclose(file);

    N = NX * NY;
    DX = LX / NX;
    DY = LY / NY;
    b = 1 / (DX * DX);
    c = 1 / (DY * DY);

}

// cria a matriz com alocação dinâmica

void create_matrix_with_dynamic_allocation() {
    matrix_a = (float **)malloc(N * sizeof(float*));
    for (i=0; i<N; i++)
        matrix_a[i] = (float *)malloc(N * sizeof(float));
}

// calculo das diagonais que possuem a variavel c
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

// calculo das diagonais que possuem a variavel b
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

// calculo da diagonal principal a
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

// salvar a matrix como txt
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