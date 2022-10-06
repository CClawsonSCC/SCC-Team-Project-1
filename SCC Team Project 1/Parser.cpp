#include "Parser.h"

void Parser::add()
{
	// itterate through each term in each list. only add together terms with matching exponents.
}

void Parser::assign_first(const string in_string)
{
	read_input(in_string, poly1); // this will assign terms to the chosen list
}

void Parser::assign_second(const string in_string)
{
	read_input(in_string, poly2);
}

void Parser::calculate_result()
{
	// iterate through the result array and write the result of each term to the string.
}

string Parser::print()
{
	string result = "";
	
	return result;
}

void Parser::read_input(const string in_string, list<int> polynomial) // Should return Term;
{
	int value = 0;
	int value_size = 0;
	bool is_negative = false;
	bool is_exponent = false;

	for (size_t i = 0; i < in_string.size(); i++)
	{
		char element = in_string.at(i);

		switch (element)
		{
		case '-':
			is_negative = true;
			// waterfall to the next case...
		case '+':
			if (is_exponent)
			{
				// assign to exponent
				is_exponent = false;
			}
			break;
		case '^':
			is_exponent = true;
			break;
		}

		if ((element >= '0') && (element <= '9')) // Character is a numeric value
		{
			// FIXME: Prevent out of bounds.

			// get the substring of the entire value and convert it to an int
			value = stoi(in_string.substr(i, i + value_size));
		};
	}
}
