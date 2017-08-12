#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

string ransomLetter(string userstring){
    //for loop to change to the string and make a ransom letter
    for (int i=0; i < userstring.size() ; i++){
        int random = rand()%2;
     if(userstring.at(i)=='i' || userstring.at(i)=='I'){
         userstring.at(i) = '1';
     }   
     else if(userstring.at(i)=='e' || userstring.at(i)=='E'){
         userstring.at(i) = '3';  
     }
     else if(userstring.at(i)=='s' || userstring.at(i)=='S'){
         userstring.at(i) = '$';
     }
     else if(userstring.at(i)=='o' || userstring.at(i)=='O'){
         userstring.at(i) = '@';
     }
     //checking if alphabet and if it is then has a 50/50 chance of switching to the letter from uppercase to lowercase or the other way around 
     else if(isalpha(userstring.at(i))){
       if(random == 1){
           if(isupper (userstring.at(i))){
               userstring.at(i) = tolower(userstring.at(i));
           }
           else if(islower(userstring.at(i))){
               userstring.at(i) = toupper(userstring.at(i));  
           }
       }  
     }
    }

    return userstring;
}

int main(){
    string userinput; 
    cout << "Enter a String:";
    cin >> userinput;
//calling to the ransom function 
    string ransom = ransomLetter(userinput);
    cout << ransom << endl; 
    
    return 0;
}
