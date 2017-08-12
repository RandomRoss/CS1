#include <iostream>
#include <cmath>
using namespace std;
double factorialaddition;
//factorial function 
double factorial(double num){
    double answer1 = 1;
    for (double  k = num;k>0;k--){
    answer1 = answer1 * k;
    
    }
    return answer1;
}
// myExp function
double myExp(int num1){
   double e = 1.0; 
   for (double i = 1;i<=num1;i++){
       e = e  + (1/factorial(i));
   }
   return e;
}

int main(){
    // constant to check value 
    double number = 100;
    // e equals 
    cout << "e =: " << myExp(number);
    return 0;
}
