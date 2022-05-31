//
// Created by Богдан Брыксин on 11.05.2022.
//

#include "TestComplex.h"
#include "Complex.h"

using namespace std;

void Complex_Constructor_Test(){
    Complex complex(2.3,4.5);
    assert(complex.Get_Real(complex)==2.3);
    assert(complex.Get_Im(complex)==4.5);
}

void Complex_SetReal_Test(){
    Complex complex(2.3,4.5);
    complex.Set_Real(2);

    assert(complex.Get_Real(complex)==2);

}
void Complex_SetIm_Test(){
    Complex complex(2.3,4.5);
    complex.Set_Im(3);

    assert(complex.Get_Im(complex)==3);

}

void Complex_OperatorPlus_Test(){
    Complex complex1(2,3);
    Complex complex2(4,5);
    Complex res=complex1+complex2;
    assert(res.Get_Real(res)==2+4);
    assert(res.Get_Im(res)==5+3);
}

void Complex_OperatorSubtract_Test(){
    Complex complex1(2,3);
    Complex complex2(4,5);
    Complex res=complex2-complex1;
    assert(res.Get_Real(res)==4-2);
    assert(res.Get_Im(res)==5-3);
}

void Complex_OperatorMult_Test(){
    Complex complex1(2,3);
    Complex complex2(4,5);
    Complex res=complex2*complex1;
    assert(res.Get_Real(res)==2*4-3*5);
    assert(res.Get_Im(res)==2*5+4*3);

}

void Complex_All_Tests(){

    Complex_Constructor_Test();
    Complex_SetReal_Test();
    Complex_SetIm_Test();
    Complex_OperatorPlus_Test();
    Complex_OperatorSubtract_Test();
    Complex_OperatorMult_Test();
    cout<<"Tests Complex Passed"<<endl;
}