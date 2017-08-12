#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Difficulty {
    public: 
        string ansStr;
        double accuracy;
        string usrStr;
    private:
        int STRING_SIZE;
        int numCorrect;
        double percentCorrect;
};
   
bool strCmp(string usrStr, string ansStr, double accuracy){
    int STRING_SIZE = usrStr.size();
    int numCorrect = 0;
    for (int i = 0; i < STRING_SIZE; ++i){
        if (usrStr[i] == ansStr[i]){
        ++numCorrect;
        }
    }

    double percentCorrect = (static_cast<double>(numCorrect)/STRING_SIZE) * 100;

    cout << "% = " << percentCorrect << endl;
    cout << "# correct: " << numCorrect << endl;   // TAKE THIS OUT AFTER IMPLEMENTATION 
    cout << "Size: " << STRING_SIZE << endl;

    if (percentCorrect >= accuracy)
        return true;
    else
        return false;
}

/*
int main(){
    string ansStr = "This is the answer string";
    string usrStr;
    double accuracy = 0;

    cout << "Enter a string: ";
    getline(cin, usrStr);
    cout << "Enter accuracy: ";
    cin >> accuracy;

    cout << strCmp(usrStr, ansStr, accuracy) << endl;
    
    return 0;
}
*/
