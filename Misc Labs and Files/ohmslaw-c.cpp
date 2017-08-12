#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// variables being declared 
vector <double> resistance1;
int resistance; 
double volt = 0;
int  resistornum;
int counter = 1;
int i = 0;
int newresistance;
int k = 1;
int totalresistance;
int choice;

//calculating voltage or volatge drop in node
double voltagedrop(double cur, double resist){
    double voltagedroped = cur * resist;
    
    return voltagedroped;
}
// calculating power in node 
double powernode(double volts1,double current){
    double powerinnode = volts1 * current; 
    
    return powerinnode;
}
// displaying and calculating values for node # 
void displays(double x,double resistance1, int node){
   double  voltagedropcalc = voltagedrop(x,resistance1);
    double powernode1 = powernode(voltagedropcalc,x);
    cout << endl;
    cout <<	"Node " << node << " Parameters:" << endl; 
    cout << "Resistance:" << resistance1 << " ohms" << endl;
	cout << "Voltage:" << voltagedropcalc << " volts" << endl;
	cout << "Power:" << powernode1 << " Watts" << endl;

}

int main(){
        cout << "Enter the voltage:";
    cin >> volt;
    double newresistance;
    int i = 0; 
    int k = 1;
    //entering in resistor values
    while(k == 1){
        cout << "Enter Resistance for resistor #" << i + 1 <<"(0 to exit):";
        cin >> newresistance;
            if (newresistance == 0){
            k = 0;
            }
            else{
                resistance1.push_back(newresistance);
            }
        i++;
    }
    do {
        //prompting user
        int choice;
    cout << "Enter a '1' to Add a single resistor" << endl; 
    cout << "Enter a '2' to Change Input voltage" << endl;
    cout << "Enter a '3' to Delete resistor" << endl;
    cout << "Enter a '4' to Edit resistor" << endl;
    cout << "Enter a '5' to Group add a series of resistors" << endl;
    cout << "Enter a '6' to Display network" << endl;
    cout << "Enter a '7' to Quit program" << endl; 
    cout << "Enter a Value:";
    cin >> choice;
switch (choice){
    case 1: {
    //adding a single resistor 
        cout << "What is the resistance for resistor #" << i + 1 <<":"; 
        cin >> resistance;
            resistance1.push_back(resistance);
            i++;
     }break;
     
     case 2:{ 
     // input voltage 
        cout << "What is the Input voltage:";
        cin >> volt;
    }break;
    
     case 3:{ 
     // delete resistor 
        cout << "What Resistor would you like to delete:";
        cin >> resistornum;
        resistance1.erase(resistance1.begin()+(resistornum - 1)); 
    }break;
    
     case 4:{ 
     //editing resistor 
        cout << "What Resistor would you like to Edit:";
        cin >> resistornum;
        cout << "What is the new value of resistor " << resistornum << ":"; 
        cin >> resistance;
        resistance1.at(resistornum - 1) = resistance;
    }break;
    
     case 5:{
     // adding resistors 
     k = 1;
            while(k == 1){
        cout << "Enter Resistance for resistor #" << i + 1 <<"(0 to exit):";
        cin >> newresistance;
            if (newresistance == 0){
             k = 0;
            }
            else{
                resistance1.push_back(newresistance);
            }
        i++;
    }
     }break;
     
      case 6:{
      //displaying network
      totalresistance = 0;
          for(int c = 0; c < resistance1.size(); c++){
        totalresistance += resistance1.at(c);
    }
    double current1 = volt / totalresistance;
    double powercalc1 = volt * current1;
    cout << endl; 
    cout << "Circuit Parameters:" << endl;
	cout << "Total Resistance:" << totalresistance <<" ohms" <<endl;
	cout << "Input Voltage:" << volt <<" volts" << endl;
	cout << "Series Current:" << current1 <<" Amp" <<endl;
	cout << "Total Power:" << powercalc1 <<" Watts" << endl;

    for(int k = 0; k < resistance1.size(); ++k){
        displays(current1,resistance1.at(k),k);
    }
    }break;
    
    case 7:{
    counter = 2;
    }break;
}
    
    }while(counter == 1);

return 0;
}
