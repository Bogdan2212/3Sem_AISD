//
// Created by Богдан Брыксин on 13.03.2022.
//
#include "complex.h"
#include "Ring.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>



void* sum_complex(void* a,void* b){
    Complex* result = (Complex *) malloc(sizeof(Complex));
    Complex* sum_a = (Complex *) a;
    Complex* sum_b = (Complex *) b;
    result->Rez=sum_a->Rez+sum_b->Rez;
    result->Imz=sum_a->Imz+sum_b->Imz;
    return (void *) result;

}

void* mult_complex(void* a,void* b){
    Complex* result = (Complex *) malloc(sizeof(Complex));
    Complex* sum_a = (Complex *) a;
    Complex* sum_b = (Complex *) b;
    result->Rez=sum_a->Rez*sum_b->Rez;
    result->Imz=sum_a->Imz*sum_b->Imz;
    return (void *) result;

}
void* subtract_complex(void* a,void* b){
    Complex* result = (Complex *) malloc(sizeof(Complex));
    Complex* sum_a = (Complex *) a;
    Complex* sum_b = (Complex *) b;
    result->Rez=sum_a->Rez-sum_b->Rez;
    result->Imz=sum_a->Imz-sum_b->Imz;
    return (void *) result;
}

void* inverse_element_complex(void* value){
    Complex* result=(Complex*)value;
    result->Rez=result->Rez*-1.0f;
    result->Imz=result->Imz*-1.0f;
    return (void*)result;
}

void* input_complex(){
    Complex* result = (Complex *) malloc(sizeof(Complex));
    printf("(действительную часть комплексного числа)");
    char answer[256];
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%lf", &(result->Rez)) != 1) {
        fgets(answer, sizeof(answer), stdin);
    }
    //printf("\n");
    printf("(мнимую часть комплексного числа)");
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%lf", &(result->Imz)) != 1) {
        fgets(answer, sizeof(answer), stdin);
    }

    return (void*)result;
}

void print_complex(void* value){
    Complex* result = (Complex *)value;
    if (result->Imz>= 0.0f) {
        printf("%.2lf+", result->Rez);
        printf("%.2lfi", result->Imz);
    }else{
        printf("%.2lf", result->Rez);
        printf("%.2lfi", result->Imz);
    }
}

Vector* creat_vector_complex(){
    RingInfo* complex_ring= creat_Ring(sum_complex,mult_complex,subtract_complex,input_complex,print_complex,inverse_element_complex);
    Vector* complex_vector= creat_vector(complex_ring);
    return complex_vector;
}