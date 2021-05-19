/*  Lista : 4
    Exercício: 7
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//definindo variaveis globais
int LIN,COL; 
int i,j,k;
float **matrix_a;
char matrix_a_address [50];
char matrix_dim_address [50];

// instanciando métodos
void update_matrix_with_random_numbers();
void second_update_matrix_with_trigonometric_rule();
void read_matrix();
void read_matrix_dim();
void save_matrix();
// estrutura principal
int main() {

    read_matrix_dim();
    read_matrix();
    update_matrix_with_random_numbers();
    second_update_matrix_with_trigonometric_rule();
    save_matrix();


}
// funcao para ler arquivo com as dimensoes da matrix, no exemplo matrix_dim.txt
void read_matrix_dim(){
    FILE *file;
    printf("Digite o caminho para o arquivo com as dimensões da matriz: \n");
    scanf("%s",&matrix_dim_address);
    file = fopen(matrix_dim_address, "r");
    if (file) {
        
        fscanf(file, "%d,%d",&LIN,&COL);
    }
        fclose(file);

}
// funcao para ler matrizes que estão em arquivos txt matrix_*.txt, no exemplo matrix_7.txt
void read_matrix(){
    FILE *file;
    printf("Digite o caminho para o arquivo da matriz: \n");
    scanf("%s",&matrix_a_address);
    file = fopen(matrix_a_address, "r");
    if (file) {
        matrix_a = (float **)malloc(LIN * sizeof(float*));
        for (i=0; i<LIN; i++)
            matrix_a[i] = (float *)malloc(COL * sizeof(float));
     
        for (i=0; i < LIN; i++)
            for (j=0; j < COL; j++)
                fscanf(file, "%2f,", &matrix_a[i][j]); 
        fclose(file);
        for (i=0; i < LIN; i++)
            for (j=0; j < COL; j++)
                printf("%.2f",matrix_a[i][j]);
    }
}
// funcao para dar update na matriz usando variaveis randomicas
void update_matrix_with_random_numbers(){
    int aux = 1;
    float a = 3.14;
    srand((unsigned)time(NULL));
    do {
        for(i=0;i<LIN;i++) {
                for(j=0;j<COL;j++) {
                    matrix_a[i][j] = ((float)rand()/(float)(RAND_MAX)) * a;
                }
        }
        aux += 1;
    } while (aux <= 10);
}
// funcao para dar segundo update usando regra de seno e cosseno
void second_update_matrix_with_trigonometric_rule(){
    for(i=0;i<LIN;i++) {
        for(j=0;j<COL;j++) {
            matrix_a[i][j] = sin(2.0*i) + cos(3.0*j);
        }
    }

}
//salva o resultado da matrix em um arquivo txt, result_random_matrix7.txt
void save_matrix(){
    FILE *file_output;
    file_output = fopen("result_random_matrix7.txt", "w");
    printf("O resultado do embaralhamento da matriz é:\n");
    for(i=0;i<LIN;i++) {
        printf("|");
        fprintf(file_output,"|");
		for(j=0;j<COL;j++) {
            printf(" ");
			printf("%.2f",matrix_a[i][j]);
            printf(" ");
            fprintf(file_output, "%.2f,",matrix_a[i][j]);
        }
  		printf("|\n");
        fprintf(file_output,"|\n");
	}
    printf("Você pode encontrá-la em: result_random_matrix7.txt\n");
    fclose(file_output);

}