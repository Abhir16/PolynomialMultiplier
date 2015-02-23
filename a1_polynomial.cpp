#include "a1_polynomial.hpp"
#include "a1_doubly_linked_list.hpp"
#include <cstddef>
#include <iostream>
using namespace std;
	
	Polynomial::Polynomial()
	{
		//DoublyLinkedList var();
		bool check = var.insert_back(0);
		highestDegree = 0;		
	}
	
	Polynomial::Polynomial(int deg)
	{
		highestDegree = deg;	
		//add 0 coefficients
	}
	
	Polynomial::Polynomial(int coeff[], int deg)
	{
		cout<<"Starting"<<endl;
		highestDegree = deg;
		for (int i = 0; i<= deg; i++)
		{
			var.insert_back(coeff[i]);
		}
		cout<<"Done building"<<endl;
	}
		
	void Polynomial::insertTerm (int data, int deg)
	{
	//	cout << "checking insertterm" << endl;
		if (highestDegree < deg)
		{
		//	cout << "check 1" << endl;
			for(int i = highestDegree+1; i < deg; i++)
			{
				var.insert(0, i);
			}
		//	cout << "check 2" << endl;
			var.insert(data, deg);
			highestDegree = deg;
		
		}
		else if(highestDegree >= deg)
		{
			
			int prevalue = var.select(deg);
			var.replace(deg, data + prevalue);
		}			
	}
	
   	void Polynomial::multiply(Polynomial* const & poly)
	{
		Polynomial* temp = new Polynomial(highestDegree);
		
		//create a temp copy of original polynomial
		for(int i = 0; i <= highestDegree; i++){
			temp -> var.insert(var.select(i),i);
			var.replace(i,0);
		}
		
		int value;
		for(int i = highestDegree; i >= 0; i--)
		{
			for(int x = poly->highestDegree; x>=0; x--)
			{
				value = poly->var.select(x) * temp->var.select(i);
				insertTerm(value, (x + i));
			}
		}
		
		highestDegree += poly->highestDegree;
		delete temp;
		temp=NULL;
		
	}

	
	void Polynomial::print()
	{
		var.print();
	}
	
	
