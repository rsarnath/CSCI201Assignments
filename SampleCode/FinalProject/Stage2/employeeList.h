// This is the header file.
// Do not attempt to compile it.

#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#include <iomanip>
#include "employee.h"
#ifndef EMPLOYEELIST
#define EMPLOYEELIST

// employeeList.h

/*------------------------------------------------------------------------
data structures (arrays, variables and constants) to store the information
-------------------------------------------------------------------------*/
class employeeList 
{

private:
 unsigned int maxSize; 
 int  nameLength, idLength; 
vector<employee> empList;


public: 
//constructor
{
}
bool addEmployee(employee ); 
void writeData(ostream& outfile);
};

#endif