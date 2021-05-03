/*  Lista : 1
    Exercício: 4
    Aluno: Lucas Magalhães Espinosa Ferreira
    Mestrado em Modelagem Computacional 2021/1     */

#include <stdio.h>

int return_char();
int return_string();

int main() {

    return_char();
    return_string();
    


}
int return_string(){
    char msg[] = "Hello Students";
    puts(msg);
    return 0;
}
int return_char(){
    char letter = "f";
    printf("%c",letter);
    return 0;
}