#include "a1_doubly_linked_list.hpp"

#ifndef A1_POLYNOMIAL_HPP
#define A1_POLYNOMIAL_HPP



class Polynomial{
private:
	DoublyLinkedList var;

	
public:
	// Can be seen outside as SequentialList::DataType	
	int highestDegree;
	
	
	//default constructor
	Polynomial();
	
	//constructor with an array with coefficients and its degree
	Polynomial(int deg);
	Polynomial(int coeff[], int deg);
	
	void insertTerm(int data, int deg);
	
	void multiply(Polynomial* const& poly);
	
	void print();
	
	int get_degree()
	{
		return highestDegree;
	}
	
	

};
#endif

