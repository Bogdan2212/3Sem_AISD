//
// Created by Богдан Брыксин on 04.05.2022.
//

#include "LinkedListTests.h"


using namespace std;

void List_from_array_test()
{
    int items[5]={4,234,234,22,12};
    list <int>* list1 = new list<int>(items,5);
    for (int i=0;i<5;i++)
    {
        assert((*list1)[i]==items[i]);
    }
}
void List_from_list_test()
{
    int items[5]={12,43,324,545,22};
    list <int>* list1= new list<int>(items,5);
    list <int>* second=new list<int>(*list1);

    for (int i=0;i<4;i++)
    {
        assert((*list1)[i]==(*second)[i]);
    }
}
void List_Concat_test()
{
    int items[5]={22,433,212,543,33};
    int items1[2]={1,2};
    int items3[7]={123,23,22,665,2,1,2};
    list <int>* list1= new list<int>(items,5);
    list <int>* second=new list<int>(items1,2);
    second=second->Concat(*list1);
    for (int i=0;i<5;i++)
    {
        assert((*second)[i]==items3[i]);
    }

}


void List_Get_first_test()
{
    int items[5]={56,233,65,22,65};
    list <int> *list1=new list <int>(items,5);
    assert(list1->GetFirst()==items[0]);

}void List_Get_last_test()
{
    int items[5]={11,22,33,555,66};
    list <int> *list1=new list <int>(items,5);
    assert(list1->GetLast()==items[4]);

}

void List_Prepend_test()
{
    int items[5]={11,22,332,111,554};
    list <int> *list1=new list<int>(items,5);
    list1->Prepend(42);
    assert(list1->Get(0)==42);
}
void List_Append_test()
{
    int items[5]={43,544,433,65,98};
    list <int> *list1=new list<int>(items,5);
    list1->Append(42);
    assert(list1->Get(5)==42);
}
void List_InsertAt_test()
{
    int items[5]={22,33,412,22,566};
    list <int> *list1=new list<int>(items,5);
    list1->Insert_at(2,42);
    assert(list1->Get(2)==42);
}


void List_GetSubList_test()
{
    int items[5]={123,312,412,45,12};
    list <int> *list1=new list<int>(items,5);
    list <int> list2=list1->GetSubList(1,3);
    for (int i=0;i<3;i++)
    {
        assert((*list1)[i+1]==list2[i]);
    }
}
void LinkedList_tests()
{
    List_from_array_test();
    List_from_list_test();
    List_Prepend_test();
    List_Append_test();
    List_InsertAt_test();
    List_GetSubList_test();
    List_Get_last_test();
    List_Get_first_test();
    List_Concat_test();
    cout<<"Linkedlist tests successful";
}