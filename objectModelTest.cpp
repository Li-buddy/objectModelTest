// testForObjectModel.cpp : Defines the entry point for the application.
//

#include "objectModelTest.h"

using namespace std;

//test case 0: object model with just data
void test_object_model_just_data()
{
	using namespace just_data;
	typedef void(*FUNC)();

	cout << endl;
	cout << "**********Object model of furniture**********" << endl;
	furniture f1;
	cout << "sizeof furniture object is : " << sizeof(f1) << endl;
	cout << "f1              ->  " << &f1 << endl;
	cout << "f1.m_furWeight  ->  " << &f1.m_furWeight << endl;

	cout << endl;
	cout << "**********Object model of sofa**********" << endl;
	sofa s1;
	cout << "sizeof sofa object is : " << sizeof(s1) << endl;
	cout << "s1 address is   ->  " << &s1 << endl;
	cout << "s1.m_sofaWeight ->  " << &s1.m_sofaWeight << endl;
	cout << "s1.m_furWeight  ->  " << &s1.m_furWeight << endl;

	cout << endl;
	cout << "**********Object model of bed**********" << endl;
	bed b1;
	cout << "sizeof bed object is : " << sizeof(b1) << endl;
	cout << "b1   address is ->  " << &b1 << endl;
	cout << "b1.m_bedWeight  ->  " << &b1.m_bedWeight << endl;
	cout << "b1.m_furWeight  ->  " << &b1.m_furWeight << endl;

	
	cout << endl;
	cout << "**********Object model of sofabed**********" << endl;
	sofabed sofBed1;
	cout << "sizeof sofabed object is : " << sizeof(sofBed1) << endl;
	cout << "sofBed1   address  is      ->  " << &sofBed1 << endl;
	cout << "sofBed1.soft::m_furWeight  ->  " << &sofBed1.sofa::m_furWeight << endl;
	cout << "sofBed1.m_sofaWeight       ->  " << &sofBed1.m_sofaWeight << endl;
	cout << "sofBed1.bed::m_furWeight   ->  " << &sofBed1.bed::m_furWeight << endl;
	cout << "sofBed1.m_bedWeight        ->  " << &sofBed1.m_bedWeight << endl;
	cout << "sofBed1.m_sofabedWeight    ->  " << &sofBed1.m_sofabedWeight << endl;
}

//test case 1: object model with virtual inheritance
void test_object_model_virtual_inheritance()
{
	using namespace virtual_inheritance;
	furniture f1;

	bed b1;
	cout << sizeof(b1) << endl;
	cout << "b1              ->  " << &b1 << endl;
	cout << "b1.m_bedWeight  ->  " << &b1.m_bedWeight << endl;
	cout << "b1.m_furWeight  ->  " << &b1.m_furWeight << endl;

	long** path = (long**)(&b1);
	cout << "sofBed1->bed->vbptr->0   ->  " << path[0][0] << endl;
	cout << "sofBed1->bed->vbptr->1   ->  " << path[0][1] << endl;


	sofa s1;
	cout << sizeof(s1) << endl;
	cout << "s1              ->  " << &s1 << endl;
	cout << "s1.m_sofaWeight ->  " << &s1.m_sofaWeight << endl;
	cout << "s1.m_furWeight  ->  " << &s1.m_furWeight << endl;

	cout << "sofBed1->sofa->vbptr->0   ->  " << path[0][0] << endl;
	cout << "sofBed1->sofa->vbptr->1   ->  " << path[0][1] << endl;

	cout << endl;

	sofabed sofBed1;
	cout << sizeof(sofBed1) << endl;
	cout << "sofBed1                  ->  " << &sofBed1 << endl;
	cout << "sofBed1.m_sofaWeight     ->  " << &sofBed1.m_sofaWeight << endl;
	cout << "sofBed1.m_bedWeight      ->  " << &sofBed1.m_bedWeight << endl;
	cout << "sofBed1.m_sofabedWeight  ->  " << &sofBed1.m_sofabedWeight << endl;
	cout << "sofBed1.m_furWeight      ->  " << &sofBed1.m_furWeight << endl;

	path = (long**)(&sofBed1);
	cout << "sofBed1->bed->vbptr->0   ->  " << path[0][0] << endl;
	cout << "sofBed1->bed->vbptr->1   ->  " << path[0][1] << endl;

	cout << "sofBed1->sofa->vbptr->0   ->  " << path[2][0] << endl;
	cout << "sofBed1->sofa->vbptr->1   ->  " << path[2][1] << endl;


	//将发生间接访问
	furniture* pFur = nullptr;
	pFur = &sofBed1;

	sofa* pSf1 = nullptr;
	pSf1 = &sofBed1;

	bed* pBed = nullptr;
	pBed = &sofBed1;
}

//test case 2: object model with virtual inheritance& virtual function
void test_object_model_virtual_inheritance_function()
{
	using namespace virtual_inheritance_function;

	typedef void(*FUNC)();

	cout << endl;
	cout << "**********Object model of furniture**********"<<endl;
	furniture f1;
	cout << "sizeof furniture object is : " << sizeof(f1) << endl;
	cout << "f1              ->  " << &f1 << endl;

	//long 4bytes long long 8bytes
	//because of the system platform is 64bits so need 8bytes store the address
	long long** baseAddressOfFur1 = (long long**)(&f1);
	FUNC furFuncPtr;
	furFuncPtr = (FUNC)baseAddressOfFur1[0][0];
	furFuncPtr();
	FUNC furFuncPtr2;
	furFuncPtr2 = (FUNC)baseAddressOfFur1[0][1];
	furFuncPtr2();
	cout << "f1.m_furWeight  ->  " << &f1.m_furWeight << endl;		

	cout << endl;
	cout << "**********Object model of sofa**********" << endl;
	sofa s1;
	cout << "sizeof sofa object is : " << sizeof(s1) << endl;
	cout << "s1 address is   ->  " << &s1 << endl;

	long long** baseAddressOfSofa = (long long**)(&s1);
	FUNC sofaFuncPtrInSofa;
	sofaFuncPtrInSofa = (FUNC)baseAddressOfSofa[0][0];
	sofaFuncPtrInSofa();

	long** path = (long**)(&s1);
	cout << "sofa of->sofa->vbptr->0   ->  " << path[1][0] << endl;
	cout << "sofa of->sofa->vbptr->1   ->  " << path[1][1] << endl;

	cout << "s1.m_sofaWeight ->  " << &s1.m_sofaWeight << endl;

	FUNC furFuncPtrInSofa;
	furFuncPtrInSofa = (FUNC)baseAddressOfSofa[3][0];
	furFuncPtrInSofa();
	FUNC furFuncPtrInSofa2;
	furFuncPtrInSofa2 = (FUNC)baseAddressOfSofa[3][1];
	furFuncPtrInSofa2();
	cout << "s1.m_furWeight  ->  " << &s1.m_furWeight << endl;

	

	cout << endl;
	cout << "**********Object model of bed**********" << endl;
	bed b1;
	cout << "sizeof bed object is : " << sizeof(b1) << endl;
	cout << "b1              ->  " << &b1 << endl;
	long long** baseAddressOfBed = (long long**)(&b1);
	FUNC bedFuncInBed;
	bedFuncInBed = (FUNC)baseAddressOfBed[0][0];
	bedFuncInBed();

	path = (long**)(&b1);
	cout << "bed->bed->vbptr->0   ->  " << path[1][0] << endl;
	cout << "bed->bed->vbptr->1   ->  " << path[1][1] << endl;

	cout << "b1.m_bedWeight  ->  " << &b1.m_bedWeight << endl;

	FUNC furFuncPtrOfBed;
	furFuncPtrOfBed = (FUNC)baseAddressOfBed[3][0];
	furFuncPtrOfBed();
	FUNC furFuncPtrOfBed2;
	furFuncPtrOfBed2 = (FUNC)baseAddressOfBed[3][1];
	furFuncPtrOfBed2();
	cout << "b1.m_furWeight  ->  " << &b1.m_furWeight << endl;

	
	cout << endl;
	cout << "**********Object model of sofabed**********" << endl;
	sofabed sofBed1;
	cout << "sizeof sofabed object is : "<<sizeof(sofBed1) << endl;
	cout << "sofBed1                  ->  " << &sofBed1 << endl;

	long long** baseAddressOfSofaBed = (long long**)(&sofBed1);
	FUNC sofaFuncPtrOfSofaBed;
	sofaFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][0];
	sofaFuncPtrOfSofaBed();

	FUNC sofabedFuncPtrOfSofaBed;
	sofabedFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][1];
	sofabedFuncPtrOfSofaBed();

	path = (long**)(&sofBed1);
	cout << "sofabed->sofa->vbptr->0   ->  " << path[1][0] << endl;
	cout << "sofabed->sofa->vbptr->1   ->  " << path[1][1] << endl;

	cout << "sofBed1.m_sofaWeight     ->  " << &sofBed1.m_sofaWeight << endl;

	FUNC bedFuncPtrOfSofaBed;
	bedFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][0];
	bedFuncPtrOfSofaBed();

	cout << "sofabed->bed->vbptr->0   ->  " << path[4][0] << endl;
	cout << "sofabed->bed->vbptr->1   ->  " << path[4][1] << endl;

	cout << "sofBed1.m_bedWeight      ->  " << &sofBed1.m_bedWeight << endl;
	cout << "sofBed1.m_sofabedWeight  ->  " << &sofBed1.m_sofabedWeight << endl;

	FUNC furFuncPtrOfSofaBed;
	furFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[7][0];
	furFuncPtrOfSofaBed();

	FUNC furFunc2PtrOfSofaBed;
	furFunc2PtrOfSofaBed = (FUNC)baseAddressOfSofaBed[7][1];
	furFunc2PtrOfSofaBed();
	
	cout << "sofBed1.m_furWeight      ->  " << &sofBed1.m_furWeight << endl;

	
}

//test case 3: object model with virtual function
void test_object_model_virtual_function()
{
	using namespace virtual_function;

	typedef void(*FUNC)();

	cout << endl;
	cout << "**********Object model of furniture**********" << endl;
	furniture f1;
	cout << "sizeof furniture object is : " << sizeof(f1) << endl;
	cout << "f1              ->  " << &f1 << endl;

	//long 4bytes long long 8bytes
	//because of the system platform is 64bits so need 8bytes store the address
	//if on 32bits system it should be
	// int** baseAddressOfFur1 = (int**)(&f1);
	long long** baseAddressOfFur1 = (long long**)(&f1);
	FUNC furFuncPtr;
	furFuncPtr = (FUNC)baseAddressOfFur1[0][0];
	furFuncPtr();
	FUNC furFuncPtr2;
	furFuncPtr2 = (FUNC)baseAddressOfFur1[0][1];
	furFuncPtr2();
	cout << "f1.m_furWeight  ->  " << &f1.m_furWeight << endl;


	cout << endl;
	cout << "**********Object model of sofa**********" << endl;
	sofa s1;
	cout << "sizeof sofa object is : " << sizeof(s1) << endl;
	cout << "s1 address is   ->  " << &s1 << endl;
	long long** baseAddressOfSofa = (long long**)(&s1);
	FUNC furFuncPtrInSofa;
	furFuncPtrInSofa = (FUNC)baseAddressOfSofa[0][0];
	furFuncPtrInSofa();
	FUNC furFunc2PtrInSofa;
	furFunc2PtrInSofa = (FUNC)baseAddressOfSofa[0][1];
	furFunc2PtrInSofa();
	FUNC sofaFuncPtrInSofa;
	sofaFuncPtrInSofa = (FUNC)baseAddressOfSofa[0][2];
	sofaFuncPtrInSofa();	
	cout << "s1.m_furWeight  ->  " << &s1.m_furWeight << endl;
	cout << "s1.m_sofaWeight ->  " << &s1.m_sofaWeight << endl;


	cout << endl;
	cout << "**********Object model of bed**********" << endl;
	bed b1;
	cout << "sizeof bed object is : " << sizeof(b1) << endl;
	cout << "b1              ->  " << &b1 << endl;
	long long** baseAddressOfBed = (long long**)(&b1);
	FUNC furFuncInBed;
	furFuncInBed = (FUNC)baseAddressOfBed[0][0];
	furFuncInBed();
	FUNC furFunc2InBed;
	furFunc2InBed = (FUNC)baseAddressOfBed[0][1];
	furFunc2InBed();
	FUNC bedFunc2InBed;
	bedFunc2InBed = (FUNC)baseAddressOfBed[0][2];
	bedFunc2InBed();
	cout << "b1.m_furWeight  ->  " << &b1.m_furWeight << endl;
	cout << "b1.m_bedWeight  ->  " << &b1.m_bedWeight << endl;


	cout << endl;
	cout << "**********Object model of sofabed**********" << endl;
	sofabed sofBed1;
	cout << "sizeof sofabed object is : " << sizeof(sofBed1) << endl;
	cout << "sofBed1                  ->  " << &sofBed1 << endl;
	long long** baseAddressOfSofaBed = (long long**)(&sofBed1);
	FUNC furFuncPtrOfSofaBed;
	furFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][0];
	furFuncPtrOfSofaBed();
	FUNC furFunc2PtrOfSofaBed;
	furFunc2PtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][1];
	furFunc2PtrOfSofaBed();
	FUNC sofaFuncPtrOfSofaBed;
	sofaFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][2];
	sofaFuncPtrOfSofaBed();
	FUNC sofabedFuncPtrOfSofaBed;
	sofabedFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][3];
	sofabedFuncPtrOfSofaBed();

	cout << "sofBed1.sofa::m_furWeight        ->  " << &sofBed1.sofa::m_furWeight      << endl;
	cout << "sofBed1.m_sofaWeight             ->  " << &sofBed1.m_sofaWeight           << endl;	

	bed* pBed = static_cast<bed*>(&sofBed1);
	cout << "bed of sofBed1                  ->  " << pBed << endl; //slice of object
	
	furFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][0];
	furFuncPtrOfSofaBed();
	furFunc2PtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][1];
	furFunc2PtrOfSofaBed();
	FUNC bedFuncPtrOfSofaBed;
	bedFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][2];
	bedFuncPtrOfSofaBed();

	cout << "sofBed1.bed::m_furWeight         ->  " << &sofBed1.bed::m_furWeight       << endl;
	cout << "sofBed1.m_bedWeight              ->  " << &sofBed1.m_bedWeight            << endl;
	cout << "sofBed1.m_sofabedWeight          ->  " << &sofBed1.m_sofabedWeight        << endl;		
}

//test case 4: object model with virtual function
void test_object_model_virtual_accesslevel()
{
	using namespace virtual_accesslevel_interface;

	typedef void(*FUNC)();

	cout << endl;
	cout << "**********Object model of furniture**********" << endl;
	
	

	cout << endl;
	cout << "**********Object model of sofa**********" << endl;
	sofa s1;
	cout << "sizeof sofa object is : " << sizeof(s1) << endl;
	cout << "s1 address is   ->  " << &s1 << endl;
	long long** baseAddressOfSofa = (long long**)(&s1);
	FUNC furFuncPtrInSofa;
	furFuncPtrInSofa = (FUNC)baseAddressOfSofa[0][0];
	furFuncPtrInSofa();
	FUNC furFunc2PtrInSofa;
	furFunc2PtrInSofa = (FUNC)baseAddressOfSofa[0][1];
	furFunc2PtrInSofa();
	cout << "s1.m_furWeight  ->  " << &s1.m_furWeight << endl;
	cout << "s1.m_sofaWeight ->  " << &s1.m_sofaWeight << endl;


	cout << endl;
	cout << "**********Object model of bed**********" << endl;
	bed b1;
	cout << "sizeof bed object is : " << sizeof(b1) << endl;
	cout << "b1              ->  " << &b1 << endl;
	long long** baseAddressOfBed = (long long**)(&b1);
	FUNC furFuncInBed;
	furFuncInBed = (FUNC)baseAddressOfBed[0][0];
	furFuncInBed();
	FUNC furFunc2InBed;
	furFunc2InBed = (FUNC)baseAddressOfBed[0][1];
	furFunc2InBed();
	cout << "b1.m_furWeight  ->  " << &b1.m_furWeight << endl;
	cout << "b1.m_bedWeight  ->  " << &b1.m_bedWeight << endl;


	cout << endl;
	cout << "**********Object model of sofabed**********" << endl;
	sofabed sofBed1;
	cout << "sizeof sofabed object is : " << sizeof(sofBed1) << endl;
	cout << "sofBed1 (also the sofa part)     ->  " << &sofBed1 << endl;
	long long** baseAddressOfSofaBed = (long long**)(&sofBed1);
	FUNC furFuncPtrOfSofaBed;
	furFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][0];
	furFuncPtrOfSofaBed();
	FUNC furFunc2PtrOfSofaBed;
	furFunc2PtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][1];
	furFunc2PtrOfSofaBed();
	FUNC sofaFuncPtrOfSofaBed;
	sofaFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[0][2];
	sofaFuncPtrOfSofaBed();

	cout << "sofBed1.sofa::m_furWeight        ->  " << &sofBed1.sofa::m_furWeight << endl;
	cout << "sofBed1.m_sofaWeight             ->  " << &sofBed1.m_sofaWeight << endl;

	bed* pBed = static_cast<bed*>(&sofBed1);

	//slice of object
	cout << "bed(part) of sofBed1             ->  " << pBed << endl;

	furFuncPtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][0];
	furFuncPtrOfSofaBed();
	furFunc2PtrOfSofaBed = (FUNC)baseAddressOfSofaBed[3][1];
	furFunc2PtrOfSofaBed();

	cout << "sofBed1.bed::m_furWeight         ->  " << &sofBed1.bed::m_furWeight << endl;
	cout << "sofBed1.m_bedWeight              ->  " << &sofBed1.m_bedWeight << endl;
	cout << "sofBed1.m_sofabedWeight          ->  " << &sofBed1.m_sofabedWeight << endl;
}


int main()
{
	test_object_model_virtual_function();
	test_object_model_virtual_accesslevel();
	return 0;
}