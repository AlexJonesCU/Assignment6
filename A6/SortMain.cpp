#include <iostream>
#include <string>
#include "Sort.h"
#include <ctime> //source: https://en.cppreference.com/w/cpp/chrono/c/time

int main(int argc, char ** argv)
{
  Sort one;


  cout << "Start Time: ";
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result))
            << result << " seconds since the Epoch\n";

  one.ReadLines();


}
