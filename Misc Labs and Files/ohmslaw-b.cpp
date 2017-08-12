#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// variables being declared 
vector <double> resistance1;
double volt;
int totalresistance;

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
    // prompting user for voltage
    double volt; 
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
	
// for loop to dislay voltage drop along each node
    for(int k = 0; k < resistance1.size(); ++k){
        displays(current1,resistance1.at(k),k);
    }

return 0;
}
