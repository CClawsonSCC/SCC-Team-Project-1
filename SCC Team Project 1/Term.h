#ifndef TERM_H
#define TERM_H

/* A Term contains the exponent and coefficient of Polynomial */
class Term {
public:
	// Constructor
	Term();
	Term(const int); // Exponent is 0
	Term(int = 1, const int = 1); // Copy constructor

	// Getters 
	int get_coefficient() const;


	// Setters
	void set_coefficient(int);

	// Operator
	bool operator == (const Term& other) const;
	bool operator < (const Term& other) const;

private:
	//Data fields
	int coefficient; // Stores coefficient of Polynomial
	const int exponent; // Stores exponent of Polynomial
};

#endif // !TERM_H
