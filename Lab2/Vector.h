//
// Created by Богдан Брыксин on 06.05.2022.
//

#ifndef UNTITLED7_VECTOR_H
#define UNTITLED7_VECTOR_H
#include "LinkedListSequence.h"
#include <iostream>
#include "LinkedList.h"
#include "Sequence.h"
#include "myexception.h"
#include "cmath"

using namespace std;

template<class T> class Vector{
private:
    LinkedListSequence<T> *vector;  //Вектор на основе LinkedListSequence
public:
    Vector();   //Конструкторы
    Vector(int k);
    Vector(T* arr,int k);
public:                         //Функции с векторами
    void input_vector(int k);       //Ввод вектора с консоли
    void append(T value,Vector<T> *v1);       //Добавление элемента в вектор
    Vector<T>* Sum_Vector(Vector<T> *v1, Vector<T> *v2);    //Сумма двух векторов
    Vector<T>* Multiply_On_Scalar_Vector(Vector<T> *v1, T value);   //Умножение вектора на скаляр
    T Module_Vector(Vector<T> *v1);         //Норма вектора
    T Scalar_Product_Vector(Vector<T> *v1,Vector<T> *v2);   //Скалярное произведение векторов
    int Get_ln_Vector(Vector<T> *v1);       //Длинна вектора
    T Get_Value_index(Vector<T> *v1,int index);     //Получение значения вектора по индексу



};

template<class T>
void Vector<T>::append(T value, Vector<T> *v1){
    v1->vector->Append(value);
}

template<class T>
T Vector<T>::Get_Value_index(Vector<T> *v1, int index){
    T res;
    res=v1->vector->Get(index);
    return res;
}


template<class T>
int Vector<T>::Get_ln_Vector(Vector<T> *v1) {
    int k;
    k=v1->vector->GetLength();
    return k;
}



template<class T>
ostream & operator << (ostream & out, Vector<T> *v1){
    int k;
    k=v1->Get_ln_Vector(v1);
    cout<<"(";
    for(int i=0;i<k;i++){
        out<<v1->Get_Value_index(v1,i);
        if (i==k-1)
            break;
        cout<<",";
    }
    cout<<")";
    return out;
}

template<class T>
Vector<T>::Vector(){
    vector=new LinkedListSequence<T>();
}

template<class T>
Vector<T>::Vector(int k){
    vector=new LinkedListSequence<T>(k);
}

template<class T>
Vector<T>::Vector(T* arr,int k){
    vector=new LinkedListSequence<T>(arr,k);
}


template<class T>
Vector<T>* Vector<T>::Sum_Vector(Vector<T> *v1, Vector<T> *v2){
    int k;
    k=v1->vector->GetLength();
    Vector<T> *res=new Vector<T>();
    for(int i=0 ;i<k; i++){
        res->vector->InsertAt((v1->vector->Get(i))+(v2->vector->Get(i)),i);
    }
    return res;
}

template<class T>
Vector<T>* Vector<T>:: Multiply_On_Scalar_Vector(Vector<T> *v1, T value){
    int k;
    k=v1->vector->GetLength();
    Vector<T> *res=new Vector<T>();
    for(int i=0;i<k;i++){
        res->vector->InsertAt(v1->vector->Get(i)*value,i);
    }
    return res;
}

template<class T>
T Vector<T>::Module_Vector(Vector<T> *v1) {
    T res;
    int k;
    k=v1->vector->GetLength();
    for(int i=0;i<k;i++){
        res=res+(v1->vector->Get(i))*(v1->vector->Get(i));
    }
    res= sqrt(res);
    return res;
}

//template<class T>
//T Vector<T>::Scalar_Product_Vector(Vector<T> *v1,Vector<T> *v2) {
//    T res;
//    int k;
//    k=v1->vector->GetLength();
//    for(int i=0;i<k;i++){
//        res=res+v1->vector->Get(i)*v2->vector->Get(i);
//    }
//    return res;
//}

template<class T>
T Vector<T>::Scalar_Product_Vector(Vector<T> *v1,Vector<T> *v2) {
    T res;
    int k;
    k=v1->vector->GetLength();
    res=v1->vector->Get(0)*v2->vector->Get(0);
    for(int i=1;i<k;i++){
        res=res+v1->vector->Get(i)*v2->vector->Get(i);
    }
    return res;
}


template<class T>
void Vector<T>::input_vector(int k) {
    T value;
    for(int i=0;i<k;i++){
        value=0;
        cin>>value;
        vector->Append(value);
    }
}



/*template<class T>
void Vector<T>::print_vector() {
    int k;
    k=vector->GetLength();
    cout<<"(";
    for(int i=0;i<k;i++){
        cout<<vector->Get(i);
        if (i==k-1)
            break;
        cout<<",";
    }
    cout<<")";
}*/




#endif //UNTITLED7_VECTOR_H
