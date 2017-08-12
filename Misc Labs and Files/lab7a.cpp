#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
//Part A of Lab 7 
//function one which character 
int countChars(string input, char which_char){
    int count1 = 0; 
    for(int i = 0; i < input.length();i++){
        if(input.at(i) == which_char){
        count1++;
        }
    }
    return count1;
}

//function two uppercase characters 
int upperCaseChars(string input){
    int count2 = 0;
    for(int i = 0; i < input.length();i++){
        if(isupper(input.at(i))){
        count2++;
        }
    }
    return count2;
}

//function three lowercase characters 
int lowerCaseChars(string input){
    int count3 = 0;
    for(int i = 0; i < input.length();i++){
        if(islower(input.at(i))){
        count3++;
        }
    }
    return count3;
}
//function four number of punctuations within the string
int numPunct(string input){
    int count4 = 0;
    for(int i = 0; i < input.length();i++){
        if(ispunct(input.at(i))){
        count4++;
        }
    }
    return count4;
}
//function five converting string to uppercase
string StringToupper(string input){
    string input1 = input;
        for(int i = 0; i < input.length();i++){
            input1[i] = toupper(input[i]);
        }
        return input1;
    }
//function six converting string to lowercase
string StringTolower(string input){
    string input2 = input; 
        for(int i = 0; i < input.length();i++){
            input2[i] = tolower(input[i]);
        }
        return input2;
    }
//function seven counting the number of character in a string
vector<int> characterCounts(string input){
    vector <int> alphabet(26);
    input = StringTolower(input);
     for(int i = 0; i < alphabet.size();i++){
         for(int k = 0; k < input.size();k++){
            if(input.at(k) == 'a'+ i ){
                alphabet.at(i)++;
            }
         }
     }
    return alphabet;
}
// function eight finding the number of lines 
int numLines(string input){
    int count5 = 1;
    for(int i = 0; i < input.length()-1;i++){
        if(input.at(i) == '\n')  {
           count5++;
        }
    }
    return count5;
}

// function nine finding the number of words inside of a string
int numWords(string input){
    int count6 = 0;
    if(isalpha(input.at(0))) {
        count6 = 1;
    }
    for(int i = 0; i < input.length()-1;i++){
        if(!isalpha (input.at(i)) && isalpha (input.at(i + 1))){
            count6++;
        }
    }
    //cout <<"counter6 =                          "<< count6 <<endl;
    return count6;
}

int main(){
    string input1;
    string input2;
    string input;
    char which_char;
    //inputting string 
    cout << "Input String:";
    cin >> input;
    //inputting char to count  
    cout <<"Char to count:";
    cin >> which_char;
    //outputting the count of char
    int c = countChars(input, which_char);
    cout << "count:" << c << endl;
    int d = upperCaseChars(input);
    cout << "Number of upper cases:" << d << endl;
    int e = lowerCaseChars(input);
    cout << "Number of lower Cases:" << e << endl;
    int f = numPunct(input);
    cout <<"Number of Punctuations:" << f << endl;
    input1 = StringToupper(input);
    cout <<"String to Upper case:" << endl <<  input1 << endl;
    input2 = StringTolower(input);
    cout <<"String to lower case:" << endl <<  input2 << endl; 
    vector <int> alphabet = characterCounts(input);
    char letter1;
    for(int i = 0; i < alphabet.size();i++){
        letter1 = 'a'+i;
        cout << letter1 <<" Apprears " << alphabet.at(i) << endl;
    }
    int g = numLines(input);
    cout <<"The Number of lines are:"<<  g << endl;
    int numofwords =  numWords(input);
    cout << "Number of Words in string is:" << numofwords << endl;
    
    return 0;
}
