#ifndef __VECTOR_H__
    #define __VECTOR_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    // definindo estruturas e variaveis globais
    struct vector {

        float x;
        float y;
        float z;
    };
    float result;
    struct vector vector_a;
    struct vector vector_b;
    // definindo funcoes
    void create_vector_a_coordinates();
    void create_vector_b_coordinates();
    void access_coordinates(struct vector v);
    float scalar_product(struct vector i, struct vector j);
    char vectorial_product(struct vector i, struct vector j);

    //funcao para ler coordenas e gravar no objeto struct
    void create_vector_a_coordinates() {

        printf("Digite o valor para primeira coordenada:\n");
        scanf("%f",&vector_a.x);

        printf("Digite o valor para segunda coordenada:\n");
        scanf("%f",&vector_a.y);

        printf("Digite o valor para terceira coordenada:\n");
        scanf("%f",&vector_a.z);


    }
     //funcao para ler coordenas e gravar no objeto struct
    void create_vector_b_coordinates() {

        printf("Digite o valor para primeira coordenada:\n");
        scanf("%f",&vector_b.x);

        printf("Digite o valor para segunda coordenada:\n");
        scanf("%f",&vector_b.y);

        printf("Digite o valor para terceira coordenada:\n");
        scanf("%f",&vector_b.z);


    }
    /* funcao para acessar coordenadas 
    (elementos do objeto struct) */
    void access_coordinates(struct vector v) {
        printf("Acessando o vetor:\n");
        printf("x: %f \n",v.x);
        printf("y: %f \n",v.y);
        printf("z: %f \n",v.z);

    }

    // funcao para calculo do produto escalar
    float scalar_product(struct vector i, struct vector j) {

        float sum_x,sum_y,sum_z,result;

        sum_x = (i.x * j.x);
        sum_y = (i.y * j.y);
        sum_z = (i.z * j.z);
        
        result = sum_x + sum_y + sum_z;

        return result;

    }
    
    // funcao para calculo do produto vetorial
    char vectorial_product(struct vector i, struct vector j) {

        float element_i = ((i.y * j.z) - (i.z * j.y));
        float element_j = ((i.z * j.x) - (i.x * j.z));
        float element_k = ((i.x * j.y) - (i.y * j.x));

        return printf("(%fi,%fj,%fk)",element_i,element_j,element_k);
        
    }



#endif