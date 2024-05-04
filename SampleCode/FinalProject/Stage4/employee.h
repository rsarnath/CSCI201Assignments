#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <string>
#include <iomanip> 
#ifndef EMPLOYEE
#define EMPLOYEE 
using namespace std;  


class employee{

 public:
  
  const static int nameLength = 20;   
  const static int idLength = 9; // 8-character Id  
  
 private:
  char name[nameLength];  
  string id;  
  int deductions;  
  float hrlyWage;  
  float Salary;  
  float withholding, netSalary, hrsWorked[5];  
 
  void computeSalary( float hours)  
    {  
      Salary = hrlyWage*hours;  
    }  
  
  void computeWithholding()  
    {  
    
      // code to compute withholding applying tax rules.  
      withholding = Salary*deductions/10;
     }  
   
  
  
 public:
  
       
    
  void setName(char n[])
    {
      strcpy(name, n);
    }
  
  void setId(string nId)
    {
      id = nId;
    }
  
  void setHours(float hours[])
    {
      // hours should be an array of 5
      for (int i = 0; i < 5; i++)
	hrsWorked[i] = hours[i];
    }
	  

  void setWage( float wage)
    {
      hrlyWage = wage;
    }
  
  void setDeductions(int deducts)
    {
      deductions = deducts;
    }

  string getId()
    {
      return id;
    }
  
  float getWage()
    {
      return hrlyWage;
    }

  char* getName()
    {
  return name;
    }

  void processEmployee()  
    {  
      
      float hours;  
      
      hours =  hrsWorked[0] + hrsWorked[1] +  
	hrsWorked[2]+ hrsWorked[3]+ hrsWorked[4];  
      computeSalary(hours);  
      computeWithholding();  
      netSalary = Salary-withholding;  
    }  


  void printPersonalInfo(ostream& outfile)  
    {  
      // prints a multi-line report 
      // listing all the fixed personal information  
      
      outfile <<  "Name:   "<<  name << endl  
	      <<  "Id:   "<<  id << endl   
	      << "Hourly Wage:  " << hrlyWage << endl  
	      << "Deductions:   " << deductions << endl  
	      <<"-------------------------------------------------"<<endl 
	      << endl;  
    }  
  
  
  
  void printRecord( ostream& outfile)  
    {  
      // prints on one line with uniform field widths  
      // describing the week's paycheque  
      
      outfile << setw(nameLength+2)<<  name   
	      <<  setw(idLength+2) <<  id   
	      << setw(10) << Salary   
	      << setw(10) << withholding  
	      << setw(10) << netSalary  << endl;   
    }  
  
  void writeEmployee(  ostream& outfile)  
    {
      // saves the raw data to the specified stream
      
      char space = ' ';
      outfile << name << space << id << space
	      <<hrsWorked[0] << space << hrsWorked[1] << space  
	      <<hrsWorked[2] << space << hrsWorked[3] << space 
	      <<hrsWorked[4] << space << hrlyWage << space
	      <<deductions << endl; 
    } 

  void printReport( ostream& outfile)   {     // prints a multi-line report for employee specified by index     // describing the week's paycheque
     outfile <<  "Name:   "<<  name << endl	     <<  "Id:   "<<  id << endl 	     << "Salary:  " << Salary << endl	     << "Withholding:   " << withholding << endl	     << "Net Pay:   " << netSalary  << endl 	     <<"-------------------------------------------------"<<endl;   }
  
};
#endif
