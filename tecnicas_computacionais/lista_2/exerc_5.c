/*  Lista : 2
    Exercício: 5
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>
#include <stdlib.h>

//definindo variaveis globais
char choice;
int i,j,k;
int vector_a [3];
int vector_b [3];
int matrix_a [3][3];
int matrix_b [3][3];
char vector_a_address [50];
char vector_b_address [50];
char matrix_a_address [50];
char matrix_b_address [50];

// instanciando métodos
void read_vectors();
void read_matrix();
void calculate_scalar_product();
void calculate_vectorial_product();
void calculate_matrix_sum();
void calculate_matrix_multiplication();
// estrutura principal
int main() {
    // coloquei um switch para um menu mais interativo
    printf("Bem Vindo a Calculadora de Geometria Analítica e Álgebra Linear!!!\n\n");
    printf("Digite a opção Desejada:\n1 - Cálculo produto escalar\n2 - Cálculo produto vetorial\n3 - Soma de matrizes 3x3\n4 - Multiplicação de matrizes 3x3\n");
    scanf("%c",&choice);
    switch (choice) {
        case '1':
            read_vectors();
            calculate_scalar_product();
            break;
        case '2':
            read_vectors();
            calculate_vectorial_product();
            break;
        case '3':
            read_matrix();
            calculate_matrix_sum();
            break;
        case '4':
            read_matrix();
            calculate_matrix_multiplication();
            break;
        default:
            printf("O caracter %c não é uma opção válida!!!\n",choice);
            break;

    }
}

// funcao para ler os vetores que estão em arquivos txt vector_*.txt
void read_vectors(){
    int i = 0;
    int c;
    FILE *file;
    FILE *file2;
    printf("Digite o caminho para o arquivo do primeiro vetor: \n");
    scanf("%s",&vector_a_address);
    printf("Digite o caminho para o arquivo do segundo vetor: \n");
    scanf("%s",&vector_b_address);
    file = fopen(vector_a_address, "r");
    file2 = fopen(vector_b_address, "r");
    if (file && file2) {
        for (j = 0; j < 3 ; j++){
            fscanf(file, "%1d,", &vector_a[j]);
            fscanf(file2, "%1d,", &vector_b[j]);
        }
        fclose(file);
        fclose(file2);
    }
}

// funcao para ler matrizes que estão em arquivos txt matrix_*.txt
void read_matrix(){

    int i = 0;
    int c;
    FILE *file;
    FILE *file2;
    printf("Digite o caminho para o arquivo da primeira matriz: \n");
    scanf("%s",&matrix_a_address);
    printf("Digite o caminho para o arquivo da segunda matriz: \n");
    scanf("%s",&matrix_b_address);
    file = fopen(matrix_a_address, "r");
    file2 = fopen(matrix_b_address, "r");
    if (file && file2) {
        for(i=0;i<3;i++) {
		    for(j=0;j<3;j++) {
                fscanf(file, "%1d,", &matrix_a[i][j]);
                fscanf(file2, "%1d,", &matrix_b[i][j]);
            }
        }
        fclose(file);
        fclose(file2);
    }
}

// funcao para calcular a sima de matrizes 3x3
void calculate_matrix_sum(){
    int matrix_c [3][3];
    FILE *file_output;
    for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
            
			matrix_c[i][j] = (matrix_a[i][j] + matrix_b[i][j]);
        }
    }
    file_output = fopen("result_matrix_sum.txt", "w");
    printf("O resultado da soma das matrizes é:\n");
    for(i=0;i<3;i++) {
        printf("|");
        fprintf(file_output,"|");
		for(j=0;j<3;j++) {
			printf("%5d",matrix_c[i][j]);
            fprintf(file_output, "%5d,",matrix_c[i][j]);
        }
  		printf("|\n");
        fprintf(file_output,"|\n");
	}
    printf("Você pode encontrá-la em: result_matrix_sum.txt\n");
    fclose(file_output);
}

// funcao para calcular multiplicacao de matrizes 3x3
void calculate_matrix_multiplication(){
    int matrix_c [3][3];
    int sum = 0;
    FILE *file_output;
    for (i = 0; i <= 2; i++) {
      for (j = 0; j <= 2; j++) {
         sum = 0;
         for (k = 0; k <= 2; k++) {
            sum = sum + matrix_a[i][k] * matrix_b[k][j];
         }
         matrix_c[i][j] = sum;
      }
   }

    file_output = fopen("result_matrix_multiplication.txt", "w");
    printf("O resultado da multiplicação das matrizes é:\n");
    for(i=0;i<3;i++) {
        printf("|");
        fprintf(file_output,"|");
		for(j=0;j<3;j++) {
			printf("%5d",matrix_c[i][j]);
            fprintf(file_output, "%5d,",matrix_c[i][j]);
        }
  		printf("|\n");
        fprintf(file_output,"|\n");
	}
    printf("Você pode encontrá-la em: result_matrix_multiplication.txt\n");
    fclose(file_output);
}

//funcao para calcular o produto escalar de dois vetores em R³
void calculate_scalar_product(){
    int aux_var=0;
    int result=0;
    FILE *file_output;
    for(i=0; i < 3; i++) {
        aux_var = (vector_a[i] * vector_b[i]);
        result += aux_var;
    }
    file_output = fopen("result_vector_scalar.txt", "w");
    printf("\nO resultado do produto escalar é: %d, você pode encontrá-lo em: result_vector_scalar.txt\n", result);
    fprintf(file_output, "O resultado do produto escalar é: %d\n",result);
    fclose(file_output);
}

//funcao para calcular o produto vetorial de dois vetores em R³
void calculate_vectorial_product(){
    FILE *file_output;
    int element_i = ((vector_a[1] * vector_b[2]) - (vector_a[2] * vector_b[1]));
    int element_j = ((vector_a[2] * vector_b[0]) - (vector_a[0] * vector_b[2]));
    int element_k = ((vector_a[0] * vector_b[1]) - (vector_a[1] * vector_b[0]));
    printf("\nO resultado do produto vetorial é: (%di,%dj,%dk), você pode encontrá-lo em: result_vector_product.txt\n", element_i,element_j,element_k);
    file_output = fopen("result_vector_product.txt", "w");
    fprintf(file_output, "O resultado do produto vetorial é: (%di,%dj,%dk)",element_i,element_j,element_k);
    fclose(file_output);
}