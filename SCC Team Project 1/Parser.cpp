#include "Parser.h"
#include "Windows.h"

using std::exception;
using std::to_string;

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
	results = poly1;
	while (!poly2.empty())
	{
		insert(poly2.front(), results);
		poly2.pop_front();
	}
}

/**
 * @brief Outputs the summed results list as a polynomial.
 * @return the summed polynomial as a string.
*/
string Parser::print()
{
	
	if (results.empty()) // Polynomial is empty.
	{
		return "Empty Polynomial.";
	}
	//return to_string(poly1.size());

	// polynomial is NOT empty.
	
	string result_str = "";
	for (list<Term>::iterator it = results.begin(); it != results.end(); it++)
	{
		if ((it != results.begin()) && (it->get_coefficient() > 0))
		{
			result_str.append("+");
		}

		if ((it->get_coefficient() != 1) || (it->get_exponent() == 0))
		{
			result_str.append(to_string(it->get_coefficient()));
		}

		if (it->get_coefficient() == -1)
		{
			result_str.append("-");
		}

		if (it->get_exponent() != 0)
		{
			result_str.append("x" + (it->get_exponent() != 1 ? ("^" + to_string(it->get_exponent())) : ""));
		}
	}
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
	//Todo Implement powers of 1 support.
	int coeficient = 0;
	int exponent = 0;
	bool is_negative = false;
	bool is_exponent = false;

	polynomial.clear();

	for (size_t i = 0; i < in_string.size(); i++)
	{		
		char element = in_string.at(i);

		if (element == '-')	{ is_negative = true; }
		else if (element == '+') { is_negative = false; }
		else if (element == '^') {
			is_exponent = true;
			is_negative = false;
		}
		else if (element == 'x') 
		{
			//if no coeficient given
			if ((i == 0) || ((in_string.at(i-1) == '+') || (in_string.at(i - 1) == '-')))
			{
				coeficient = 1 * (is_negative ? -1 : 1);
			}

			//if no exponent given
			if ((i == in_string.size() - 1) || (in_string.at(i + 1) != '^'))
			{
				insert(Term(coeficient, 1), polynomial);
			}
		}
		else if ((element >= '0') && (element <= '9')) // Character is a numeric value
		{
			int val = in_string.at(i) - 48;
			while ((i != in_string.size() - 1) && ((in_string.at(i + 1) >= '0') && (in_string.at(i + 1) <= '9')))
			{
				i++;
				val = (val * 10) + (in_string.at(i) - 48);
			}
			
			val *= is_negative ? -1 : 1;
			
			if (is_exponent) { exponent = val; }
			else { coeficient = val; }

			if (exponent != 0) 
			{ 
				//insert(Term(coeficient, exponent), polynomial);
				insert(Term(coeficient, exponent), polynomial);
			}
			
			// 1x^3+1x+5
			else if ((i <= in_string.size() - 3) && (element == 'x'))
			{
				exponent = 1;
			}

			// if we are at the end of the string or the next character is + or -...
			else if ((i == in_string.size() - 1) ||
				((in_string.at(i + 1) == '+') || (in_string.at(i + 1) == '-')))
			{    
				// term is a whole number or last number
				//insert(Term(coeficient, 0), polynomial);
				insert(Term(coeficient, 0), polynomial);
			}

			exponent = 0;
			is_exponent = false;
			is_negative = false;
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
	// terms with a coeficient of 0 always evaluate to 0, so don't add anything!
	if (term.get_coefficient() == 0) { return; }

	// otherwise, add the term.
	if (polynomial.empty())	{ polynomial.push_back(term); }

	else if (polynomial.size() == 1)
	{
		// they share the same exponent.
		if (polynomial.front().get_exponent() == term.get_exponent())
		{
			polynomial.front() = term + polynomial.front();
		}

		else if (polynomial.front().get_exponent() < term.get_exponent()) // the new term has larger exponent...
		{
			polynomial.push_front(term);
		}
		else // the new term has a smaller exponent...
		{
			polynomial.push_back(term);
		}
	}
	else
	{
		for (list<Term>::iterator it = polynomial.begin(); it != polynomial.end(); it++)
		{
			if (it->get_exponent() == term.get_exponent())
			{
				*it = term + *it;
				return;
			}
			else if (it->get_exponent() < term.get_exponent())
			{
				polynomial.insert(it, term);
				return;
			}
		}

		if (polynomial.back().get_exponent() > term.get_exponent())
		{
			polynomial.push_back(term);
		}
	}
}
