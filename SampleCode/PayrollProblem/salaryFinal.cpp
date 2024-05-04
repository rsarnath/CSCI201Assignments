// A payroll program. This is the final step.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


float computeHours(istream& infile)
{
  int hours; float total=0;
  bool error= false;

  for(int i=1; i <= 5; i++)
    {
      infile >> hours; 

      //error check: hours should be between 0 and 16
      // for each day of the week. Return -1.0 otherwise.
      if ((hours < 0) || (hours > 16))
         error = true;

      total += hours;
    }
  if (error) 
    return -1;
  return total;
}

float computeSalary(float hours, istream& infile)
{
  float wage, total_salary;
  infile >> wage;
  total_salary = wage*hours;
  return total_salary;
}  

float computeWithholding(float salary, istream& infile)
{
  float percent, deductAmt; int deductions;
  infile >> deductions;
  percent = 5*(6-deductions)/100.0; // compute percentage withholding
  deductAmt = salary *percent; 
  return deductAmt;
}


float computeNetSalary(float salary, float withholding)
{
  return (salary-withholding);
}

void printRecord (string name,  string Id, float hours, float salary, 
		  float withholding, float netSalary, ostream& outfile)
{
  outfile <<  "Name:   "<<  name << endl
	  <<  "Id:   "<<  Id << endl
          << " Hours  " << hours << endl
	  << "Salary:  " << salary << endl
	  << "Withholding:   " << withholding << endl
	  << "Net Pay:   " << netSalary  << endl 
	  <<"-------------------------------------------------"<<endl<< endl;
}

int main()
{
  ofstream outfile;
  ifstream infile; 


  string file_name, name, Id, payrollRecord;

  float  hoursWorked = 0, salary=0, withholding=0, netSalary=0;


  cout << "Please enter name of input file:  ";
  cin >> file_name;
  infile.open(file_name.c_str());
  if ( !infile)
    {
      // abandons operation with error mesg
      cout << "Could not open input file \n";
      return 0;
    }


  outfile.open("PayrollResult");
  if ( !outfile)
    {
      cout << "Could not open output file \n";
      return 0;
    }

  
  infile >> name; 
  while(!infile.eof())
    {
      infile >> Id;
      hoursWorked = computeHours(infile); /*Read daily hours 
					  and compute  hoursWorked*/
      salary = computeSalary(hoursWorked, infile); /* Read hourly wage and 
						      compute salary */
      withholding = computeWithholding(salary, infile); /*Read deductions and
							  compute withholding*/
      netSalary = computeNetSalary(salary, withholding);/* Compute netSalary
							   from salary and
							   withholding*/
      printRecord (name, Id, hoursWorked, salary, withholding, 
		   netSalary, outfile);
      infile >> name; //try to read another name
    }
  infile.close();
  outfile.close();
  return 0;
}
