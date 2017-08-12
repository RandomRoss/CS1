#include <iostream>
#include <cmath>
using namespace std;

//factorial function 
double factorial(double num){
    double answer1 = 1;
    for (double  k = num;k>0;k--){
    answer1 = answer1 * k;
    
    }
    return answer1;
}

int main(){
    // for loop making it run a total of 25 times 
for (double i = 1;i<=25;i++){
    // displaying factorials
    cout << i <<"! = " << factorial(i)<< endl;
}
return 0; 
}
