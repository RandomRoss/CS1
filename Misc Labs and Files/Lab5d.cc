#include <iostream>
#include <cmath>
using namespace std;
bool IsMultipleofX(int number, int X){
    if (number % X == 0){
        return true;
    }
    return false;
}
bool IsMultipleofFive(int number){
    if (number % 5  == 0){
        return true;
    }
    return false; 
}
bool IsMultipleofThree(int number){
    if(number % 3 == 0){
        return true;
    }
    return false; 
}
bool IsAnOddNumber(int number){
    if(number % 2 == 0){
        return false;
    }
    return true; 
}
bool IsAnEvenNumber(int number ){
    if(number % 2 == 0){
        return true;
    }
    return false; 
}
int main(){
int number = 1; 
int i; 
// for loop iterating 100 times 
for (i = 1; i<101; i++){
    cout << i << " - "; 
    // calling to see if number is Odd 
    if(IsAnOddNumber(i)){
        cout << "Odd";
    }
    // calling to see if number is even
    if(IsAnEvenNumber(i)){
        cout << "Even";
    }
    // calling to see if number is divisable by three 
    if(IsMultipleofThree(i)){
        cout << ",Three";
    }
    // calling to see if number is divisable by five 
    if(IsMultipleofFive(i)){
        cout << ",Five";
    }
    cout << endl;
}
return 0; 
}
