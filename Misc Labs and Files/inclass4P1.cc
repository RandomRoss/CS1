#include <iostream>
#include <cmath>
using namespace std;
// declaring global variables 
int functionP1(int arrayName[], int arrayLength, int search_term){
    //counter
    int k = 0;
    if (arrayLength == 0){
        return 0;
    }
        for(int g = 0;g < arrayLength; g++){
        if(arrayName[g] == search_term){
            k = k + 1;
        }
        
    } 
    return k;
}
int main(){
const int arrayLength = 6;
int arrayName[arrayLength] = {4,4,4,4,3};
int search_term = 4;
//int k = 0;
functionP1(arrayName,arrayLength,search_term);
cout << functionP1(arrayName,arrayLength,search_term) << endl;
    return 0; 
}
