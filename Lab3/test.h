#ifndef TEST_H
#define TEST_H
#include <cassert>
#include "BinTree.hpp"

void add_test();//проверка добавления элемента
void del_test();//Проверка удаления элемента дерева
void Tostr_test();//Проверка записи дерева в строку
void Check_element_test();//Тест функции проверки наличия элемента дерева
void CheckSubTree_test();//Тест функции проверки наличия поддерева дерева
void Get_SubTree_test();//Тест получения поддерева дерева
void Concat_test();//Тест слияния деревьев
void Where_test();
void Map_test();
void Bintree_test();//Все тесты бинарного дерева
bool More(int a);
int mult(int a);
#endif //TEST_H
