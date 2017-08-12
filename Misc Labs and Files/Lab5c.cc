#include <iostream>
#include <cmath>
using namespace std;
    int maxvalue(int x, int y){
        if (x < y){
            return y;
        }
 return x;
    }
    int minvalue(int x, int y){
        if (x > y){
            return y;
        }
 return x;
    }
int main(){
    // initializing x and y
    int x;
    int y;
    //asking user for input of 2 values
    cout << "Enter a value (Posotive or Negative:";
    cin >> x;
    cout << endl; 
    cout << "Enter a value (Posotive or Negative:";
    cin >> y;
    cout << endl;

// testing/displaying maximum value
    cout << "The Maximum value is:"<< maxvalue(x,y) << endl;
// testing / displaying minimum value
    cout  << "The Minumum value is:" << minvalue(x,y) << endl; 
    
    return 0; 
}
