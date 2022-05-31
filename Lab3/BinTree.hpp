#ifndef BINARYTREE2_HPP
#define BINARYTREE2_HPP
#include <iostream>
#include <cstring>


using namespace std;
template <class T>
class BinTree
{
private:
    T data_tree;// значение в дерево
    BinTree* Left_pointer; // указатель на левый
    BinTree* Right_pointer; // указатель на правый
public:
    BinTree();  //конструкторы
    BinTree(T data);
//    ~BinTree()
//    {
//        data_tree=0;
//        Left_pointer= nullptr;
//        Right_pointer=nullptr;
//    }
public:
    BinTree* Get_left();    //Геттеры
    BinTree* Get_right();
    T Get_Data();               //функции
    BinTree<T>* find(BinTree<T>* Tree, T a);
    void Concat(BinTree<T>* tree1, BinTree<T>* tree2);
    void del(BinTree<T>* tree, T b, BinTree<T>* prev = nullptr);
    void tree_delete(BinTree<T>* tree);
    void Insert(BinTree<T>*& Tree, T k);
    void del2(int key);
    bool Check_Sub_Tree(BinTree<T>* Tree, BinTree<T>* SubTree);
    void PKL(BinTree<T>* Tree); //обходы
    void PLK(BinTree<T>* Tree);
    void KLP(BinTree<T>* Tree);
    void KPL(BinTree<T>* Tree);
    void LPK(BinTree<T>* Tree);
    void LKP(BinTree<T>* tree);
    void Show(BinTree<T>*& tree, int level);
    void print(BinTree<T>*& tree);
    bool Tree_Element_Check(BinTree<T>* Tree, T value);
    BinTree<T>* Get_subTree(BinTree<T>* Tree, T a);
    string* ToStr(BinTree<T>* tree1, string *res);
    BinTree<T>* Where(bool (*f) (T data), BinTree<T>* tree1, BinTree<T>* res);
    BinTree<T>* Map(T (*f) (T data), BinTree<T>* tree1, BinTree<T>* res);
    string* ToNormalString(BinTree<T>* tree1,string* res);
    BinTree<T>* FromStringToBinTreeKLP(const std::string& str, int *start);
    BinTree<T>* FromStringToBinTreeKPL(const std::string& str, int *start);


};
template <class T>
BinTree<T>::BinTree(T data)
{
    this->data_tree= data;
    this->Left_pointer=nullptr;
    this->Right_pointer=nullptr;
}
template <class T>
BinTree<T>::BinTree()
{
    this->Left_pointer=nullptr;
    this->Right_pointer=nullptr;
}

template <class T>
void BinTree<T>::print(BinTree<T>*& tree) {
    if (tree != nullptr)
    {

        print(tree->left);// переходим в левое поддерево пока не дойдем до конца слева
        cout << tree->zn << " __ "; // печатаем с левого конца поддерева
        print(tree->right);
        cout << endl;
    }

}


template <class T>
string* BinTree<T>::ToStr(BinTree<T>* tree1, string* res)
{
    if (tree1== nullptr)
        return nullptr;
    *res= *res+ to_string(tree1->Get_Data());
    *res= *res + " ";
    if (tree1->Get_left()!= nullptr)
        ToStr(tree1->Get_left(), res);
    if (tree1->Get_right()!= nullptr)
        ToStr(tree1->Get_right(), res);
    return res;
}

template <class T>
BinTree<T>* BinTree<T>::Where(bool (*f) (T data), BinTree<T>* tree1, BinTree<T>* res)
{
    if (tree1!=nullptr)
    {
        if (f(tree1->Get_Data()))
            res->Insert(res, tree1->Get_Data());
        if (tree1->Get_left()!=nullptr)
            Where(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Where(f,tree1->Get_right(),res);
    }
    return res;
}


template <class T>
string* BinTree<T>::ToNormalString(BinTree<T>* tree1,string* res)
{
    if (tree1== nullptr)
        return nullptr;
    *res= *res+ to_string(tree1->Get_Data());
    if (tree1->Get_left()!= nullptr)
    {
        *res+="(";
        ToNormalString(tree1->Get_left(),res);
        *res+=")";
    }
    else{////
        *res+="(";/////
        *res+=")";////
    }////

    if (tree1->Get_right()!= nullptr) {
        *res += "(";
        ToNormalString(tree1->Get_right(), res);
        *res += ")";
    }
    else{////
        *res+="(";/////
        *res+=")";////
    }////
    return res;
}

template <class T>
BinTree<T>* BinTree<T>::Map(T (*f) (T data), BinTree<T>* tree1, BinTree<T>* res)
{
    if (tree1== nullptr)
        return nullptr;
    if (tree1!=nullptr)
    {
        if (tree1->Get_Data())
            res->Insert(res, f(tree1->Get_Data()));
        if (tree1->Get_left()!=nullptr)
            Map(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Map(f,tree1->Get_right(),res);
    }
    return res;
}

template <class T>
void BinTree<T>::Concat(BinTree<T>* tree1, BinTree<T>* tree2)
{

    if (tree1->Get_left()!=nullptr)
        Concat(tree1->Left_pointer, tree2);
    if (tree1->Get_right()!=nullptr)
        Concat(tree1->Get_right(),tree2);
    tree2->Insert(tree2, tree1->Get_Data());
}
template <class T>
bool BinTree<T>::Tree_Element_Check(BinTree<T>* Tree, T value)
{
    BinTree<T> *nwtree=nullptr;
    nwtree=Tree->find(Tree,value);

    if (nwtree==nullptr)
        return false;
    else
        return true;
}
template <class T>
bool BinTree<T>::Check_Sub_Tree(BinTree<T>* Tree, BinTree<T>* SubTree)
{

    bool cont=Tree->Tree_Element_Check(Tree, SubTree->Get_Data());
    if (cont == false)
        return false;
    if (Tree->Get_left()!= nullptr) {
        cont = Check_Sub_Tree(Tree, SubTree->Get_left());
        if (cont == false)
            return false;
    }
    if (Tree->Get_right()!= nullptr){
        cont=Check_Sub_Tree(Tree, SubTree->Get_right());
         if (cont==false)
            return false;
    }
    if (cont==true)
    {
        return true;
    }
}

template <class T>
BinTree<T>* getmin(BinTree<T>* Tree, BinTree<T>*& prev)
{
    if (Tree == nullptr)
    {
        return nullptr;
    }
    if (Tree->Get_left() != nullptr)
    {
        BinTree<T>* tmp =  getmin(Tree->Get_left(), Tree);
        prev = Tree;
        return tmp;
    }
    else
    {
        return Tree;
    }
}

template <class T>
BinTree<T>* BinTree<T>::Get_left()
{
    return this->Left_pointer;
}
template <class T>
BinTree<T>* BinTree<T>::Get_right()
{
    return this->Right_pointer;
}
template <class T>
T BinTree<T>::Get_Data()
{
    return this->data_tree;
}


// поиск
template <class T>
BinTree<T>* BinTree<T>::find(BinTree<T>* Tree, T a)
{
    if (Tree != nullptr)
    {
        if (Tree->data_tree == a)
        {
            return Tree;
        }
        else if (a < Tree->data_tree)
        {
            return find(Tree->Left_pointer, a);
        }
        else if (a > Tree->data_tree)
        {
            return find(Tree->Right_pointer, a);
        }

    }
    else
        return nullptr;

}





template<class T>
BinTree<T>* BinTree<T>::FromStringToBinTreeKLP(const std::string& str, int *start)
{
    if (str.empty() || *start >= str.size())
        return nullptr;

    T num = 0;
// Получаем первое число
    while(*start < str.size() && str[*start] != '(' && str[*start] != ')')
    {
        T num_here = (T)(str[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
// Создаем узел с нашим числом
    BinTree<T> *root = nullptr;
    if (num > 0)
        root = new BinTree(num);
// Встречаем правую скобку - начинаем строить дерево слева.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->Left_pointer = FromStringToBinTreeKLP(str, start);
    }
    if (*start < str.size() && str[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
// Когда мы встречаем вторую правую скобку от узла, строим дерево вправо.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->Right_pointer = FromStringToBinTreeKLP(str, start);
    }

    if (*start < str.size() && str[*start] == ')')
        *start = *start + 1;

    return root;


}

template<class T>
BinTree<T>* BinTree<T>::FromStringToBinTreeKPL(const std::string& str, int *start)
{
    if (str.empty() || *start >= str.size())
        return nullptr;

    T num = 0;
// get
    while(*start < str.size() && str[*start] != '(' && str[*start] != ')')
    {
        T num_here = (T)(str[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
// create
    BinTree<T> *root = nullptr;
    if (num > 0)
        root = new BinTree(num);
// left tree
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->Right_pointer = FromStringToBinTreeKPL(str, start);
    }
    if (*start < str.size() && str[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
// right tree
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->Left_pointer = FromStringToBinTreeKPL(str, start);
    }

    if (*start < str.size() && str[*start] == ')')
        *start = *start + 1;

    return root;


}

template <class T>
void BinTree<T>::del(BinTree<T>* tree, T b , BinTree<T>* prev)
{

    if (tree != nullptr)
    {
        if (b == tree->data_tree)
        {
            if ((tree->Left_pointer == nullptr) && (tree->Right_pointer == nullptr))
            {
                if (prev != nullptr && prev->data_tree <= tree->data_tree)
                    prev->Right_pointer = nullptr;
                else
                    prev->Left_pointer = nullptr;
                delete tree;
            }
            else if (tree->Left_pointer == nullptr && tree->Right_pointer != nullptr)
            {
                if (prev != nullptr && prev->data_tree <= tree->data_tree)
                    prev->Right_pointer = tree->Right_pointer;
                else
                    prev->Left_pointer = tree->Right_pointer;
                delete tree;
            }
            else if (tree->Left_pointer != nullptr && tree->Right_pointer == nullptr) {
                if (prev != nullptr && prev->data_tree <= tree->data_tree)
                    prev->Right_pointer = tree->Left_pointer;
                else
                    prev->Left_pointer = tree->Left_pointer;
                delete tree;

            }
            else if (tree->Left_pointer != nullptr && tree->Right_pointer != nullptr)
            {
                BinTree<T>* prev = nullptr;
                BinTree<T>* ptr = getmin(tree->Right_pointer, prev);
                if (ptr->Right_pointer == nullptr) {
                    if (prev != nullptr)
                        prev->Left_pointer = nullptr;
                }
                else {
                    if (prev != nullptr)
                        prev->Left_pointer = ptr->Right_pointer;
                }
                tree->data_tree = ptr->data_tree;
                delete ptr;
            }

        }
        else if (b < tree->data_tree)
        {
            del(tree->Left_pointer, b, tree);
        }
        else if (b > tree->data_tree)
        {
            del(tree->Right_pointer, b, tree);
        }
    }
    else
    {
        cout << "No elementa  " << endl;
    }
}

template <class T>
void BinTree<T>::KLP(BinTree<T>* tree)
{
    if (tree != nullptr)
    {
        cout << tree->data_tree << "\t";
        KLP(tree->Left_pointer);
        KLP(tree->Right_pointer);
    }
}

template <class T>
void BinTree<T>::KPL(BinTree<T>* tree)
{
    if (tree != nullptr)
    {
        cout << tree->data_tree << "\t";
        KPL(tree->Right_pointer);
        KPL(tree->Left_pointer);
    }
}

template <class T>
void BinTree<T>::LPK(BinTree<T>* Tree)
{
    if (Tree != nullptr)
    {
        LPK(Tree->Left_pointer);
        LPK(Tree->Right_pointer);
        cout << Tree->data_tree << "\t";

    }
}

template <class T>
void BinTree<T>::LKP(BinTree<T>* Tree)
{
    if (Tree != nullptr)
    {
        LKP(Tree->Left_pointer);
        cout << Tree->data_tree << "\t";
        LKP(Tree->Right_pointer);
    }
}


template <class T>
BinTree<T>* BinTree<T>::Get_subTree(BinTree<T>* Tree, T a)
{
    BinTree<T>* res=find(Tree, a);
    return res;
}



template <class T>
void BinTree<T>::tree_delete(BinTree<T>* tree)
{
    if (tree != nullptr)
    {
        tree_delete(tree->Get_left());
        tree_delete(tree->Get_right());

        delete tree;
        tree = nullptr;
    }

}

template <class T>
void BinTree<T>::PKL(BinTree<T>* Tree)
{
    if (Tree != nullptr)
    {
        PKL(Tree->Right_pointer);
        cout << Tree->data_tree << "\t";
        PKL(Tree->Left_pointer);
    }

}

template <class T>
void BinTree<T>::PLK(BinTree<T>* Tree)
{
    if (Tree != nullptr)
    {
        PLK(Tree->Right_pointer);
        PLK(Tree->Left_pointer);
        cout << Tree->data_tree << "\t";
    }
}



template <class T>
void BinTree<T>::Insert(BinTree<T>*& Tree, T k)
{

    if (Tree == nullptr)
    {
        Tree = new BinTree<T>;
        Tree->data_tree = k;
        Tree->Left_pointer = Tree->Right_pointer = nullptr;
        return;
    }

    if (k < Tree->data_tree)
    {
        if (Tree->Left_pointer != nullptr) Insert(Tree->Left_pointer, k);
        else
        {
            Tree->Left_pointer = new BinTree<T>;
            Tree->Left_pointer->Left_pointer = Tree->Left_pointer->Right_pointer = nullptr;
            Tree->Left_pointer->data_tree = k;
        }

    }
    if (k >= Tree->data_tree)
    {
        if (Tree->Right_pointer != nullptr) Insert(Tree->Right_pointer, k);
        else
        {
            Tree->Right_pointer = new BinTree<T>;
            Tree->Right_pointer->Right_pointer = Tree->Right_pointer->Left_pointer = nullptr;
            Tree->Right_pointer->data_tree = k;
        }
    }
}

template<class T>
void BinTree<T>::Show(BinTree<T> *&tree, int level)
{

    if (tree)
    {
        Show(tree->Right_pointer, level + 3);
        for (int i = 0; i < level; i++) cout << "     ";
        cout << tree->data_tree << endl;
        Show(tree->Left_pointer, level + 3);
    }
    else{
        cout<<"";
    }
}

template<class T>
void BinTree<T>::del2(int key)
{
    BinTree<T> * curr =new BinTree<T>();
    curr=this;
    BinTree<T> * parent = NULL;
    while (curr && curr->data_tree != key)
    {
        parent = curr;
        if (curr->data_tree > key)
        {
            curr = curr->Left_pointer;
        }
        else
        {
            curr = curr->Right_pointer;
        }
    }
    if (!curr)
        return;
    if (curr->Left_pointer == NULL)
    {
        if (this==curr && this->Right_pointer==nullptr){

            curr= nullptr;
            return;


        }


        if (parent && parent->Left_pointer == curr)
            parent->Left_pointer = curr->Right_pointer;
        if (parent && parent->Right_pointer == curr)
            parent->Right_pointer = curr->Right_pointer;

        delete curr;
        return;
    }
    if (curr->Right_pointer == NULL)
    {

        if (parent && parent->Left_pointer == curr)
            parent->Left_pointer = curr->Left_pointer;
        if (parent && parent->Right_pointer == curr)
            parent->Right_pointer = curr->Left_pointer;

        curr= nullptr;
        return;
    }

    BinTree<T> * replace = curr->Right_pointer;
    while (replace->Left_pointer)
        replace = replace->Left_pointer;
    int replace_value = replace->data_tree;
    del2(replace_value);
    curr->data_tree = replace_value;
}

#endif //BINARYTREE2_HPP

