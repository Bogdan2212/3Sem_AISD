#include "Ring.h"
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

typedef struct Vector{
    void* x;
    void* y;
    void* z;
    size_t size;
    RingInfo* Ring;
}Vector;
Vector* creat_vector(RingInfo* Ring_info){
    Vector* Vector_res=(Vector*)malloc(sizeof(Vector));
    Vector_res->Ring=Ring_info;
    return Vector_res;
}

Vector* input_vector(Vector* vector){
    printf("Введите координату х:");
    vector->x=vector->Ring->input();
    printf("Введите координату y:");
    vector->y=vector->Ring->input();
    printf("Введите координату z:");
    vector->z=vector->Ring->input();
    return vector;
}



void print_vector(Vector *vector){
    printf("(");
    vector->Ring->print(vector->x);
    printf(",");
    vector->Ring->print(vector->y);
    printf(",");
    vector->Ring->print(vector->z);
    printf(")");
}

Vector* sum_vector(Vector* vector_A,Vector* vector_B){
    Vector * Vector_res=creat_vector(vector_A->Ring);
    Vector_res->x=vector_A->Ring->sum(vector_A->x,vector_B->x);
    Vector_res->y=vector_A->Ring->sum(vector_A->y,vector_B->y);
    Vector_res->z=vector_A->Ring->sum(vector_A->z,vector_B->z);
    return Vector_res;
}



Vector* subtract_vector(Vector* vector_A, Vector* vector_B){
    Vector * Vector_res=creat_vector(vector_A->Ring);
    Vector_res->x=vector_A->Ring->subtract(vector_A->x,vector_B->x);
    Vector_res->y=vector_A->Ring->subtract(vector_A->y,vector_B->y);
    Vector_res->z=vector_A->Ring->subtract(vector_A->z,vector_B->z);
    return Vector_res;
}

void* scalar_mult(Vector* vector_A,Vector* vector_B){
    void* res=vector_A->Ring->sum(vector_A->Ring->sum(vector_A->Ring->mult(vector_A->x,vector_B->x),vector_A->Ring->mult(vector_A->y,vector_B->y)),vector_A->Ring->mult(vector_A->z,vector_B->z));
    //vector_A->Ring->print(res);
    return res;
}

void print_value(void* value,Vector* vector){
    vector->Ring->print(value);
}

Vector* set(void* x, void* y, void* z, Vector* vector){
    vector->x=x;
    vector->y=y;
    vector->z=z;
    return vector;
}

Vector* seta_complex(void* RezX, void* ImzX, void* RezY, void* ImzY,void* RezZ, void* ImzZ, Vector* vector){
    Complex* result1 = (Complex *) malloc(sizeof(Complex));
    result1->Rez = *(double *)RezX;
    result1->Imz = *(double *)ImzX;
    vector->x=(void*)result1;
    Complex* result2 = (Complex *) malloc(sizeof(Complex));
    result2->Rez = *(double *)RezY;
    result2->Imz = *(double *)ImzY;
    vector->y=(void*)result2;
    Complex* result3 = (Complex *) malloc(sizeof(Complex));
    result3->Rez = *(double *)RezZ;
    result3->Imz = *(double *)ImzZ;
    vector->z=(void*)result3;
    return vector;
}

void print_vector_product(void** all, Vector* vector){
    //printf("\n");
    printf("(");
    vector->Ring->print(all[0]);
    printf(")");
    printf("i+");
    printf("(");
    vector->Ring->print(all[1]);
    printf(")");
    printf("j+");
    printf("(");
    vector->Ring->print(all[2]);
    printf(")");
    printf("k");
}

void** vector_product(Vector* vector_A, Vector* vector_B){
    void* i=vector_A->Ring->subtract(vector_A->Ring->mult(vector_A->y,vector_B->z),vector_A->Ring->mult(vector_A->z,vector_B->y));
    void* j=vector_A->Ring->inverse_element(vector_A->Ring->subtract(vector_A->Ring->mult(vector_A->x,vector_B->z),vector_A->Ring->mult(vector_A->z,vector_B->x)));
    void* k=vector_A->Ring->subtract(vector_A->Ring->mult(vector_A->x,vector_B->y),vector_A->Ring->mult(vector_A->y,vector_B->x));
    void** all;
    all=(void**) malloc(sizeof(void*)*3);
    all[0]=i;
    all[1]=j;
    all[2]=k;
    print_vector_product(all,vector_A);
    return all;

}

