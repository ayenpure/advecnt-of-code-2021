#include <iostream>
#include <fstream>
#include <vector>

int main()
{
  std::vector<int> depths;
  std::ifstream input;
  input.open("input1");
  int num;
  while(input >> num)
  {
    depths.push_back(num);
  }
  int accum = 0;
  for(int i = 1; i < depths.size(); i++)
  {
    if(depths[i] > depths[i-1])
      accum++;
  }
  std::cerr << accum << std::endl;
}
