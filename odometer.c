#include <iostream>
#include <string>
#include <algorithm>

#define MIN 1
#define MAX 9
#define BASE 10

using namespace std;

class Odometer {
	
	public:
		int length, min, max;
		Odometer(int);
		int getMinimum();
		int getMaximum();
		bool isValidNumber(int);
		int nextNumber(int);
		int previousNumber(int);
		int difference(int, int);
		void swap(int *, int *);
};

int Odometer::getMinimum() {
	int min;
	for(int i = 1; i <= length; i++) {
		min = (min + i) * BASE;
	}
	return min /= 10;
}

int Odometer::getMaximum() {
	int max;
	for(int i = BASE - length; i < BASE; i++) {
		max = (max + i) * BASE;
	}
	return max /= 10;
}

Odometer::Odometer(int length) {
	this->length = length;
	min = getMinimum();
	max = getMaximum();
}

bool Odometer::isValidNumber(int number) {
	int previous = INT_MAX;
	for(int i = 0; i < length; i++) {
		if(previous <= number % 10) {
			return false;
		}
		previous = number % 10;
		number /= 10;
	}
	return true;
}

int Odometer::previousNumber(int number){
	int i = number <= min ? max : number - 1 ;
	while (!isValidNumber(i)) {
		i--;
	}
	return i;
}

int Odometer::nextNumber(int number) {
	int i = number >= max ? min : number + 1 ;
	while (!isValidNumber(i)) {
		i++;
	}
	return i;
}

int Odometer::difference(int number1,int number2){
	if (number1 > number2) {
		swap(&number1, &number1);
	}
	int validCount = 0;
	for (int i = number1 + 1 ; i < number2 ; i++ ) {
		if (isValidNumber(i)) {
			validCount++;
		}
	}
	return validCount + 1;
}

void Odometer::swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	Odometer odometer(5);
	cout << odometer.nextNumber(23456) << endl;
	cout << odometer.previousNumber(23468) << endl;
	cout << odometer.difference(23456, 35678) << endl;
	return 0;
}