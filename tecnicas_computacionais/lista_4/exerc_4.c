/*  Lista : 4
    Exercício: 4
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//definindo variaveis globais
int i,j,k;
float matrix_a [3][3];
char matrix_a_address [50];

// instanciando métodos
void update_matrix_with_random_numbers();
void read_matrix();
void save_matrix();
// estrutura principal
int main() {

    read_matrix();
    update_matrix_with_random_numbers();
    save_matrix();


}
// funcao para ler matrizes que estão em arquivos txt matrix_*.txt. no exemplo matrix_a.txt
void read_matrix(){

    int i = 0;
    int c;
    FILE *file;
    
    printf("Digite o caminho para o arquivo da matriz: \n");
    scanf("%s",&matrix_a_address);
    file = fopen(matrix_a_address, "r");
    if (file) {
        for(i=0;i<3;i++) {
		    for(j=0;j<3;j++) {
                fscanf(file, "%2f,", &matrix_a[i][j]);
            }
        }
        fclose(file);
    }
}
// funcao para dar update na matriz usando variaveis randomicas
void update_matrix_with_random_numbers(){
    int aux = 1;
    float a = 3.14;
    srand((unsigned)time(NULL));
    do {
        for(i=0;i<3;i++) {
                for(j=0;j<3;j++) {
                    matrix_a[i][j] = ((float)rand()/(float)(RAND_MAX)) * a;
                }
        }
        aux += 1;
    } while (aux <= 10);
}
//salva o resultado da matrix em um arquivo txt, result_random_matrix2.txt
void save_matrix(){
    FILE *file_output;
    file_output = fopen("result_random_matrix2.txt", "w");
    printf("O resultado do embaralhamento da matriz é:\n");
    for(i=0;i<3;i++) {
        printf("|");
        fprintf(file_output,"|");
		for(j=0;j<3;j++) {
            printf(" ");
			printf("%.2f",matrix_a[i][j]);
            printf(" ");
            fprintf(file_output, "%.2f,",matrix_a[i][j]);
        }
  		printf("|\n");
        fprintf(file_output,"|\n");
	}
    printf("Você pode encontrá-la em: result_random_matrix2.txt\n");
    fclose(file_output);

}