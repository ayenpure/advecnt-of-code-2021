#include <iostream>
#include <fstream>
#include <vector>

struct window
{
  int _1, _2, _3;
};

int windowsum(window* w)
{
  std::cerr << w->_1 + w->_2 + w->_3 << std::endl;
  return w->_1 + w->_2 + w->_3;
}

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
  int* start = depths.data();
  for(int i = 0; i < depths.size() - 3; i++)
  {
    window* w1 = (window*)&start[i];
    window* w2 = (window*)&start[i+1];
    if(windowsum(w2) > windowsum(w1))
      accum++;
  }
  std::cerr << accum << std::endl;
}
