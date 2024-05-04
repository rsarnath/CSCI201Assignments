//This is the application program. Compile at the
// very end with the command "g++ angletest.cpp angle.o"


#include <iostream>  
#include "angle.h"
#include <fstream>
#include <cstring>

using namespace std;


void sum_and_diff (int x, int y, int &s, int &d)
{
  //using refernce parameters, as usual
   cout << "x at: " << &x << endl;
  cout << "y at: " << &y << endl;
  cout << "s at: " << &s << endl;
  cout << "d at: " << &d << endl;
  s = x+y; d = x-y;
}

void sum_and_diff2 (int x1, int y1, int *s, int *d)
{
  // s and d are int pointers
  cout << "x1 at: " << &x1 << endl;
  cout << "y1 at: " << &y1 << endl;
  cout << "s at: " << &s << endl;
  cout << "d at: " << &d << endl;
  cout << "s is: " << s << endl;
  cout << "d is: " << d << endl;
  *s = x1+y1; *d = x1-y1;
}

int main()
{

  // Working with pointer parameters

  int i=3, j, sum, diff;
  cout << "i at: " << &i << endl;
  cout << "j at: " << &j << endl;
  cout << "sum at: " << &sum << endl;
  cout << "diff at: " << &diff << endl;
  
  cout << "Please input two numbers: ";
  cin >> i >> j; 
  sum_and_diff(i, j, sum, diff); //usual call 
  cout << " sum is " << sum << " diff is " << diff << endl;

  cout << "Please input two numbers: "; 
  cin >> i >> j; 
  sum_and_diff2(i, j, &sum, &diff); // pass addresses in call
  cout << " sum is " << sum << " diff is " << diff << endl;
  
}

