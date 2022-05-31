//
// Created by olga_ on 12.03.2022.
//

#include "Ring.h"
#include <stdio.h>
#include <stdlib.h>
RingInfo *creat_Ring(void *(*sum)(void *a, void *b),
                     void *(*mult)(void *a, void *b),
                     void *(*subtract)(void *a, void *b),
                     void *(*input)(),
                     void (*print)(void *value), void* (*inverse_element)(void* value)){
    RingInfo* Res_Ring=(RingInfo*)malloc(sizeof(RingInfo));
    Res_Ring->sum=sum;
    Res_Ring->mult=mult;
    Res_Ring->subtract=subtract;
    Res_Ring->print=print;
    Res_Ring->input=input;
    Res_Ring->inverse_element=inverse_element;
    return Res_Ring;
}