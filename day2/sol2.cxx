#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream file;
  file.open("input2");
  long horizontal = 0;
  long vertical = 0;
  long aim = 0;
  while(!file.eof())
  {
    std::string action;
    int value;
    file >> action >> value;
    if(action == "forward")
    {
      horizontal += value;
      vertical += aim * value;
    }
    else if(action == "up")
    {
      aim -= value;
    }
    else if(action == "down")
    {
      aim += value;
    }
  }
  std::cerr << horizontal * vertical << std::endl;
  return 0;
}
