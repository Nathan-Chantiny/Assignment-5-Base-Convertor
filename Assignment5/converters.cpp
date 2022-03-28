#include "converters.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void converters::errors() {
	int dec = converters::getDec();
	int base = converters::getBase();

	if (dec < 0) {
		string negative = "\nchoose a POSITIVE INTEGER of BASE 10\n";
		throw negative;
	}
	else if (base < 2 || base > 16) {
		string badBase = "\nbase must be AT LEAST 2, but NO GREATER THAN 16\n";
		throw badBase;
	}
	else {

	}
}

void converters::converterA() {
	int dec = converters::getDec();
	int base = converters::getBase();

	vector<string> output;

	while (0 < dec) {
		if (dec % base > 9 && dec % base < 16) {
			string value(1, *(new char((dec % base) + 87)));
			output.push_back(value);
		}
		else {
			output.push_back(to_string(dec % base));
		}
		dec = dec / base;
	}

	for (auto i = output.rbegin(); i != output.rend(); ++i) {
		cout << *i;
	}
}

string converters::converterB() {
	int dec = converters::getDec();
	int base = converters::getBase();

	int a = dec;
	int b = 0;

	while (a > 0) {
		a = a / base;
		b++;
	}

	string output;
	int mod = 0;
	int d = dec;

	for (int i = 0; b > i; i++) {
		d = dec;
		for (int j = 0; b - i > j; j++) {
			mod = d % base;
			d = d / base;
		}

		if (mod > 9 && mod < 16) {
			string value(1, *(new char(mod + 87)));
			output.append(value);
		}
		else {
			output.append(to_string(mod));
		}
	}

	return output;
}

int converters::converterC() {
	int dec = converters::getDec();
	int base = converters::getBase();
	/*
	if (dec >= pow(base, 10)) {
		string overflow = "\nmethod 3: cannot handle numbers that big\n";
		throw overflow;
	}
	*/
	int a = dec;
	int b = 0;

	while (a > 0) {
		a = a / base;
		b++;
	}

	int output = 0;
	int mod = 0;
	int d = dec;

	for (int i = 0; b > i; i++) {
		d = dec;
		for (int j = 0; b - i > j; j++) {
			mod = d % base;
			if (mod >= 10) {
				string error = "\nmethod 3: cannot handle letters, method 3 returns an int value\n";
				throw error;
			}
			else {
				d = d / base;
			}
		}
		output = (output * 10) + mod;
	}

	return output;
}
