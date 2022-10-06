#pragma once

#include <list>
#include <string>

using std::list;
using std::string;

class Parser
{
public:
	void add();
	void assign_first(const string);
	void assign_second(const string);
	void calculate_result();
	string print();

private:
	//replace <int> with <Term> soon.
	list<int> poly1;
	list<int> poly2;
	list<int> results;
};