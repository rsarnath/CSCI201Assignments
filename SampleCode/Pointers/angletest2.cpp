//This is the application program. Compile at the
// very end with the command "g++ angletest.cpp angle.o"

#include "angle.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
  int t; char c[11];
  int x; float x1[5]; int y; int *xp, *yp;
  int p; angle a1(20,20,20), a2(20,20,20);
  int &z = x;

  cout << "t at: " << &t << endl;
  cout << "c at: " << &c << endl;
  cout << "x at: " << &x << endl;
  cout << "x1 at: " << &x1 << endl;
  cout << "y at: " << &y << endl;
  cout << "z at: " << &z << endl;
  xp = &x; yp = &y;
  cout << "xp  at: " << &xp << endl;
  cout << "yp at: " << &yp << endl;
  cout << "xp  is: " << xp << endl;
  cout << "yp is: " << yp << endl;
  cout << "p at: " << &p << endl;
  cout << "a1 at: " << &a1 << endl;
  cout << "a2 at: " << &a2 << endl;

  strcpy(c, "abcdefghi");
  cout << "c is  " <<  c << endl;
  //c[10] = ' ';c[9] = ' ';c[11] = ' ';c[12] ='?';
  //cout << "c is: " << c << endl;
  

}

