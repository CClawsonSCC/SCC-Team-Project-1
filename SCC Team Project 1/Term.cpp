#include"Term.h"

// Default constructor
Term::Term(int coefficient, int exponent) : coefficient(coefficient), exponent(exponent) { }

// Getters
/* Get the coefficient
    @return the coefficient
*/
int Term::get_coefficient() const { return coefficient; }
/* Get the exponent
    @return the exponent
*/
int Term::get_exponent() const { return exponent; }

// Setters
/* Updates the coefficient
*    @param coeff: the coeeficient
*/
void Term::set_coefficient(int coeff) { coefficient = coeff; }

/* Check whether the current equal to other term using exponent
*    @param other:the exponent of other term
*    @return: {True} if there is equal; {false} for there is no equal
*/
bool Term::operator == (const Term& other) const {
    return (get_coefficient() == other.get_coefficient());
}

/* Check whether the current less than other term using exponent
*    @param other:the exponent of other term
*    @return: {True} if exponent of current term is less than the other term; {false} if exponent of current term is not less than the other term
*/
bool Term::operator < (const Term& other) const {
    return (get_coefficient() < other.get_coefficient());
}

/*Adds two Term with the same exponent
    @param other: the other term
    @return a Term after adding two term
 */
Term Term::operator + (const Term& other) const {
    Term result;
    result.coefficient = coefficient + other.coefficient;
    result.exponent = exponent;
    return  result;
}
