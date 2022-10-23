#ifndef PARSER_H
#define PARSER_H

#include "Term.h"

#include <list>
#include <string>

using std::list;
using std::string;

/**
 * @brief Parser class that holds three ordered linked lists of terms.
 * This class is to be used by the main function.
 *
 * @author Connor Clawson
*/
class Parser
{
public:
	// Member functions.
	void assign_first(const string);
	void assign_second(const string);
	void calculate_result();
	string print();

private:
	// Data fields.
	list<Term> poly1;
	list<Term> poly2;
	list<Term> results;
	list<int> something;

	// Member functions.
	void read_input(const string, list<Term>&);
	void insert(Term, list<Term>&);
};

#endif // !PARSER_H