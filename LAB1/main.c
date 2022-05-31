#include "double.h"
#include "vector.h"
#include "int.h"
#include "menu.h"
#include "Ring.h"
#include <stdio.h>
#include "complex.h"
#include <stdlib.h>


void menu() {
    int cont=1;
    while (cont==1) {
        int ask_type = qu_type();
        int cont_type = 1;
        while (cont_type == 1) {
            if (ask_type == 1) {
                printf("Введите целочисленный вектор: \n ");
                Vector *vector1 = create_int_vector();
                input_vector(vector1);
                printf("\nВведенный вектор: ");
                print_vector(vector1);

                int cont_vector = 1;
                while (cont_vector == 1) {
                    int ask_activity = qu_activ();
                    if (ask_activity == 1) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = create_int_vector();
                        input_vector(vector2);
                        Vector *result = sum_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 2) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = create_int_vector();
                        input_vector(vector2);
                        Vector *result = subtract_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 3) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = create_int_vector();
                        input_vector(vector2);
                        void *result = scalar_mult(vector1,vector2);
                        printf("Результат: \n");
                        print_value(result,vector1);
                    }
                    if (ask_activity == 4) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = create_int_vector();
                        input_vector(vector2);
                        printf("Результат: \n");
                        void** result= vector_product(vector1,vector2);
                    }

                    cont_vector = qu_continue_vector();
                }
            }
            if (ask_type == 2) {
                printf("Введите вещественный вектор:\n ");
                Vector *vector1 = creat_double_vector();
                input_vector(vector1);
                printf("\nВведенный вектор: ");
                print_vector(vector1);

                int cont_vector = 1;
                while (cont_vector == 1) {
                    int ask_activity = qu_activ();
                    if (ask_activity == 1) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_double_vector();
                        input_vector(vector2);
                        Vector *result = sum_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 2) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_double_vector();
                        input_vector(vector2);
                        Vector *result = subtract_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 3) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_double_vector();
                        input_vector(vector2);
                        void *result = scalar_mult(vector1,vector2);
                        printf("Результат: \n");
                        print_value(result,vector1);
                    }
                    if (ask_activity == 4) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_double_vector();
                        input_vector(vector2);
                        printf("Результат: \n");
                        void** result= vector_product(vector1,vector2);
                    }

                    cont_vector = qu_continue_vector();
                }
            }
            if (ask_type == 3) {
                printf("Введите комплексный вектор:\n ");
                Vector *vector1 = creat_vector_complex();
                input_vector(vector1);
                printf("\nВведенный вектор: ");
                print_vector(vector1);

                int cont_vector = 1;
                while (cont_vector == 1) {
                    int ask_activity = qu_activ();
                    if (ask_activity == 1) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_vector_complex();
                        input_vector(vector2);
                        Vector *result = sum_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 2) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_vector_complex();
                        input_vector(vector2);
                        Vector *result = subtract_vector(vector1,vector2);
                        printf("Результат: \n");
                        print_vector(result);
                    }
                    if (ask_activity == 3) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_vector_complex();
                        input_vector(vector2);
                        void *result = scalar_mult(vector1,vector2);
                        printf("Результат: \n");
                        print_value(result,vector1);
                    }
                    if (ask_activity == 4) {
                        printf("Введите второй вектор:\n ");
                        Vector *vector2 = creat_vector_complex();
                        input_vector(vector2);
                        printf("Результат: \n");
                        void** result= vector_product(vector1,vector2);
                    }

                    cont_vector = qu_continue_vector();
                }
            }

            cont_type = qu_continue_type();
        }
        cont=qu_continue();
    }

}

void test_int(){
    printf("ТЕСТЫ ДЛЯ INT:\n");
    int* pointer1=calloc(1,sizeof(int));
    *pointer1=2;
    int* pointer2=calloc(1,sizeof(int));
    *pointer2=3;
    int* pointer3=calloc(1,sizeof(int));
    *pointer3=6;
    int* pointer4=calloc(1,sizeof(int));
    *pointer4=1;
    int* pointer5=calloc(1,sizeof(int));
    *pointer5=-4;
    int* pointer6=calloc(1,sizeof(int));
    *pointer6=-3;
    //printf("Складываем вектора:\n");
    Vector* vector1=create_int_vector();
    vector1=set((void*)pointer1,(void*)pointer2,(void*)pointer3,vector1);

    Vector* vector2=create_int_vector();
    vector2=set((void*)pointer4,(void*)pointer5,(void*)pointer6,vector2);

    printf("Проверка функции sum_vector:\n");
    printf("Складываем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (3,-1,3)\nПолученный результат:");
    Vector* res=sum_vector(vector1,vector2);
    print_vector(res);
    printf("\n");
    printf("Проверка функции subtract_vector:\n");
    printf("Вычитаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (1,7,9)\nПолученный результат:");
    Vector* res1=subtract_vector(vector1,vector2);
    print_vector(res1);
    printf("\n");
    printf("Проверка функции scalar_mult:\n");
    printf("Скалярно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: -28\nПолученный результат:");
    void* res2=scalar_mult(vector1,vector2);
    print_value(res2,vector1);
    printf("\n");
    printf("Проверка функции vector_product:\n");
    printf("Векторно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: 15i+12j-11k\nПолученный результат:");
    void** res3=vector_product(vector1,vector2);
    printf("\n");
}
void test_double(){
    printf("ТЕСТЫ ДЛЯ DOUBLE:\n");
    double * pointer1=calloc(1,sizeof(double));
    *pointer1=2.5f;
    double * pointer2=calloc(1,sizeof(double ));
    *pointer2=-3.4f;
    double * pointer3=calloc(1,sizeof(double ));
    *pointer3=6.0f;
    double * pointer4=calloc(1,sizeof(double ));
    *pointer4=1.7f;
    double * pointer5=calloc(1,sizeof(double ));
    *pointer5=-4.5f;
    double * pointer6=calloc(1,sizeof(double ));
    *pointer6=-3.9f;
    //printf("Складываем вектора:\n");
    Vector* vector1=creat_double_vector();
    vector1=set((void*)pointer1,(void*)pointer2,(void*)pointer3,vector1);

    Vector* vector2=creat_double_vector();
    vector2=set((void*)pointer4,(void*)pointer5,(void*)pointer6,vector2);

    printf("Проверка функции sum_vector:\n");
    printf("Складываем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (4.20,-7.90,2.10)\nПолученный результат:");
    Vector* res=sum_vector(vector1,vector2);
    print_vector(res);
    printf("\n");
    printf("Проверка функции subtract_vector:\n");
    printf("Вычитаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (0.80,1.10,9.90)\nПолученный результат:");
    Vector* res1=subtract_vector(vector1,vector2);
    print_vector(res1);
    printf("\n");
    printf("Проверка функции scalar_mult:\n");
    printf("Скалярно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: -3.85\nПолученный результат:");
    void* res2=scalar_mult(vector1,vector2);
    print_value(res2,vector1);
    printf("\n");
    printf("Проверка функции vector_product:\n");
    printf("Векторно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: 40.26i+19.95j-5.47k\nПолученный результат:");
    void** res3=vector_product(vector1,vector2);
    printf("\n");
}


void test_complex(){
    printf("ТЕСТЫ ДЛЯ COMPLEX:\n");
    double * pointer1=calloc(1,sizeof(double));
    *pointer1=2.5f;
    double * pointer2=calloc(1,sizeof(double ));
    *pointer2=-3.4f;
    double * pointer3=calloc(1,sizeof(double ));
    *pointer3=6.0f;
    double * pointer4=calloc(1,sizeof(double ));
    *pointer4=1.7f;
    double * pointer5=calloc(1,sizeof(double ));
    *pointer5=-4.5f;
    double * pointer6=calloc(1,sizeof(double ));
    *pointer6=-3.9f;
    double * pointer7=calloc(1,sizeof(double));
    *pointer7=2.0f;
    double * pointer8=calloc(1,sizeof(double ));
    *pointer8=-3.0f;
    double * pointer9=calloc(1,sizeof(double ));
    *pointer9=6.6f;
    double * pointer10=calloc(1,sizeof(double ));
    *pointer10=2.0f;
    double * pointer11=calloc(1,sizeof(double ));
    *pointer11=-8.6f;
    double * pointer12=calloc(1,sizeof(double ));
    *pointer12=-4.1f;
    //printf("Складываем вектора:\n");
    Vector* vector1=creat_vector_complex();
    vector1= seta_complex((void*)pointer1,(void*)pointer2,(void*)pointer3,(void*)pointer4,(void*)pointer5,(void*)pointer6,vector1);

    Vector* vector2=creat_vector_complex();
    vector2=seta_complex((void*)pointer7,(void*)pointer8,(void*)pointer9,(void*)pointer10, (void*)pointer11,(void*)pointer12,vector2);

    printf("Проверка функции sum_vector:\n");
    printf("Складываем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (4.50-6.40i,12.60+3.70i,-13.10-8.00i)\nПолученный результат:");
    Vector* res=sum_vector(vector1,vector2);
    print_vector(res);
    printf("\n");
    printf("Проверка функции subtract_vector:\n");
    printf("Вычитаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (0.50-0.40i,-0.60-0.30i,4.10+0.20i)\nПолученный результат:");
    Vector* res1=subtract_vector(vector1,vector2);
    print_vector(res1);
    printf("\n");
    printf("Проверка функции scalar_mult:\n");
    printf("Скалярно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: 83.30+29.59i\nПолученный результат:");
    void* res2=scalar_mult(vector1,vector2);
    print_value(res2,vector1);
    printf("\n");
    printf("Проверка функции vector_product:\n");
    printf("Векторно умножаем вектора:\n");
    print_vector(vector1);
    printf(" и ");
    print_vector(vector2);
    printf("\n");
    printf("Ожидаемый результат: (-21.90+0.83i)i+(12.50-2.24i)j+(4.50-1.70i)k\nПолученный результат:");
    void** res3=vector_product(vector1,vector2);
    printf("\n");

}
int main(){
    menu();

    //test_int();
    //test_double();
    //test_complex();















    /*Vector* vector1=creat_double_vector();
    input_vector(vector1);
    print_vector(vector1);

    Vector* vector2=creat_double_vector();
    input_vector(vector2);
    print_vector(vector2);

    Vector* vector3;
    vector3= sum_vector(vector1,vector2);
    print_vector(vector3);

    scalar_mult(vector1,vector2);*/

    /*Vector* vector1= creat_vector_complex();
    input_vector(vector1);
    print_vector(vector1);
    Vector* vector2= creat_vector_complex();
    input_vector(vector2);
    print_vector(vector2);
    void** res = vector_product(vector1,vector2);*/
    /*print_value(res[0],vector1);
    print_value(res[1],vector1);
    print_value(res[2],vector1);*/
    //print_value(res,vector2);



    //vector_product(vector1,vector2);
    /*Vector* vector2= creat_vector_complex();


    input_vector(vector2);
    print_vector(vector2);
    printf("\n");*/
    //vector_product(vector1,vector2);

    return 0;
}