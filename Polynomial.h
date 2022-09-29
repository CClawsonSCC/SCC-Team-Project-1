#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>


/*A Polynomial which is a doubly-linked list of Terms.*/
class Term {
public:
	// Data fields
	int coefficient, exponent; // Stores coefficient and exponent of Polynomial
	Term* next; // A pointer to the next term in the Polynomial
	Term* prev; // A pointer to the previous term in the Polynomial

	// Constructor
	Term(const int&, const int&);
};
//Implementation of class {Term}

// Default constructor
Term::Term(const int& coefficient, const int& exponent): coefficient(coefficient), exponent(exponent), next(NULL), prev(NULL) {}

class Polynomial {
public:
private:
	/*A Term of Polynomial*/
	struct Term;

};
#endif
