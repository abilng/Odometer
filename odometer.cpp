#include <iostream>
#include <string>
#include <algorithm>

#define MIN 1
#define MAX 9
#define BASE 10

using namespace std;

class Odometer {
	
private:
  int length;
  int min;
  int max;

  bool isValidNumber(int);
  
public:
  Odometer(int);
  int nextNumber(int);
  int previousNumber(int);
  int difference(int, int);
  void swap(int *, int *);
};


Odometer::Odometer(int length) {
  this->length = length;
  
  min=0;
  for(int i = 1; i <= length; i++) {
    min = min*BASE + i;
  }
  max=0;
  for(int i = 0; i <length; i++) {
    max = max*BASE + (BASE-length+i);
  }
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
  int validCount = 0;
  int i = number1;
  while ( i != number2 ) {
    if (isValidNumber(i)) {
      validCount++;
    }
    i = (i < max) ? i+1 : min ;
  }
  return validCount;
}


int main() {
  Odometer odometer(5);
  cout << odometer.nextNumber(12389) << endl;
  cout << odometer.previousNumber(23468) << endl;
  cout << odometer.difference(12345,56789) << endl; 
  return 0;
}
