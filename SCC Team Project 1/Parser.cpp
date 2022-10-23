#include "Parser.h"

using std::exception;
using std::to_string;

/**
 * @brief Passes the user inputed polynomial to the parser for assignment
 * to the first polynomal list.
 * @param in_string - User input string.
*/
void Parser::assign_first(const string in_string)
{
	read_input(in_string, poly1);
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
	results = poly1; // bring over the first polynomial.
	while (!poly2.empty()) // while the second polynomial has elements.
	{
		insert(poly2.front(), results); // use insert() to sum the terms.
		poly2.pop_front(); // remove the now added term from the second polynomial.
	}
}

/**
 * @brief Outputs the summed results list as a polynomial.
 * @return the summed polynomial as a string.
*/
string Parser::print()
{
	// Polynomial is empty.
	if (results.empty()) { return "Empty Polynomial."; }

	// polynomial is NOT empty.
	string result_str = "";

	// Using iterators, go through each term and concatenate the values to a string. 
	for (list<Term>::iterator it = results.begin(); it != results.end(); it++)
	{
		if (it->get_coefficient() == 0)	{ continue; } // If a result term solved to 0, ignore it.

		// It's not the first term and the coeficient is positive.
		if ((it != results.begin()) && (it->get_coefficient() > 0))	{ result_str.append("+"); }

		// The coefficient is neither 1 or -1, or the exponent is 0.
		if (((it->get_coefficient() != 1) && (it->get_coefficient() != -1)) || (it->get_exponent() == 0))
		{
			result_str.append(to_string(it->get_coefficient()));
		}

		// Coeficient is -1.
		if (it->get_coefficient() == -1) { result_str.append("-"); }

		// The exponent isn't 0.
		if (it->get_exponent() != 0)
		{
			// Output the variable. If the exponent is not 1, output the exponent.
			result_str.append("x" + (it->get_exponent() != 1 ? ("^" + to_string(it->get_exponent())) : ""));
		}
	}
	return result_str;
}
	

// Private Functions

/**
 * @brief Parses the user inputed polynomial into a useable list of terms.
 * @param in_string - User input string.
 * @param polynomial - the list to record the polynomial to.
*/
void Parser::read_input(const string in_string, list<Term>& polynomial)
{
	// Function data fields.
	int coefficient = 0;
	int exponent = 0;
	bool is_negative = false;
	bool is_exponent = false;

	polynomial.clear(); // Clear the list of any left over terms.

	// Iterate through the string
	for (size_t i = 0; i < in_string.size(); i++)
	{
		char element = in_string.at(i); // Get the character at the current index.

		if (element == '-')	{ is_negative = true; }  // The next value is negative.
		else if (element == '+') { continue; } // It is asumed the next value is positive.
		else if (element == '^') { // The next value is an exponent.
			is_exponent = true;
		}
		else if (element == 'x') // Character is a variable.
		{
			//if no coeficient given
			if ((i == 0) || ((in_string.at(i-1) == '+') || (in_string.at(i - 1) == '-')))
			{
				coefficient = 1 * (is_negative ? -1 : 1);
			}

			//if no exponent given
			if ((i == in_string.size() - 1) || (in_string.at(i + 1) != '^'))
			{
				insert(Term(coefficient, 1), polynomial);
			}
		}
		else if ((element >= '0') && (element <= '9')) // Character is a numeric value
		{
			int val = in_string.at(i) - 48; // Subtract the character by 0's ascii value of 48.

			// Iterate through and get the entire value.
			while ((i != in_string.size() - 1) && ((in_string.at(i + 1) >= '0') && (in_string.at(i + 1) <= '9')))
			{
				i++;
				val = (val * 10) + (in_string.at(i) - 48);
			}
			
			val *= is_negative ? -1 : 1; // If the value entered was negative, make it negative.
			
			// assign the value to either the coefficient or the exponent.
			if (is_exponent) { exponent = val; }
			else { coefficient = val; }

			// If the exponent is not 0, add it to the list.
			if (exponent != 0) { insert(Term(coefficient, exponent), polynomial); }

			// if we are at the end of the string or the next character is + or -...
			else if ((i == in_string.size() - 1) ||
				((in_string.at(i + 1) == '+') || (in_string.at(i + 1) == '-')))
			{    
				// term is a whole number or last number, add it to the list.
				insert(Term(coefficient, 0), polynomial);
			}

			// Reset values for the next loop
			coefficient = 0;
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
*/
void Parser::insert(Term term, list<Term>& polynomial)
{
	// Terms with a coeficient of 0 always evaluate to 0, so don't add anything!
	if (term.get_coefficient() == 0) { return; }

	// Otherwise, add the term.
	if (polynomial.empty())	{ polynomial.push_back(term); }

	// If there is only one term in the list...
	else if (polynomial.size() == 1)
	{
		// and they share the same exponent, add the terms.
		if (polynomial.front().get_exponent() == term.get_exponent())
		{
			polynomial.front() = term + polynomial.front();
		}

		// and the new term has larger exponent, push it to the front.
		else if (polynomial.front().get_exponent() < term.get_exponent())
		{
			polynomial.push_front(term);
		}
		else // and the new term has a smaller exponent, push it to the back.
		{
			polynomial.push_back(term);
		}
	}
	else // There's more than one term in the list. 
	{
		// Go through the list to find it's proper spot.
		for (list<Term>::iterator it = polynomial.begin(); it != polynomial.end(); it++)
		{
			// A like term has been found. Add them.
			if (it->get_exponent() == term.get_exponent()) 
			{
				*it = term + *it;
				return;
			}

			// the term is higher than the one at the iterator.
			else if (it->get_exponent() < term.get_exponent()) 
			{
				polynomial.insert(it, term);
				return;
			}
		}

		// If the term is the lowest, push it to the back.
		if (polynomial.back().get_exponent() > term.get_exponent())
		{
			polynomial.push_back(term);
		}
	}
}
