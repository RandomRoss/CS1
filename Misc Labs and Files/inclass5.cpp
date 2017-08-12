#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
      int summed1 = 0;
    vector <int> count1(int min,int max, int count){
        vector<int> rand1(max - min + 1);
        int random1; 
        srand(time(NULL));
        for (int k = 0; k < count; k++ ){
            random1 = rand() % (max - min + 1);
            ++rand1.at(random1);
        }
        return rand1;
    }

int main() {
    int min = 0; 
    int max = 50;
    int count = 100000;

    vector<int> count2 = count1(min,max,count);
    // number of times it appears 
    for(int k = 0; k < count2.size();k++){
        cout << k << " appears " << count2.at(k) << " Times" << endl;
    }
    int minval = count2.at(0);
    int maxval = count2.at(0);
    int minnum;
    int maxnum;
    for (int k = 0; k < count2.size();k++){
        if  (count2.at(k) < minval){
            minval = count2.at(k); 
            minnum = k; 
        }
        if (count2.at(k) > maxval){
            maxval = count2.at(k);
            maxnum = k;
        }
    }
    for(int k = 0; k < count2.size();k++){
        summed1 += count2.at(k);
    }
    cout << endl;
    cout << "Max value is:" << maxval << " and is for number " << maxnum <<endl;
    cout << "Min value is:" << minval << " and is for number " << minnum <<endl;
    cout << "Summed all equals " << summed1 << endl; 
    
    return 0;
}
