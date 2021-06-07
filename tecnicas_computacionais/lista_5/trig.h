#ifndef __TRIG_H__
    #define __TRIG_H__
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

// declaroando variaveis que vao ser usadas
    float a,b,result;

// soma dos senos

    void sin_sum(float a, float b) {

    result = (sin(a) * cos(b)) + (sin(b) * cos(a));
    printf("O resultado de sen( %f + %f ) é: %f",a,b,result);



    }

// diferença dos senos

    void sin_diff(float a, float b) {

        result = (sin(a) * cos(b)) - (sin(b) * cos(a));
        printf("O resultado de sen( %f - %f ) é: %f",a,b,result);



    }
// soma dos cossenos
    void cos_sum(float a, float b) {

        result = (cos(a) * cos(b)) - (sin(a) * sin(b));
        printf("O resultado de cos( %f + %f ) é: %f",a,b,result);



    }
// diferença dos cossenos
    void cos_diff(float a, float b) {

        result = (cos(a) * cos(b)) + (sin(a) * sin(b));
        printf("O resultado de cos( %f - %f ) é: %f",a,b,result);



    }
// soma das tangentes
    void tan_sum(float a, float b) {
        result = (tan(a) + tan(b)) / (1 - (tan(a) * tan(b)));
        printf("O resultado de tan( %f + %f ) é: %f",a,b,result);

    }
// diferença das tangentes
    void tan_diff(float a, float b) {
        result = (tan(a) - tan(b)) / (1 + (tan(a) * tan(b)));
        printf("O resultado de tan( %f - %f ) é: %f",a,b,result);

    }

#endif