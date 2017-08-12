#include <iostream>
#include <cmath>
using namespace std;
// function calculating current
double current(double res,double volt){
    double cur = volt / res; 
    
    return cur; 
}
// function calculating power 
double power(double x, double y){
    double powers = x * y;
    
    return powers;
}
int main() {
    double res;
    double volt;
    // prompting user for input 
    cout << "Enter the resistance:";
    cin >> res;
    cout << "Enter the voltage:";
    cin >> volt;
    
   double currcalc = current(res,volt);
    double powercalc = power(volt,currcalc);
    // displaying the calculations
    cout << "Resistance:" << res <<" ohm" << endl; 
	cout << "Voltage:" << volt << " volts" << endl;
    cout << "Current:" << currcalc << " Amps"<< endl; 
    cout << "Power:" << powercalc <<" Watts"<< endl;
    
     return 0;
}
