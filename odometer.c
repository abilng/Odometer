#include <iostream>
#include <string>
#include <algorithm>

#define MIN 1
#define MAX 9
#define BASE

class Odometer {
	
	public:
		int length, min, max;
		Odometer(int);
		bool isValidNumber(int)
		int nextNumber(int);
		int previousNumber(int);
		int difference(int, int);
		void createDigitsArray(int &);
		bool compare(int &, int);
};

Odometer::Odometer(int lenght) {
	this->length = length;
	min = max = 0;
	for(int i = 1; i <= length; i++) {
		min = (min + i) * BASE;
	}
	for(int i = BASE - length; i < BASE; i++) {
		max = (max + i) * BASE;
	}
}

void Odometer::createDigitsArray(int& digits) {
	for(int i = length - 1; i >= 0; i--) {
		digits[i] = number % 10;
		if(digits[i] == 0) {
			return false;
		}
		number /= 10;
	}
}

bool Odometer::compare(int &digits, int copy_number) {
	for(i = length - 1; i >= 0; i--) {
		if(digits[i] != (copy_number % 10)) {
			return false;
		}
		copy_number /= 10;
	}
	return true;
}

bool Odometer::isValidNumber(int number) {
	int digits[10];
	int copy_num = number;
	createDigitsArray(digits);
	sort(begin(digits), end(digits));
	return compare(digits, copy_number);
}