// Project 1-b.cpp : this file contains the 'main' function. program execution begins and ends there.
// Lubaba Masangu
#include "Parser.h"

#include <iostream>
using namespace std;

int main()
{
	Parser parser;
	while (true)
	{
		int menu_number;
		cout << "1 = First Polynomial:" << endl;
		cout << "2 = Second Polynomial:" << endl;
		cout << "3 = Calculate the results:" << endl;
		cout << "4 = Show the results:" << endl;
		cout << "5 = Exit the program:" << endl;

		// 1 to 4 will call a function from the parse
		// 5 will return 0 to tell the program to exit.

		cout << "Please select an option on the menu above" << endl;
		cin >> menu_number;// or size_t
		if (menu_number == 1) {
			cout << "enter polynomials in a user - friendly fashion." 
				<< endl << "For instance, 3X3 - X2 + 1 should be entered as 3x^3-x^2+1." 
				<< endl;
			string input;
			cin >> input;
			parser.assign_first(input);
			continue;
		}

		else if (menu_number == 2) {
			cout << "enter polynomials in a user - friendly fashion."
				<< endl << "For instance, 3X3 - X2 + 1 should be entered as 3x^3-x^2+1."
				<< endl;
			string input;
			cin >> input;
			parser.assign_second(input);
			continue;
		}

		else if (menu_number == 3) {
			parser.calculate_result();
			cout << " Polynomial added " << endl;
			continue;
		}

		else if (menu_number == 4) {
			cout << parser.print() << endl;
			continue;
		}

		else if (menu_number == 5) {
			return 0;
		}
	}
}