#include "Parser.h"
using std::exception;

/**
 * @brief Iterates through the input polynomials and adds like-terms,
 * the total sum is recorded to the results polynomial list.
*/
void Parser::add()
{
	// itterate through each term in each list. only add together terms with matching exponents.
	//FIXME: implement Thanh's Term class.
}

/**
 * @brief Passes the user inputed polynomial to the parser for assignment
 * to the first polynomal list.
 * @param in_string - User input string.
*/
void Parser::assign_first(const string in_string)
{
	read_input(in_string, poly1); // this will assign terms to the chosen list.
}

/**
 * @brief Passes the user inputed polynomial to the parser for assignment
 * to the second polynomal list.
 * @param in_string - User input string.
*/
void Parser::assign_second(const string in_string)
{
	read_input(in_string, poly2);
}

/**
 * @brief Sums both user input polynomials by adding like-terms from both
 * polynomials and records the results to the results list.
*/
void Parser::calculate_result()
{
	// iterate through the result array and write the result of each term to the string.
}

/**
 * @brief Outputs the summed results list as a polynomial.
 * @return the summed polynomial as a string.
*/
string Parser::print()
{
	return "this string to be replaced with the result.";
}
	

// Private Functions

/**
 * @brief Parses the user inputed polynomial into a useable 
 * @param in_string - User input string.
 * @param polynomial - the list to record the polynomial to.
*/
void Parser::read_input(const string in_string, list<Term>& polynomial)
{
	int coeficient = 0;
	int exponent = 0;
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
				int value = stoi(in_string.substr(i, i + value_size)) * (is_negative ? -1 : 1);
				is_negative = false;
				is_exponent ? (true /* exponent = value */) : (false /* base = value */);
				is_exponent = false;

				polynomial.push_back(value);

				//assign {value} to the coeficient or the exponent;
				// push the new term to the list.

				i = i + value_size - 1; // advance to the last digit in the number.
			}
		}
	}
}

/**
 * @brief Iterate through the list and inserts the term into its ordered place.
 * @param term - the newly created term.
 * @param polynomial - linked list of polynomials.
 * @todo: create and test this function.
*/
void Parser::insert(int term, list<Term>& polynomial)
{
}
