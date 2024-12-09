#include <iostream>
#include "f.h"
int main()
{
   f();
   std::cout << std::endl << std::endl << "standard  " << __cplusplus << "Compiled at " << __DATE__ << " " << __TIME__ << std::endl;
   std::cout << "File # " << __FILE__ <<  "Line # " << __LINE__ << std::endl;
   return 0;
}