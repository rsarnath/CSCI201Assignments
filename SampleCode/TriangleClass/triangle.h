// This file is not compiled
#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#ifndef TRIANGLE
#define TRIANGLE
// triangle.h

class triangle {
 private:

  
  int height;
  char ch;
  int topmargin;
  int leftmargin;
  static void printChars(int, char, ostream&);//used to draw
  

 public: 

  // constructor
  triangle(int h = 0, char c = '*' ,int t = 0, int l = 0)
    {
      height =h; ch = c; topmargin=t; leftmargin=l;
    }
  
 // modifier methods
  void setheight(int h) {height=h;}
  
  void settopmargin(int t) {topmargin=t;}
  
  void setleftmargin(int l) {leftmargin=l;}


  void draw(ostream&);// draws the triangle with specified character

  // Triangle is stored as (<height> <drawing character> < topmargin> <leftmargin>)
  void  read(istream&); // reads the triangle data
  void  write(ostream&); // writes the triangle data

};
#endif

