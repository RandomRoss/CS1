#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int numstart = 0; 
    int numend = 0; 
    int numstep = 0;
    int sumodd = 0;
    int sumeven = 0;
    int sumall = 0; 
    int average1 = 0 ;
    int i = 1;
    int t = 0; 
    int c = 0;
    
    while (i == 1){
    cout << "Start Number: ";
    cin >> numstart;
    cout << endl ;
    
    cout << "Ending Number: ";
    cin >> numend;
    cout << endl; 
    
    cout << "Steps: ";
    cin >> numstep;
    cout << endl;
    
    if ((numend >= numstart) && (numstep >= 1)){
        i = 10;
    }
    else{
        i = i;
    }
    }

for (t = numstart;t <= numend;t+=numstep){
    if (t % 2 == 0){
        
        sumeven = sumeven + t;
        sumall = sumall + t; 
        c = c + 1; 
        
    }
    else{
        
        sumodd = sumodd + t;
        sumall = sumall + t; 
        c = c + 1; 
        
    
    }
}

    average1 = sumall/c; 
    cout << "ODD Number Sum: " << sumodd; 
    cout << endl; 
    cout << "EVEN Number Sum: " << sumeven;
    cout << endl;
    cout << "Sum of ALL Numbers: " << sumall;
    cout << endl;
    cout << "Average: " << average1;
    cout << endl;
    
    return 0;

}
