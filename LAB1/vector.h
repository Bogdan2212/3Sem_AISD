//
// Created by olga_ on 12.03.2022.
//
#include "Ring.h"
#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H

typedef struct Vector Vector;
Vector * creat_vector(RingInfo* Ring_info);


Vector* input_vector(Vector* vector);

void print_vector(Vector *vector);

Vector* sum_vector(Vector* vector_A,Vector* vector_B);

Vector* subtract_vector(Vector* vector_A, Vector* vector_B);
void print_value(void* value,Vector* vector);
void* scalar_mult(Vector* vector_A,Vector* vector_B);
void** vector_product(Vector* vector_A, Vector* vector_B);
Vector* set(void* x, void* y, void* z, Vector* vector);
Vector* seta_complex(void* RezX, void* ImzX, void* RezY, void* ImzY,void* RezZ, void* ImzZ, Vector* vector);

#endif //LAB6_VECTOR_H
