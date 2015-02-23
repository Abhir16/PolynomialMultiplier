#include <cstddef>
#include <iostream>
#include "a1_polynomial.hpp"

using namespace std;


int main()
{
	
	cout<<"Hi"<<endl;
	int aCoeff[4]= {1,1,1,1};
	Polynomial* a = new Polynomial(aCoeff, 3);
	cout<<"Print"<<endl;
	//a.insertTerm(1,0);
//	a->print();
//	cout<<"A"<<endl;
//	a->insertTerm(1, 6);
//	cout << "inserted" << endl;
//	a->print();
//	
//	a->insertTerm(1, 4);
//	cout << "inserted" << endl;
//	a->print();
//	
	a->print();
	
	int bCoeff[4]= {0,1,1};
	Polynomial* c = new Polynomial(bCoeff, 2);
	c->print();
	cout << "multiplying" << endl;
	
	c->multiply(a);
	c->print();

	
	return 0;
}
