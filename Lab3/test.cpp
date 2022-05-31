#include "test.h"
#include <iostream>
using namespace std;
void add_test()
{
    BinTree<int>* tree=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    assert(tree->Get_Data() == 12);
    assert(tree->Get_left()->Get_Data() == 10);
    assert(tree->Get_right()->Get_Data() == 13);
}

void del_test()
{
    BinTree<int>* tree=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    tree->del(tree,13);
    tree->del(tree,10);
    assert(tree->Get_left()==nullptr);
    assert(tree->Get_right()==nullptr);
}

void Tostr_test()
{
    BinTree<int>* tree=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    tree->Insert(tree, 9);
    tree->Insert(tree, 8);
    string str12="12 10 9 8 13 ";
    string *str=new string();
    string *str1=new string(str12);
    str=tree->ToStr(tree, str);
    for (int i=0;i<12;i++)
    {
        assert(str[i]==str1[i]);
    }

}

void Check_element_test()
{
    BinTree<int>* tree=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    bool cont = tree->Tree_Element_Check(tree, 10);
    assert(cont == true);
}

void CheckSubTree_test()
{
    BinTree<int>* tree=nullptr;;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    BinTree<int>* tree2=nullptr;
    tree2->Insert(tree2, 10);
    tree2->Insert(tree2, 13);
    bool ans=tree->Check_Sub_Tree(tree, tree2);
    assert(ans==true);
}

void Get_SubTree_test()
{
    BinTree<int>* tree=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    tree->Insert(tree, 90);
    tree->Insert(tree, 11);
    tree->Insert(tree, 9);
    tree->Insert(tree, 87);
    BinTree<int>* tree2=tree->Get_subTree(tree, 10);
    string *str=new string ();
    string *str22=tree2->ToStr(tree2, str);
    cout<<str22[0];
    string str12="10 9 11";
    for (int i=0;i<str->length();i++)
        assert(str12[i]==str22[0][i]);
}

void Concat_test()
{
    BinTree<int>* tree=nullptr;
    BinTree<int>* tree2=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    tree->Insert(tree, 90);
    tree2->Insert(tree2, 80);
    tree2->Insert(tree2, 7);
    tree2->Insert(tree2, 67);
    tree2->Concat(tree,tree2);
    string *str=new string();
    string str2="80 7 67 10 13 12 90";


    string *str3=tree2->ToStr(tree2, str);
    for (int i=0;i<str->length();i++)
        assert(str[i]==str3[i]);
}
int mult(int a)
{
    return a*8;
}
void Map_test()
{
    BinTree<int>* tree=nullptr;
    BinTree<int>* tree2=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 13);
    tree->Insert(tree, 90);
    tree2=tree2->Map(&mult,tree,tree2);
    string *str=new string ();
    string *str22=tree2->ToStr(tree2, str);
    //cout<<str22[0][1];
    string str2="96 80 104 720";
    string *str1=&str2;
    for (int i=0;i<str1->length();i++)
        assert(str2[i]==str22[0][i]);
}
bool More(int a)
{
    if (a%3==0)
        return true;
    else
        return false;
}
void Where_test()
{
    BinTree<int>* tree=nullptr;
    BinTree<int>* tree2=nullptr;
    tree->Insert(tree, 12);
    tree->Insert(tree, 10);
    tree->Insert(tree, 15);
    tree->Insert(tree, 90);
    tree->Insert(tree, 81);
    tree->Insert(tree, 27);
    tree->Insert(tree, 40);
    tree2=tree2->Where(&More,tree,tree2);
    string *str=new string ();
    string *str22=tree2->ToStr(tree2, str);
    string str2="12 15 90 81 27";
    string *str1=&str2;
    for (int i=0;i<str1->length();i++)
        assert(str2[i]==str22[0][i]);
}
void Bintree_test()
{
    add_test();
    del_test();
    Tostr_test();
    Check_element_test();
    Where_test();
    Concat_test();
    Map_test();
    cout<<"Тесты прошли успешно"<<endl;
}