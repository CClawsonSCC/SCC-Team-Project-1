#ifndef TERM_H
#define TERM_H

/* A Term contains the exponent and coefficient of Polynomial */
class Term {
public:
    // Constructor
    Term(int = 0, int = 0); // Default constructor

    // Getters
    int get_coefficient() const;
    int get_exponent() const;


    // Setters
    void set_coefficient(int);

    // Operator
    bool operator == (const Term& other) const; //heck whether the current equal to other term using exponent
    bool operator < (const Term& other) const; //Check whether the current less than other term using exponent
    Term operator + (const Term& other) const; // Add in another Term with the same exponent
private:
    //Data fields
    int coefficient; // Stores coefficient of Polynomial
    int exponent; // Stores exponent of Polynomial
};

#endif // !TERM_H

