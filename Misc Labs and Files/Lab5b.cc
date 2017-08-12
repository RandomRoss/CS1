#include <iostream>
#include <cmath>
using namespace std;
// declaring global variables 
int number = 1;
int i = 1;
// function to find prime number 
bool prime(int number){
    // if the  number is less than 2 then the number is not prime making it return false 
    if(number <= 1){
        return false;
    }
    // for loop determining if the number is prime or not
    for(int k = 2; k <= number - 1; ++k){
        if (number % k == 0){
            return false; 
        }
    }
    i = i + 1;
//    number = number + 1;
    return true;
    }
int main(){
    //i = 1;
    int number = 1;
    while(i <= 50){
    // dispalaying the number if the number is prime
    // does not display if the number is prime
        if (prime(number)){
            cout << number << " is prime" << endl;
        }
        number++;

    }
    return 0; 
}
