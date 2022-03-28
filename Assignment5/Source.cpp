#include "converters.h"
#include <iostream>

using namespace std;

int main() {
	char str[100];

	converters Q1(15, 2);
	cout << "15, base 2" << endl; // 1111
	_itoa_s(15, str, 2);
	cout << " formula: " << str;
	cout << "\nmethod 1: ";
	Q1.converterA();
	cout << "\nmethod 2: " << Q1.converterB();
	cout << "\nmethod 3: " << Q1.converterC();

	converters Q2(38, 16);
	cout << "\n\n38, base 16" << endl; // 26
	_itoa_s(38, str, 16);
	cout << " formula: " << str;
	cout << "\nmethod 1: ";
	Q2.converterA();
	cout << "\nmethod 2: " << Q2.converterB();
	cout << "\nmethod 3: " << Q2.converterC();

	converters Q3(54, 6);
	cout << "\n\n54, base 6" << endl; //130
	_itoa_s(54, str, 6);
	cout << " formula: " << str;
	cout << "\nmethod 1: ";
	Q3.converterA();
	cout << "\nmethod 2: " << Q3.converterB();
	cout << "\nmethod 3: " << Q3.converterC();

	converters Q4(19, 8);
	cout << "\n\n19, base 8" << endl; // 23
	_itoa_s(19, str, 8);
	cout << " formula: " << str;
	cout << "\nmethod 1: ";
	Q4.converterA();
	cout << "\nmethod 2: " << Q4.converterB();
	cout << "\nmethod 3: " << Q4.converterC();

	converters Q5(27, 3);
	cout << "\n\n27, base 3" << endl; // 1000
	_itoa_s(27, str, 3);
	cout << " formula: " << str;
	cout << "\nmethod 1: ";
	Q5.converterA();
	cout << "\nmethod 2: " << Q5.converterB();
	cout << "\nmethod 3: " << Q5.converterC();

	cout << "\n";

	string answer = "Y";
	while (answer != "N" && answer != "n") {
		try {
			cout << "\nchoose a POSITIVE BASE 10 number: ";
			int dec;
			cin >> dec;

			cout << "choose a base to convert to between 1 and 16: ";
			int base;
			cin >> base;

			converters fun(dec, base);

			cout << "\n" << dec << ", base " << base << endl;

			_itoa_s(dec, str, base);
			cout << " formula: " << str;

			cout << "\nmethod 1: ";
			fun.converterA();

			cout << "\nmethod 2: " << fun.converterB();

			try {
				cout << "\nmethod 3: " << fun.converterC() << "\n";
			}
			catch (string error) {
				cout << error;
			}

			cout << "\nwould you like to go again(Y/N)? ";
			cin >> answer;
		}
		catch (string error) {
			cout << error;
		}
	}
}