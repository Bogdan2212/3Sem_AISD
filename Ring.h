//
// Created by olga_ on 12.03.2022.
//

#ifndef LAB6_RING_H
#define LAB6_RING_H
typedef struct RingInfo{
    void* (*sum)(void* a, void* b);
    void* (*mult)(void* a, void* b);
    void* (*subtract)(void* a, void* b);
    void* (*input)();
    void (*print)(void* value);
    void* (*inverse_element)(void* value);
}RingInfo;

RingInfo *creat_Ring(void *(*sum)(void *a, void *b),
                     void *(*mult)(void *a, void *b),
                     void *(*subtract)(void *a, void *b),
                     void *(*input)(),
                     void (*print)(void *value), void* (*inverse_element)(void* value));
#endif //LAB6_RING_H