#include <iostream>
#include "test.h"
//#include "menu.cpp"

int menu()
{
    setlocale(LC_ALL, "RUS");
    cout<<"Тип : 1-Double, 2-Int: ";
    int type;
    cin>>type;
    if (type==1) {
        BinTree<double> *tree = NULL;
        int chislo;
        chislo = 10;
        while (chislo != 100) {
            cout << "Select the operation performed with the binary tree:" << endl;
            cout << "1) inserting elements into a binary tree;\n"
                    "2) removing an element from a binary tree;\n"
                    "3) searching for an element in a binary tree;\n"
                    "4) binary tree traversal;\n"
                    "5) binary tree output;\n"
                    "6) Checking an element for occurrence;\n"
                    "7) Writing a tree to a string;\n"
                    "100) exit the menu;\n" << endl;
            cin >> chislo;
//        if (tree== nullptr)

            if (chislo == 1) {

                double s;
                int n;
                cout << "kolvo elementov dobavlyemoe  v derevo: " << endl;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->Insert(tree, s);
                }
            }
            if (chislo == 2) {
                cout << "Input element" << endl;
                double p;
                cin >> p;
                //tree->del(tree, p);
                tree->del2(p);
                cout << endl;
            }
            if (chislo == 3) {
                cout << "Input element" << endl;
                double q;
                cin >> q;
                tree->find(tree, q);
                cout << endl;
            }
            if (chislo == 4) {
                cout << "Выберите обход бинарного дерева поиска: 1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int q;
                cin >> q;
                switch (q) {
                    case 1:
                        cout << "Обход бинарного дерева поиска(ПКЛ):" << endl;
                        tree->PKL(tree);
                        break;
                    case 2:
                        cout << "Обход бинарного дерева поиска(ПЛК):" << endl;
                        tree->PLK(tree);
                        break;
                    case 3:
                        cout << "Обход бинарного дерева поиска(ЛПК):" << endl;
                        tree->LPK(tree);
                        break;
                    case 4:
                        cout << "Обход бинарного дерева поиска(ЛКП):" << endl;
                        tree->LKP(tree);
                        break;
                    case 5:
                        cout << "Обход бинарного дерева поиска(КЛП):" << endl;
                        tree->KLP(tree);
                        break;
                    case 6:
                        cout << "Обход бинарного дерева поиска(КПЛ):" << endl;
                        tree->KPL(tree);
                        break;

                }
                cout << endl;
            }

            if (chislo == 5) {
                cout << "binarnoe derevo: " << endl;
                tree->Show(tree,0);
            }
            if (chislo == 6) {
                double q;
                cout << "Input element: " << endl;
                cin >> q;
                bool ans = tree->Tree_Element_Check(tree, q);
                if (ans == true)
                    cout << "Элемент есть в дереве" << endl;
                else
                    cout << "Элемент нет в дереве" << endl;
            }

            if (chislo == 7) {
                string *line = new string();
                line = tree->ToStr(tree, line);
                cout << *line << endl;
            }
        }
    }
    else
    {
        BinTree<int> *tree = NULL;
        int chislo;
        chislo = 10;
        while (chislo != 100) {
            cout << "Select the operation performed with the binary tree" << endl;
            cout << "1) inserting elements into a binary tree;\n"
                    "2) removing an element from a binary tree;\n"
                    "3) searching for an element in a binary tree;\n"
                    "4) binary tree traversal;\n"
                    "5) binary tree output;\n"
                    "6) Checking an element for occurrence;\n"
                    "7) Writing a tree to a string;\n"
                    "8) inserting elements into a binary tree from str\n"
                    "9) print elements into str normal\n"
                    "100) exit the menu;\n" << endl;
            cin >> chislo;
//        if (tree== nullptr)

            if (chislo == 1) {

                int s;
                int n;
                cout << "kolvo elementov dobavlyemoe  v derevo: " << endl;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->Insert(tree, s);
                }
            }
            if (chislo == 2) {
                cout << "Input element" << endl;
                int p;
                cin >> p;
                tree->del2( p);
                cout << endl;
            }
            if (chislo == 3) {
                cout << "Input element" << endl;
                int q;
                cin >> q;
                tree->find(tree, q);
                cout << endl;
            }
            if (chislo == 4) {
                cout << "Выберите обход бинарного дерева поиска: 1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int q;
                cin >> q;
                switch (q) {
                    case 1:
                        cout << "Обход бинарного дерева поиска(ПКЛ):" << endl;
                        tree->PKL(tree);
                        break;
                    case 2:
                        cout << "Обход бинарного дерева поиска(ПЛК):" << endl;
                        tree->PLK(tree);
                        break;
                    case 3:
                        cout << "Обход бинарного дерева поиска(ЛПК):" << endl;
                        tree->LPK(tree);
                        break;
                    case 4:
                        cout << "Обход бинарного дерева поиска(ЛКП):" << endl;
                        tree->LKP(tree);
                        break;
                    case 5:
                        cout << "Обход бинарного дерева поиска(КЛП):" << endl;
                        tree->KLP(tree);
                        break;
                    case 6:
                        cout << "Обход бинарного дерева поиска(КПЛ):" << endl;
                        tree->KPL(tree);
                        break;

                }
                cout << endl;
            }

            if (chislo == 5) {
                cout << "binarnoe derevo: " << endl;
                tree->Show(tree,0);
            }
            if (chislo == 6) {
                int q;
                cout << "Input element: " << endl;
                cin >> q;
                bool ans = tree->Tree_Element_Check(tree, q);
                if (ans == true)
                    cout << "Элемент есть в дереве" << endl;
                else
                    cout << "Элемент нет в дереве" << endl;
            }

            if (chislo == 7) {
                string *line = new string();
                line = tree->ToStr(tree, line);
                cout << *line << endl;
            }

            if (chislo == 8){
                //string res="4(2(3)(1))(6(5))";
                string res;
                getline(cin.ignore(),res);
                //cout<<str;
                int start=0;
                tree=tree->FromStringToBinTreeKLP(res,&start);
            }

            if (chislo == 9){
                string *res1=new string();
                string *res2=tree->ToNormalString(tree,res1);
                cout<<res2[0];
                cout<<endl;
            }
        }
    }
    return 0;
}



ostream& operator<<(ostream& out,string *str)
{
    for (int i=0;i<str->length();i++)
        out<<str[i];
    return out;
}


int main()
{
//    string res="4(2(3)(1))(6(5))";
//    BinTree<int>* tree= nullptr;
//    int start=0;
//    tree=tree->FromStringToBinTreeKPL(res,&start);
//    //tree->Show(tree,0);
//    string *res1=new string();
//    string *res2=tree->ToNormalString(tree,res1);
//    cout<<res2[0];
    //Bintree_test();
//    BinTree<int>* tree= nullptr;
//    tree->Insert(tree,20);
//    tree->Insert(tree,10);
//    tree->Insert(tree,5);
//    tree->Insert(tree,40);
//    tree->Insert(tree,15);
//    tree->Insert(tree,12);
//    tree->Insert(tree,17);
//    tree->Insert(tree,8);
//    tree->Show(tree,0);
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    tree->del2(20);
//    tree->Show(tree,0);
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    tree->del2(15);
//    tree->Show(tree,0);


    menu();
    return 0;
}
