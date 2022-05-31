//
// Created by Богдан Брыксин on 11.03.2022.
//

#include "Ring.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void *sum_int(void *a, void *b) {
    int *result = (int *) malloc(sizeof(int *));
    int *sum_a = (int *) a;
    int *sum_b = (int *) b;
    *result = *sum_a + *sum_b;
    return (void *) result;
}

void *mult_int(void *a, void *b) {
    int *result = (int *) malloc(sizeof(int *));
    int *mult_a = (int *) a;
    int *mult_b = (int *) b;
    *result = (*mult_a) * (*mult_b);
    return (void *) result;
}

void *subtract_int(void *a, void *b) {
    int *result = (int *) malloc(sizeof(int *));
    int *subtract_a = (int *) a;
    int *subtract_b = (int *) b;
    *result = (*subtract_a) - (*subtract_b);
    return (void *) result;
}

void *input_int() {

    int *value = (int *) malloc(sizeof(int*));
    char answer[256];
    fgets(answer, sizeof(answer), stdin);
    while (sscanf(answer, "%d", &(*value)) != 1) {
        fgets(answer, sizeof(answer), stdin);
    }
    return (void *) value;
}

void print_int(void *value) {

    printf("%d", *(int *) value);
}

void* inverse_element_int(void *value){
    int *res= (int*)malloc(sizeof(int*));
    *res=*(int*)value*-1;
    return (void*)res;
}


Vector *create_int_vector() {
    RingInfo * int_ring= creat_Ring(sum_int,mult_int,subtract_int,input_int,print_int,inverse_element_int);
    Vector *int_vector = creat_vector(int_ring);
    return int_vector;
}

//printf("%f+i%f );