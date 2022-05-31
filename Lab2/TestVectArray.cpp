//
// Created by Богдан Брыксин on 12.05.2022.
//

#include "TestVectArray.h"
#include "cmath"

using namespace std;


void VectorArray_From_Array(){
    int arrInt[8]={234,432,532,54,67,432,233,876};
    double arrDouble[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    VectorArray<int> *v1=new VectorArray<int>(arrInt,8);
    VectorArray<double> *v2=new VectorArray<double>(arrDouble,8);

    for(int i=0;i<8;i++){
        assert(arrInt[i]==v1->Get_Value_index(v1,i));
    }

    for(int i=0;i<8;i++){
        assert(arrDouble[i]==v2->Get_Value_index(v2,i));
    }



}

void VectorArray_append_Test(){
    int arrInt[8]={234,432,532,54,67,432,233,876};
    double arrDouble[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    VectorArray<int> *v1=new VectorArray<int>(arrInt,8);
    VectorArray<double> *v2=new VectorArray<double>(arrDouble,8);
    v1->append(24,v1);
    v2->append(2.2,v2);

    for(int i=0;i<8;i++) {
        assert(arrInt[i] == v1->Get_Value_index(v1, i));
    }
    assert(v1->Get_Value_index(v1,8)==24);

    for(int i=0;i<8;i++){
        assert(arrDouble[i]==v2->Get_Value_index(v2,i));
    }

    assert(v2->Get_Value_index(v2,8)==2.2);



}

void VectorArray_Sum_Test(){
    int arr1Int[8]={234,432,532,54,67,432,233,876};
    int arr2Int[8]={234,432,532,54,67,432,233,876};
    double arr1Double[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    double arr2Double[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    VectorArray<int> *v1=new VectorArray<int>(arr1Int,8);
    VectorArray<int> *v2=new VectorArray<int>(arr2Int,8);
    VectorArray<double> *v3=new VectorArray<double>(arr1Double,8);
    VectorArray<double> *v4=new VectorArray<double>(arr2Double,8);

    VectorArray<int> *resI=v1->Sum_Vector(v1,v2);
    VectorArray<double> *resD=v3->Sum_Vector(v3,v4);

    for(int i=0;i<8;i++){
        assert((arr1Int[i]+arr2Int[i])==resI->Get_Value_index(resI,i));
    }

    for(int i=0;i<8;i++){
        assert((arr1Double[i]+arr2Double[i])==resD->Get_Value_index(resD,i));
    }

}

void VectorArray_Multiply_On_Scalar_Test(){
    int arrInt[8]={234,432,532,54,67,432,233,876};
    double arrDouble[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    VectorArray<int> *v1=new VectorArray<int>(arrInt,8);
    VectorArray<double> *v2=new VectorArray<double>(arrDouble,8);

    VectorArray<int> *resI=v1->Multiply_On_Scalar_Vector(v1,2);
    VectorArray<double> *resD=v2->Multiply_On_Scalar_Vector(v2,2.1);




    for(int i=0;i<8;i++) {
        assert((arrInt[i]*2) == resI->Get_Value_index(resI, i));
    }

    for(int i=0;i<8;i++){
        assert((arrDouble[i]*2.1)==resD->Get_Value_index(resD,i));
    }





}

void VectorArray_Scalar_Product_Test(){
    int arr1Int[8]={234,432,532,54,67,432,233,876};
    int arr2Int[8]={234,432,532,54,67,432,233,876};
    double arr1Double[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    double arr2Double[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};
    VectorArray<int> *v1=new VectorArray<int>(arr1Int,8);
    VectorArray<int> *v2=new VectorArray<int>(arr2Int,8);
    VectorArray<double> *v3=new VectorArray<double>(arr1Double,8);
    VectorArray<double> *v4=new VectorArray<double>(arr2Double,8);

    int resI=v1->Scalar_Product_Vector(v1,v2);
    double resD=v3->Scalar_Product_Vector(v3,v4);
    int resI1=0;
    double resD1=0;
    for(int i=0;i<8;i++){
        resI1=resI1+arr1Int[i]*arr2Int[i];
    }

    assert(resI1==resI);
    for(int i=0;i<8;i++){
        resD1=resD1+arr1Double[i]*arr2Double[i];
    }
    assert(resD1==resD);


}

void VectorArray_Module_Test(){
    int arr1Int[8]={234,432,532,54,67,432,233,876};

    double arr1Double[8]={2.4,4.5,23.7,67.8,12.1,8.3,9.5,16.4};

    VectorArray<int> *v1=new VectorArray<int>(arr1Int,8);

    VectorArray<double> *v3=new VectorArray<double>(arr1Double,8);


    double resI=v1->Module_Vector(v1);
    double resD=v3->Module_Vector(v3);
    double resI1=0;
    double resD1=0;
    for(int i=0;i<8;i++){
        resI1=resI1+arr1Int[i]*arr1Int[i];
    }
    resI1= sqrt(resI1);
    assert(abs(resI1==resI)<0.1);
    for(int i=0;i<8;i++){
        resD1=resD1+arr1Double[i]*arr1Double[i];
    }
    resD1= sqrt(resD1);
    assert(abs(resD1-resD)<0.1);



}

void VectorArray_All_Tests(){

    VectorArray_From_Array();
    VectorArray_append_Test();
    VectorArray_Sum_Test();
    VectorArray_Multiply_On_Scalar_Test();
    VectorArray_Module_Test();
    VectorArray_Scalar_Product_Test();
    cout<<"Tests VectorArray Passed"<<endl;

}
