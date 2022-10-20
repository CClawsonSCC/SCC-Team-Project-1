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

	string something = "123b";
	int num = stoi(something.substr(0, 3));

	parser.assign_first("1x^3+11x^1+5");

	cout << parser.print() << " " << num << endl;

	system("pause");
	return 0;
}