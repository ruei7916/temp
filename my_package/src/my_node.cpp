#include <cstdio>
#include "serial.h"
#include <iostream>
#include <string>


int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;
  int a;
  printf("hello world my_package package\n");
  serial::Serial my_serial("/dev/ttyACM0", 115200, serial::Timeout::simpleTimeout(1000));
  if(my_serial.isOpen())
    std::cout << " Yes." << std::endl;
  else
    std::cout << " No." << std::endl;
  while(1){
        scanf("%d",&a);
        my_serial.write(std::to_string(a));
        std::string result = my_serial.read(1);
        std::cout<<result;
    }
  
  return 0;
}
