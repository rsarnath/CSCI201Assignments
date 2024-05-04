// A payroll template C++ program  
  
#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <iomanip>  
#include "employeeList.h"
using namespace std;  
  
  

  
const int maxSize = 20; //at most 20 employees  
const int nameLength = employee::nameLength;   
const int idLength = employee::idLength; // 8-character Id  
  
 
  


  
  

  


employeeList empList(maxSize);  // define the employeeList object.
// some more variables used only main  
ofstream outfile;  
ifstream infile;    
char input_file_name[21], output_file_name[21], name[nameLength+1], id[idLength+1];  
  

/*------------------------------------------------------------------------  
  Functions used by main program and the user interface  
  ------------------------------------------------------------------------*/  


void showmenu()  
{  
  cout<< "Please type in  one of the following options: \n";  
  cout<< "L or l  to load the employee list \n";  
  cout<< "D or d  to display  the employee data \n";  
  cout<< "P or p to process payroll\n";  
  cout<< "C or c to change an employee's wage \n";  
  cout<< "A or a to add a new employee \n";  
  cout<< "S or s to search for a particular employee's information \n";  
  cout<< "R or r to print the payroll results \n";  
  cout<< "M or m to display this menu \n";  
  cout<< "E or e to save and exit \n";  
}  

void loadEmployees()  
{  
  employee e_temp;  float hrsWorked[10];
  int deductions; float hrlyWage; 
  int i; bool done;
  cout << "Please enter name of the  data file:  ";  
  cin >> input_file_name;  
  infile.open(input_file_name);  
  if ( !infile)  
    {  
      // abandons operation with error mesg  
      cout << "Could not open input file \n";  
      infile.close();  
      infile.clear();  
      return;  
    }  
  infile >> name; e_temp.setName(name);
  while(!infile.eof())  
    {  
      infile >> id; e_temp.setId(id); 
      i = 0; done = false;
      // reads numbers for hours worked until it sees a '|' character
      while (not done)
      { 
        infile >> hrsWorked[i];
        if (infile)
        {
           i++;
        }
        else
        {
          infile.clear();
          infile.ignore(10, '|');
          done = true;
        }
      }
      e_temp.setHours(hrsWorked, i);
      infile >> hrlyWage; e_temp.setWage(hrlyWage);   
      infile >> deductions; e_temp.setDeducts(deductions);  
      empList.addEmployee(e_temp);
      infile >> name; e_temp.setName(name);
    }  

  infile.close();  
  infile.clear();  
}   

  
void displayData()
{
  empList.writeData(cout);
}

void processThePayroll()  
{  
   // No further input is needed from the user.
  // Simply call function that processes the list.

  empList.processPayroll();

}  
  
  
void changeWages()  
{  
  
  cout << "Changing employee wage\n";  
}  
  
void addNewEmployee()  
{  
  cout << "Adding employee \n";  
}  
  
  
void searchAnEmployee()  
{  
  cout << "Searching employee \n";      
}  
  
void printPayroll()  
{  
  int i;
  cout << "Please enter name of output  file:  ";
  cin >> output_file_name;
  outfile.open(output_file_name);
  cout << "Please enter 1 to print tabular and 2 to print report: ";
  cin >> i;
  if(i == 1)
    empList.printTable(outfile);
  else 
    empList.printReport(outfile);
  outfile.close();
  outfile.clear();
}  
  
void saveInfo()  
{  
  cout << "Saving data";  
}  
  
  
/* ---------------------- start of Main Program -----------------------------*/  
  
  
int main()  
{  
  
  char choice;  
    
  showmenu();  
  cout << "Please indicate your choice of operation (m for menu): ";  
  cin >> choice;  
  
  while ((choice != 'e')&& (choice != 'E'))  
    {  
      switch(choice)  
	{  
	case 'l':  
	case 'L': loadEmployees(); break;  
        case 'd':
	case 'D': displayData(); break;
	case 'p':  
	case 'P': processThePayroll();break;  
	case 'c':  
	case 'C': changeWages();break;  
	case 'a':  
	case 'A': addNewEmployee();break;  
	case 's':  
	case 'S': searchAnEmployee();break;  
	case 'r':  
	case 'R': printPayroll();break;  
	case 'm':  
	case 'M': showmenu();break;  
	default : cout << "Not a valid choice" << endl;  
	}  
      cin.ignore(200, '\n'); cin.clear(); //clear out all input  
      cout << "Please indicate your choice of operation (m for menu): ";  
      cin >> choice;  
    }  
  saveInfo();  
  cout << "Thank-you, good bye! \n";  
}  
  
