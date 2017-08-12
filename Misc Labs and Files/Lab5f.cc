#include <iostream>
#include <cmath>
using namespace std;
// fills array with random values 
void functionA(float arrayName[], int arrayLength){
    for(int i = 0;i < arrayLength; i++){
        arrayName[i] = rand() % 1000; 
    } 

}
// displays array 
void functionB(float arrayName[],int arrayLength){
    for(int i = 0; i < arrayLength; i++ ){
        cout << arrayName[i];
        cout << " ";
    }
    cout << endl;
}
// sums all values stored in the arrays
int functionC(float arrayName[],int arrayLength){
    int arraysum = 0;
    for(int i = 0; i < arrayLength; i++){
     arraysum = arraysum + arrayName[i]; 
    }
    return arraysum;
}
int main(){
int arrayLength = 4;
float arrayName[arrayLength];
functionA(arrayName,arrayLength);
//cout << arrayName[0];
functionB(arrayName,arrayLength);
cout << functionC(arrayName,arrayLength);
return 0;
}
