//
// Created by Богдан Брыксин on 13.03.2022.
//

#ifndef UNTITLED4_COMPLEX_H
#define UNTITLED4_COMPLEX_H
#include "complex.h"
#include "Ring.h"
#include "vector.h"

typedef struct Complex{
    double Rez;
    double Imz;
}Complex;

void* sum_complex(void* a,void* b);

void* mult_complex(void* a,void* b);
void* subtract_complex(void* a,void* b);

void* inverse_element_complex(void* value);

void* input_complex();

void print_complex(void* value);
Vector* creat_vector_complex();
#endif //UNTITLED4_COMPLEX_H
