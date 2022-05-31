//
// Created by Богдан Брыксин on 11.03.2022.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>



void* sum_double(void* a, void* b){
    double* result=(double *)malloc(sizeof(double*));
    double* sum_a=(double*)a;
    double* sum_b=(double*)b;
    *result=*sum_a + *sum_b;
    return (void*)result;
}

void* mult_double(void* a, void* b){
    double* result=(double*)malloc(sizeof(double*));
    double* mult_a=(double*)a;
    double* mult_b=(double*)b;
    *result=(*mult_a) * (*mult_b);
    return (void*)result;
}

void* subtract_double(void* a, void* b){
    double* result=(double*)malloc(sizeof(double*));
    double* subtract_a=(double*)a;
    double* subtract_b=(double*)b;
    *result=(*subtract_a) - (*subtract_b);
    return (void*)result;
}

void* input_double(){
    double* value=(double*)malloc(sizeof(double*));
    char answer[256];
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%lf", &(*value)) != 1) {
        fgets(answer, sizeof(answer), stdin);
    }
    return (void*)value;
}

void print_double(void* value){
    printf("%.2lf", *(double*)value);
}

void* inverse_element_double(void *value){
    double *res= (double *)malloc(sizeof(double *));
    *res=*(double *)value*-1.0f;
    return (void*)res;
}

Vector* creat_double_vector(){
    RingInfo* double_ring= creat_Ring(sum_double,mult_double,subtract_double,input_double,print_double, inverse_element_double);
    Vector* vector= creat_vector(double_ring);

    return vector;
}