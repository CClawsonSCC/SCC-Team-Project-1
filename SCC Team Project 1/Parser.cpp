#include "Parser.h"
#include "Windows.h"

using std::exception;
using std::to_string;

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
	OutputDebugStringA("Testing");
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
	if (poly1.empty()) // Polynomial is empty.
	{
		return "Empty Polynomial.";
	}

	// polynomial is NOT empty.
	list<Term>::iterator it = poly1.begin();
	string result_str = "";
	do
	{
		result_str.append(to_string(it->get_coefficient()) + "x^" + to_string(it->get_exponent()));

		it++;
	} while (it != poly1.end()); // must execute at least once.

	return result_str;
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
	int value_size = 0;
	bool is_negative = false;
	bool is_exponent = false;

	polynomial.clear();

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
				// We are going to iterate through the numbers
				for (; i < in_string.size() - 1; i++) { value_size++; }
				
				if (is_exponent) { exponent = stoi(in_string.substr(i, i + value_size))* (is_negative ? -1 : 1); }
				else { coeficient = stoi(in_string.substr(i, i + value_size)) * (is_negative ? -1 : 1);	}

				value_size = 0;

				if (is_exponent) { insert(Term(coeficient, exponent), polynomial); }

				// if we are at the end of the string or the next character is + or -...
				else if ((i == in_string.size() - 1) || 
					((in_string.at(i + 1) == '+') || (in_string.at(i + 1) == '-')))
				{
					// term is a whole number or last number
					insert(Term(coeficient, 0), polynomial);
				}
				
				is_exponent = false;
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
void Parser::insert(Term term, list<Term>& polynomial)
{
	if (polynomial.empty())	{ polynomial.push_back(term); }
	else
	{
		list<Term>::iterator it = polynomial.begin();
		do
		{
			if (it->get_exponent() == term.get_exponent())
			{
				it->set_coefficient(it->get_coefficient() + term.get_coefficient());
				*it = term + *it;
			}
			else if (*it < term) // if term at iterator has smaller exponent...
			{
				polynomial.insert(it, term);
			}
		} while (it != polynomial.end());
	}
}
