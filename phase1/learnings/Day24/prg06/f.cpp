#include<iostream>
#include"f.h"
void f() {
   std::cout << "standard  " << __cplusplus << "Compiled at " << __DATE__ << " " << __TIME__ << std::endl;
   std::cout << "File # " << __FILE__ <<  "Line # " << __LINE__ << std::endl;
}