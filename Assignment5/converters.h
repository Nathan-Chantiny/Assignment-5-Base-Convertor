#ifndef CONVERTERS_H
#define CONVERTERS_H
#include <string>

class converters {
public:
	

	converters(int dec, int base) : dec(dec), base(base) { errors(); }

	int getDec() { return dec; }
	int getBase() { return base; }

	void converterA();
	std::string converterB();
	int converterC();
private:
	void errors();

	int dec;
	int base;
};
#endif // !CONVERTERS_H
