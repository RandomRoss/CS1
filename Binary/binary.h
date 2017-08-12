// makes sure that .h do not share the same header as other .h files 
// this is why #endif is at the end 
#ifndef BINARY_HEADER
#define BINARY_HEADER
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>
using namespace std;
//Jared Ross
//classes and functions went into the .h file for the binary-sandbox.cpp
// creating th Binary class
class Binary{
    
public:
Binary(string test) : binarynumber(test) {};
Binary() = default;
//adding binary numbers
friend Binary operator+(const Binary &lefthandside, const Binary &righthandside);
//subtracting binary numbers 
friend Binary operator-(const Binary &lefthandside, const Binary &righthandside);
//multiplication of binary numbers
friend Binary operator*(const Binary &lefthandside, const Binary &righthandside);
// division of binary numbers
friend Binary operator/(const Binary &lefthandside, const Binary &righthandside);
friend ostream &operator<<(ostream &, const Binary &);
friend istream &operator>>(istream &, Binary &);

private:
string binarynumber;
int todec() const;
string tobin(int number) const;
};

int Binary::todec() const{ 
int decnumber = 0;
int k = 0;
for(int i = binarynumber.size()-1; i >= 0; --i){
decnumber = decnumber + (binarynumber.at(i) - '0')*pow(2,k);
++k;
}
return decnumber;
}
//converting the givin string to binary
string Binary::tobin(int number) const { 
string answer = "";
while(number > 0){
answer.insert(answer.begin(), number % 2 + '0');
number = number / 2;
}
return answer;
}

// adding binary lefthandside and righthandside
Binary operator+(const Binary &lefthandside, const Binary &righthandside){
int value = lefthandside.todec() + righthandside.todec();
string result = lefthandside.tobin(value);
return Binary(result);
}
// subtraction binary lefthandside and righthandside
Binary operator-(const Binary &lefthandside, const Binary &righthandside){
int value = lefthandside.todec() - righthandside.todec();
string result = lefthandside.tobin(value);
return Binary(result);
}
// multiplication binary lefthandside and righthandside
Binary operator*(const Binary &lefthandside, const Binary &righthandside){
int value = lefthandside.todec() * righthandside.todec();
string result = lefthandside.tobin(value);
return Binary(result);
}
//division binary lefthandside and righthandside
Binary operator/(const Binary &lefthandside, const Binary &righthandside){
int value = lefthandside.todec() / righthandside.todec();
string result = lefthandside.tobin(value);
return Binary(result);
}

ostream &operator<<(ostream &cout, const Binary &b){
cout << b.binarynumber;
return cout;
}

istream &operator>>(istream &cin, Binary &b){
string temp;
cin >> temp;
b.binarynumber = temp;
return cin;
}
#endif
