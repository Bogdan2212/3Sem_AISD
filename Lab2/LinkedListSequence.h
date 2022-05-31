//
// Created by Богдан Брыксин on 22.04.2022.
//

#ifndef UNTITLED7_LINKEDLISTSEQUENCE_H
#define UNTITLED7_LINKEDLISTSEQUENCE_H
#include <iostream>
#include "LinkedList.h"
#include "Sequence.h"
#include "myexception.h"
using namespace std;



template <class T> class LinkedListSequence: public Sequence<T>
{
private:
    list<T> *items;
public:
    LinkedListSequence (T* items, int count);
    LinkedListSequence ();
    LinkedListSequence (int k);
    LinkedListSequence (const list <T> & prevlist );
    ~LinkedListSequence();
public:
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    int GetLength() override;
    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    Sequence <T>* Concat(Sequence <T> *list) override; //переделать
    void print() override;
    T& operator[](int index)override;
};


template <class T>
T& LinkedListSequence<T>::operator[](int index)
{
    if (index<0 || index>items->getCount()){
        Myexception(1).show();
    }
    else {
        return (*items)[index];
    }
}

template <class T>
LinkedListSequence<T>::LinkedListSequence() {
    items= new list<T>();
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(int k) {
    items= new list<T>(k);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(T* arr,int k) {
    items=new list<T>(arr,k);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(const list <T> & prevlist ) {
    items= new list<T>(prevlist);
}

template <class T>
LinkedListSequence<T>::~LinkedListSequence() {
    items->clear();
}

template <class T>
int LinkedListSequence<T>::GetLength() {
    return items->getCount();
}

template <class T>
T LinkedListSequence<T>::Get(int index) {
    try {
        return items->Get(index);
    }
    catch (Myexception ex){
        ex.show();
    }
}

template <class T>
T LinkedListSequence<T>::GetFirst() {
    return items->GetFirst();
}

template <class T>
T LinkedListSequence<T>::GetLast() {
    return items->GetLast();
}

template <class T>
Sequence <T>* LinkedListSequence<T>::GetSubsequence(int startindex,int endindex )
{
    auto* sub= new LinkedListSequence<T>(items->GetSubList(startindex,endindex));
    return sub;


}

template <class T>
void LinkedListSequence<T>::Append(T item) {
    try {InsertAt(item,items->getCount());}
    catch(Myexception ex)
    {
        ex.show();
    };
}

template <class T>
void LinkedListSequence<T>::Prepend(T item) {
    try {InsertAt(item,0);}
    catch(Myexception ex)
    {
        ex.show();
    };
}

template <class T>
void LinkedListSequence<T>::InsertAt(T item, int index) {
    try {items->Insert_at(index,item);}
    catch(Myexception &ex)
    {
        throw ex;
    }
}


template <class T>
Sequence <T>* LinkedListSequence<T>::Concat(Sequence<T> * list)
{
    if (list==NULL)
    {
        Myexception(2).show();

    }
    else {
        try {
            auto *resultList = new LinkedListSequence<T>;
            *(resultList->items) = *(items);

            for (int i = 0; i < list->GetLength(); i++) {
                resultList->Append(list->Get(i));
            }
            return resultList;
        }
        catch (Myexception ex) {
            ex.show();

        }
    }
}

template <class T>
void LinkedListSequence<T>::print() {
    items->PrintList();
}


#endif //UNTITLED7_LINKEDLISTSEQUENCE_H
