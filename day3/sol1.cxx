#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int CharBinaryToDecimal(char* binary, int length)
{
  int decimal = 0;
  for(int i = length - 1; i >=0; i--)
  {
    decimal += ((int)binary[i] - 48) * pow(2, (length - 1 - i));
  }
  return decimal;
}

int main()
{
  std::ifstream file;
  file.open("input");
  std::vector<int> _0(20, 0);
  std::vector<int> _1(20, 0);
  int maxlen = 0;
  while(!file.eof())
  {
    std::string binary;
    file >> binary;
    int len = binary.length();
    maxlen = std::max(len, maxlen);
    const char* str = binary.c_str();
    for(int i = 0; i < len; i++)
    {
      if(str[i] == '1')
        _0[i]++;
      if(str[i] == '0')
        _1[i]++;
    }
  }
  char _gam[maxlen + 1];
  char _eps[maxlen + 1];
  _gam[maxlen] = '\0';
  for(int i =0; i < maxlen; i++)
  {
    if(_1[i] > _0[i])
    {
      _gam[i] = '1';
      _eps[i] = '0';
    }
    else
    {
      _gam[i] = '0';
      _eps[i] = '1';
    }
  }
  int gamma   = CharBinaryToDecimal(_gam, maxlen);
  int epsilon = CharBinaryToDecimal(_eps, maxlen);
  std::cerr << gamma * epsilon << std::endl;
  return 0;
}
