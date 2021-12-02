#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream file;
  file.open("input2");
  long horizontal = 0;
  long vertical = 0;
  while(!file.eof())
  {
    std::string action;
    int value;
    file >> action >> value;
    if(action == "forward")
    {
      horizontal += value;
    }
    else if(action == "up")
    {
      vertical -= value;
    }
    else if(action == "down")
    {
      vertical += value;
    }
  }
  std::cerr << horizontal * vertical << std::endl;
  return 0;
}
