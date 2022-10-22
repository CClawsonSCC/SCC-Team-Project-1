#pragma once

#include "Term.h"

#include <list>
#include <string>

using std::list;
using std::string;

class Parser
{
public:
	void assign_first(const string);
	void assign_second(const string);
	void calculate_result();
	string print();

private:
	//replace <int> with <Term> soon.
	list<Term> poly1;
	list<Term> poly2;
	list<Term> results;
	list<int> something;
	
	void read_input(const string, list<Term>&);
	void insert(Term, list<Term>&);
};