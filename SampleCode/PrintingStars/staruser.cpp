#include "starprinter.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
// compile with g++ staruser.cpp starprinter.o


int main()
{ 
   starprinter star1, star2;
   int num;
   
   cout << "Please enter number of stars:" << endl;
   cin >> num;
   star1.printstars(num);
   star2.printstars(2*num);
    
   return 0;
}