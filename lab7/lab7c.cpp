#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
// coordinate pairs 
struct coordpair {
    double x1;
    double y1;
    double x2;
    double y2;
};
double width(double x1, double x2){
    double widthcalc;
    if (x1 <= x2){
        widthcalc = x2 - x1;
    } 
    else{
        widthcalc = x1 - x2;
    }
    return widthcalc;
}
 double height(double y1, double y2){
    double heightcalc;
    if (y1 <= y2){
        heightcalc = y2 - y1;
    } 
    else{
        heightcalc = y1 - y2;
    }
    return heightcalc;
}
double area(double height1, double width1){
    double area1 = height1 * width1;
    
    return area1;
}
double slp1(double x1,double y1,double x2,double y2){

   double slopes =  (y2-y1)/(x2-x1);
 
 return slopes;  
}
 double yintercept(double x1,double y1,double slope1){
  double calulation1 = slope1 * x1;
  calulation1 = y1 - calulation1;
  
  return calulation1;
 }
//converting to radians from degrees 
double PI = 3.1415926359;
double degreesToRadians(double degrees){
    if(degrees == 360 || degrees == 720){
        degrees = 0;
    }
    // while loop to make between 0 and 360 
  while(degrees > 360){
      degrees = degrees - 360;
  }
double radians =(PI/180)*degrees;
//returning degrees 
return radians;
}
int main(){
    double degrees;
    cout << "enter degrees:";
    cin >> degrees;
    double answer = degreesToRadians(degrees);
    cout <<degrees << "To radians is " <<  answer << endl;
    
        coordpair xyvals;
    cout <<"Enter The first x coordinate:";
    cin >> xyvals.x1;
    cout <<"Enter The first y coordinate:";
    cin >> xyvals.y1;
    cout <<"Enter The last x coordinate:";
    cin >> xyvals.x2;
    cout <<"Enter The last y coordinate:"; 
    cin >> xyvals.y2;
    double slope1 = slp1(xyvals.x1,xyvals.y1,xyvals.x2,xyvals.y2);
    cout <<"The slope is:" <<slope1 << endl;
    double yint = yintercept(xyvals.x1,xyvals.y1,slope1);
    cout <<"The b value or y-intercept is:" << yint << endl;
    
        double findwidth = width(xyvals.x1,xyvals.x2);
    cout << "The Width is:" << findwidth <<endl;
    double findheight = height(xyvals.y1,xyvals.y2);
    cout << "The Height is:" << findheight << endl; 
    double calcarea = area(findheight,findwidth);
    cout << "The area is:" << calcarea << endl; 
    
    return 0; 
}
