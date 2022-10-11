#include"Term.h"

// Default constructor
Term::Term(int coefficient, const int exponent) : coefficient(coefficient), exponent(exponent) { }

// Getters
/* Get the coefficient 
	@return the coefficient 

*/
int Term::get_coefficient() const { return coefficient; }

// Setters
/* Updates the coefficient
*	@param coeff: the coeeficient
*/
void Term::set_coefficient(int coeff) { coefficient = coeff; }

/* Check whether the current equal to other term using exponent
*	@param other:the exponent of other term
*	@return: {True} if there is equal; {false} for there is no equal
*/
bool Term::operator == (const Term& other) const {
	return (coefficient == other.coefficient);
}

/* Check whether the current less than other term using exponent
*	@param other:the exponent of other term
*	@return: {True} if exponent of current term is less than the other term; {false} if exponent of current term is not less than the other term
*/
bool Term::operator < (const Term& other) const {
	return (coefficient < other.coefficient);
}