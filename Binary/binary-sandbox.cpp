#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>
//including .h file of binary
#include "binary.h"

int main(){
//declaring variables for the class Binary
Binary bin1("100");
Binary bin2("10");
Binary bin3 = bin1 + bin2;
Binary bin4;
//Getting the Binary Numbers from the user
cout << "Please Enter binary number:";
cin >> bin4;
//multiplying b4 by b3
Binary bin5 = bin4 * bin3;
Binary bin6 = bin2 / bin1;
Binary bin7 = bin5 - bin3;
//coutiing the addition, subtraction, multiplacation, an division 
cout << "addition:" << bin3 << endl;
cout << "subtraction:" << bin7 << endl;
cout << "multiplication:" << bin5 << endl;
cout << "division:" << bin6 << endl;

return 0;

}
