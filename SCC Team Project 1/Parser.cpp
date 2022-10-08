#include "Parser.h"

void Parser::add()
{
	// itterate through each term in each list. only add together terms with matching exponents.
	//FIXME: implement Thanh's Term class.
}

void Parser::assign_first(const string in_string)
{
	read_input(in_string, poly1);
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
	// FIXME: explore the possibility of passing through an ostream instead of returning a string.
	string result = "this string will be replaced by the result.";

	return result;
}

// Private Functions

void Parser::read_input(const string in_string, list<int> polynomial) // Should return Term;
{
	int value = 0;
	int value_size = 1;
	bool is_negative = false;
	bool is_exponent = false;

	for (size_t i = 0; i < in_string.size(); i++)
	{
		char element = in_string.at(i);

		switch (element)
		{
		case '-':
			is_negative = true;
			break;
		case '+':
			is_negative = false;
			break;
		case '^':
			is_exponent = true;
			break;
		default: // get the substring of the entire value and convert it to an int
			if ((element >= '0') && (element <= '9')) // Character is a numeric value
			{
				size_t j = i;
				while (j < in_string.size() && // prevent out of bounds.
					((in_string.at(j) >= '0') && (in_string.at(j) <= '9'))) // only use numeric characters.
				{
					value_size++;
					j++; 
				}

				value = stoi(in_string.substr(i, i + value_size)) * (is_negative ? -1 : 1);
				is_negative = false;
				is_exponent ? (true /* exponent = value */) : (false /* base = value */);
				is_exponent = false;
				i = i + value_size - 1;
			};
		}
	}
}
