#include <iostream>
#include "Sequence.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "Vector.h"
#include "TestVect.h"
#include "TestComplex.h"
#include "VecrorArray.h"
#include "TestVectArray.h"

using namespace std;



template<class T>
void input(T* a)
{
    while (true)
    {
        cout << "Enter a value:";
        cin >> *a;
        break;
    }
}

void menu()
{   int data_type=0;
    printf("Enter 1 for int, 2 for double\n");
    while (data_type != 1 && data_type != 2)
        input(&data_type);
    if (data_type==1) {
        printf("Enter 1 for Vector on LinkedListSequence Enter 2 for Vector on DinamicArraySequence \n");
        int type = -1;
        while (type != 1 && type != 2)
            input(&type);

        Vector<int> *seq;

        if (type == 1)
            seq = new Vector<int>;



        printf("Enter 1 for append, 2 Sum Vector, 3 Multiply_On_Scalar_Vector,  4 for print, 5 Scalar_Product_Vector,6 Module_Vector 0 for exit program\n");
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }


            switch (type) {
                case 0:
                    exit(0);
                    break;

                case 1:
                    int zz;
                    printf("Enter append item\n");
                    cin>>zz;
                    seq->append(zz,seq);
                    break;

                case 2:{
                    Vector<int> *seq1= new Vector<int>;

                    printf("Enter vector\n");
                    seq1->input_vector(seq->Get_ln_Vector(seq));
                    Vector<int> *seq2= seq->Sum_Vector(seq,seq1);
                    cout<<seq2<<endl;
                    break;}

                case 3:
                    printf("Enter Scalar:\n");
                    int qq;
                    cin >> qq;

                    try {
                        Vector<int> *seq3 = seq->Multiply_On_Scalar_Vector(seq, qq);
                        cout << seq3;
                    }
                    catch (Myexception &abc) {

                        cout << "Process finished with error code = " << abc.number << endl;
                        exit(0);
                    }
                    break;



                case 4:
                    cout<<seq<<endl;
                    break;
                case 5:{
                    Vector<int> *seq5= new Vector<int>;

                    printf("Enter vector\n");
                    seq5->input_vector(seq->Get_ln_Vector(seq));
                    int ress;
                    ress=seq5->Scalar_Product_Vector(seq,seq5);
                    cout<<ress;
                    break;}
                case 6:
                    double xx;
                    xx=seq->Module_Vector(seq);
                    cout<<xx;
                    break;

            }
        }
    }
    else
    {
        printf("Enter 1 for Vector \n");
        int type = -1;
        while (type != 1 && type != 2)
            input(&type);

        Vector<double> *seq;

        if (type == 1)
            seq = new Vector<double>;


        printf("Enter 1 for append, 2 Sum Vector, 3 Multiply_On_Scalar_Vector,  4 for print, 5 Scalar_Product_Vector,6 Module_Vector 0 for exit program\n");
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                printf("Enter a command: \n");
                input(&type);
            }


            switch (type) {
                case 0:
                    exit(0);
                    break;

                case 1:
                    int zz;
                    printf("Enter append item\n");
                    cin>>zz;
                    seq->append(zz,seq);
                    break;

                case 2:{
                    Vector<double> *seq1= new Vector<double>;

                    printf("Enter vector\n");
                    seq1->input_vector(seq->Get_ln_Vector(seq));
                    Vector<double> *seq2= seq->Sum_Vector(seq,seq1);
                    cout<<seq2<<endl;
                    break;}

                case 3:
                    printf("Enter Scalar:\n");
                    int qq;
                    cin >> qq;

                    try {
                        Vector<double> *seq3 = seq->Multiply_On_Scalar_Vector(seq, qq);
                        cout << seq3;
                    }
                    catch (Myexception &abc) {

                        cout << "Process finished with error code = " << abc.number << endl;
                        exit(0);
                    }
                    break;



                case 4:
                    cout<<seq<<endl;
                    break;
                case 5:{
                    Vector<double> *seq5= new Vector<double>;

                    printf("Enter vector\n");
                    seq5->input_vector(seq->Get_ln_Vector(seq));
                    double ress;
                    ress=seq5->Scalar_Product_Vector(seq,seq5);
                    cout<<ress;
                    break;}
                case 6:
                    double xx;
                    xx=seq->Module_Vector(seq);
                    cout<<xx;
                    break;

            }
        }
    }

}


int main() {

    menu();
//    Vector_All_Tests();
//    Complex_All_Tests();
//    VectorArray_All_Tests();
//    double arr[5]={1,2,3,4,5};
//    int arr1[5]={1,2,3,4,5};
//    int arr2[5]={10,20,30,40,50};


//    VectorArray<int> *v1=new VectorArray<int>(arr1,5);
//    cout<<v1<<endl;
//    VectorArray<int> *v2=new VectorArray<int>(arr2,5);
//    cout<<v2<<endl;
//    double res=v1->Get_ln_Vector(v1);
//    cout<<res;



    double arr[5]={1,2,3,4,5};
    int arr1[5]={1,2,3,4,5};

    Vector<Complex> *v1=new Vector<Complex>;
    Vector<Complex> *v2=new Vector<Complex>;
    Vector<Complex> *v7=new Vector<Complex>;
    Vector<double> *v10=new Vector<double>(arr,5);

    Complex complex1(2,3);
    v7->append(complex1,v7);
    Complex complex2(3,4);
    Complex complex3(5,6);
    Complex complex4(7,8);
    v1->append(complex1,v1);
    v1->append(complex2,v1);
    v2->append(complex3,v2);
    v2->append(complex4,v2);
    cout<<v1<<endl;
    cout<<v2<<endl;
    Vector<Complex> *v3=v1->Multiply_On_Scalar_Vector(v1,complex3);
    cout<<v3<<endl;
    Complex complex5;
    double zzz=v10->Module_Vector(v10);
    cout<<zzz;

    return 0;
}
