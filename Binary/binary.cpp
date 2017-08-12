// Abreviated Rational Class with overloaded math operators +/-*
#include <cmath>
#include <iostream>
using namespace std;
//Jared Ross 
//binary addition subtraction, multiplication, division
int gcd(int, int);


class Rational
{

// The friend keyword is used to setup << and >> operators
// for use with the cin and cout streams.
  friend ostream   & operator<<(ostream&, const Rational &);
  friend istream   & operator>>(istream &,  Rational &);
public:
  Rational();	// Non overloaded constructor: set initial value to 0
  Rational(int);	// This allows the class to add an integer to
			// a rational number.

  Rational(int,int);	// Take in both numerator and denominator
  void SetRational(int,int);
  int GetDenom();
  int GetNum();
  Rational operator+(const Rational &);
  Rational operator-(const Rational &);
  Rational operator*(const Rational &);
  Rational operator/(const Rational &);
private:
  void Reduce();
  int Numerator;
  int Denominator;
};

Rational::Rational(){
  SetRational(0, 1);
}

// Assume denominator is 1. This allows us to have
// equations in the form of :
// X = Y + 1; 
// Where both X and Y are Rational numbers
Rational::Rational(int num){
  SetRational(num, 1);
}

Rational::Rational(int num, int den){
  SetRational(num, den);
}

int Rational::GetDenom()
{
  return Denominator;
}

int Rational::GetNum()
{
  return Numerator;
}

void Rational::SetRational(int num,int den){
  Numerator = num;
  Denominator  = den;

  Reduce();
}

// In all of these rhs is the "right hand side" of an equation. 
// For exmaple: X = Y + Z; The Z in that equation is the rhs.
// Note: Y in the above is the same as the "current" object which
//	 is why we do not have to use the dot operator.

// This section demostrates three different methods to create a new
// object.


// Addtion operator

// This is the preferred method for object creation
Rational Rational::operator+(const Rational &rhs){
  // Calculate the denominator and numerator of the new
  // Rational number 
  int new_Denominator = Denominator*rhs.Denominator;
  int new_Numerator   = (Numerator*rhs.Denominator) +
                        (rhs.Numerator*Denominator);

  // Use the builtin Constructor to build a new object out of
  // the numerator and denominator
  return Rational(new_Numerator, new_Denominator);
}

// subtraction operator
Rational Rational::operator-(const Rational &rhs){
  // Create a new object to hold the return value
  // This will leak memory.

  Rational *retval = new Rational;
  // Calculate the denominator and numerator of the new
  // Rational number 

  int new_Denominator = Denominator*rhs.Denominator;
  int new_Numerator   = (Numerator*rhs.Denominator) -
                        (rhs.Numerator*Denominator);

  retval->Numerator   = new_Numerator;
  retval->Denominator = new_Denominator;

  retval->Reduce();

  return *retval;
}

// multiplication operator
Rational Rational::operator*(const Rational &rhs){
  // Some compilers have issues with this way of doing
  // the return
  Rational retval;

  int new_Denominator = Denominator*rhs.Denominator;
  int new_Numerator   = Numerator*rhs.Numerator;

  retval.Numerator   = new_Numerator;
  retval.Denominator   = new_Denominator;

  retval.Reduce();

  return retval;
}

// divison operator. 
// Note: We combined a couple of steps in this one to elminate a couple
// of steps.
Rational Rational::operator/(const Rational &rhs){
  Rational *retval = new Rational;

  retval->Denominator = Denominator*rhs.Numerator;
  retval->Numerator   = Numerator*rhs.Denominator;
  retval->Reduce();

  return *retval;
}


void Rational::Reduce(){
  int GCD, OldDen;

  do {  // Try to reduce at least once
    // Reduce until no reductions possiable
    GCD = gcd(Denominator, Numerator);
    OldDen = Denominator;    //  Save a value;
    Numerator /= GCD;
    Denominator /= GCD;
  }
  while(Denominator != OldDen );
}

ostream & operator<<(ostream &output, const Rational &number){
  output << number.Numerator << "/" << number.Denominator;

  return output;
}

istream & operator>>(istream &input, Rational &number){
  input  >> number.Numerator;
  input.ignore(1);
  input >> number.Denominator;

  return input;
}

//gcd function definition
int gcd (int u, int v){
  int temp;

  while ( v != 0 )
  {
    temp = u % v;
    u = v;
    v = temp;
q
  }
  return (u);
}

int main()
{
  Rational R1(5), R2(6,2), R3(9,4), R4(120,12), R5;

  cout << "R1 = " << R1 << endl;
  cout << "R2 = " << R2 << endl;
  cout << "R3 = " << R3 << endl;
  cout << "R4 = " << R4 << endl;
  cout << "R5 = " << R5 << endl;

  cout << "R5 = R1 + R2: " << R1 << " + "  << R2 
       << " = " << R1 + R2 << endl;

  cout << "R5 = R1 + 6: " << R1 << " + "  << 6 
       << " = " << R1 + 6 << endl;

  cout << "R5 = R1 - R2: " << R1 << " - "  << R2 
       << " = " << R1 - R2 << endl;

  cout << "R5 = R1 * R2: " << R1 << " * "  << R2 
       << " = " << R1 * R2 << endl;

  cout << "R5 = R1 / R4: " << R1 << " / "  << R4 
       << " = " << R1 / R4 << endl;

  cout << "R5 = R1 / R4 + R4: " << R1 << " / "  << R4  << " + " << R4
       << " = " << R1 / R4 + R4 << endl;

  cout << "R5 = R1 - R2 + R3: " << R1 << " - "  << R2 << " + " << R3
       << " = " << R1 - R2 + R3 << endl;

  return 0;
}
