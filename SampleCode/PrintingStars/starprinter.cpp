 // compile with "g++ -c starprinter.cpp"

// i.e., compile without linking. This will

// create an executable file starprinter.o



#include <cstdlib>
#include <string>

#include "starprinter.h"
// Program  prints stars


void starprinter::printstars(int num)
{ 
   int count = 0;
   while (count < num)
   {
      cout << '*'; count++;
   }
   cout << endl;
}
