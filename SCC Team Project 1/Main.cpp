#include "Parser.h"

#include <iostream>

using namespace std;

/*
	* The code from each of your branches will be implemented here
	* when the branches are merged and the code is fleshed out more.
	*
	* In the mean time, use this file to test your portion of the
	* code.
	*
	* Connor Clawson.
	*/

int main()
{
	Parser parser;

	parser.assign_first("13x^2+9");

	cout << parser.print() << endl;

	system("pause");
	return 0;
}