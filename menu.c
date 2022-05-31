#include "menu.h"
#include <stdio.h>
#include <stdlib.h>



int qu_type(){
    printf("Введите тип данных\n1 - Int\n2 - Double\n3 - Complex\n Ввод:");
    int n;
    scanf("%d", &n);
    return n;
}
int qu_activ(){
    printf("\nДействие: \n1-Сложение векторов\n2-Вычетание векторов\n3-Скалярное произведение\n4-Векторное произведение \nВвод: ");
    int n;
    scanf("%d",&n);
    return n;
}
int qu_continue_vector(){
    int a;
    printf("\n1-Продолжить с этим вектором\n0-нет\nВвод:");
    scanf("%d",&a);
    return a;
}
int qu_continue_type(){
    int a;
    printf("\n1-Продолжить с этим типом данных\n0-нет\nВвод:");
    scanf("%d",&a);
    return a;
}int qu_continue(){
    int a;
    printf("\n0-Выход \n1-Продолжить \nВвод:");
    scanf("%d",&a);
    return a;
}



