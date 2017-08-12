#include <iostream>
#include <string> 
#include <vector>
#include <cctype>
using namespace std; 
//finding the max value inside of a vector 
int maxInt(vector <int> maxValue){
    int maximum = maxValue.at(0);
    for (int k = 0; k < maxValue.size();k++){
        if (maxValue.at(k)>maximum){
            maximum=maxValue.at(k);
        }
    }
    return maximum;
}
//finding the minimum value inside of a vector
int minInt(vector <int> minValue){
    int minimum = minValue.at(0);
    for (int k = 0; k < minValue.size();k++){
        if (minValue.at(k)<minimum){
            minimum=minValue.at(k);
        }
    }
    return minimum;
}
//returns true or false if vector cantains 2 of the same values 
bool containsDups (vector <int> dups){
    for (int k=0; k < dups.size();k++){
        for(int i=k+1; i<dups.size();i++){
            if (dups.at(i)== dups.at(i)){
                return true;
            }
        }
    }
    return false; 
}
// creating the histogram couts or displays the histograph
void Histogram(vector<int> Vector1){
    vector <int> histograms; 
    double star= maxInt(Vector1) / 80.0; 
    for (int k = 0; k < Vector1.size(); k++){
        histograms.push_back(Vector1.at(k)/star);
    }
     cout<<"Value"<<""<<"-"<<endl;
     
    for (int k = 0; k < histograms.size(); k++){
        cout<<Vector1.at(k)<<"-";
        for(int i=0; i <histograms.at(k);i++){
            
            cout<<'*';
        }
        cout<<endl;
    }
}
//returning true or false if the histograph is not sorted 
bool isSorted(vector<int> sort){
    for (int k = 0; k <sort.size();k++){
        int valuestored;
        if (sort.at(k)<valuestored){
            return false;
        }
         valuestored = sort.at(k);
    }
   
   return true;
}
int main (){
    int maximum;
    int minimum;
    bool Dups;
    vector<int> Vector1(3);
    Vector1.at (0)= 200;
    Vector1.at (1)= 2000;
    Vector1.at (2)= 10000;
    bool sorted = isSorted(Vector1);
    if (sorted == 1){
        cout << "This is sorted" <<endl;
    }
    else{
        cout << "This is not sorted" << endl;
    }
    maximum = maxInt(Vector1);
    minimum = minInt(Vector1);
    //checks for duplicates 
    Dups =  containsDups(Vector1);
    if (Dups == 0){
        cout <<"contains Duplicates" << endl;
    }
    else{
        cout <<"Does not contain Duplicates" << endl;
    }
    //calling to histogram function to display histograph
    Histogram(Vector1);
    
    return 0; 
}
