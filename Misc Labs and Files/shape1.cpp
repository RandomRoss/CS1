#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Cuboid{
public: 
    void setlg(double lg){
        length = lg;
    }
    void setwd(double wd){
        width = wd; 
    }
    void setht(double ht){
        height = ht;
    }
    void display(){
        cout << "The Volume for the Cuboid is:" << volume() << endl; 
        cout << "The Surface Area for the Cuboid is:" << surface() << endl; 
    }
    double getW () const{return width;}
    double getH () const{return height;}
    double getL () const{return length;}
private:
    double length;
    double width;
    double height; 
    double volume ()const {return length * width * height;}
    double surface () const {return 2*length*width+width*height+height*length;}
};
int main(){
    Cuboid lwh;
    
    lwh.setlg(2); //setting the length 
    lwh.setwd(2); // setting the width 
    lwh.setht(2); // setting the ht 
    
    lwh.display();
    
    lwh.setlg(14); //setting the length 
    lwh.setwd(2); // setting the width 
    lwh.setht(11); // setting the ht 
    
    lwh.display();
    
    lwh.setlg(100); //setting the length 
    lwh.setwd(12); // setting the width 
    lwh.setht(11); // setting the ht 
    
    lwh.display();


return 0; 
}
