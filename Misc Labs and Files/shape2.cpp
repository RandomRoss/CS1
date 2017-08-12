#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
//creating a class
class Cuboid{
public: 
    void setlg(double lg){ // setting length 
        length = lg;
    }
    void setwd(double wd){ // setting width 
        width = wd; 
    }
    void setht(double ht){ // setting height 
        height = ht;
    }
    void display(){
        cout << "The Volume for the Cube is:" << volume() << endl; //displaying the volume 
        cout << "The Surface Area for the Cube is:" << surface() << endl; //displaying the surface area 
    }
    double getW () const{return width;}
    double getH () const{return height;}
    double getL () const{return length;}
private:
    double length;
    double width;
    double height; 
    double volume ()const {return length * length * length;}
    double surface () const {return 6*(length*length);}
};
int main(){
    Cuboid lwh;
    
    lwh.setlg(2); //setting the length 
  
    
    lwh.display();
    
    lwh.setlg(14); //setting the length 

    
    lwh.display();
    
    lwh.setlg(100); //setting the length 

    
    lwh.display();


return 0; 
}
