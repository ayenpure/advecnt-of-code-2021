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

void PruneList(std::vector<std::string>& numbers, char* gamma, int length)
{
  std::vector<std::string> oxy = numbers;
  std::cerr << gamma << " | Sz before : " << oxy.size() << std::endl;
  for(int i = 0; i < length; i++)
  {
    std::cerr << "Getting : " << gamma[i] << std::endl;
    std::vector<std::string> _oxy;
    for(int j = 0; j < oxy.size(); j++)
    {
      if(oxy[j].c_str()[i] == gamma[i])
      {
        std::cerr << "Match : " << oxy[j] << std::endl;
        _oxy.push_back(oxy[j]);
      }
    }
    oxy = _oxy;
    std::cerr << "Sz after : " << oxy.size() << std::endl;
  }
}

int main()
{
  std::ifstream file;
  file.open("input");
  std::vector<int> _0(20, 0);
  std::vector<int> _1(20, 0);
  int maxlen = 0;
  std::vector<std::string> numbers;
  while(!file.eof())
  {
    std::string binary;
    file >> binary;
    numbers.push_back(binary);
    int len = binary.length();
    maxlen = std::max(len, maxlen);
    const char* str = binary.c_str();
    for(int i = 0; i < len; i++)
    {
      if(str[i] == '1')
        _1[i]++;
      if(str[i] == '0')
        _0[i]++;
    }
  }

  char tlet[maxlen + 1];
  tlet[maxlen] = '\0';
  for(int i = 0; i < maxlen; i++)
  {
    std::cerr << _1[i] << "vs." << _0[i] <<  std::endl;
    if(_1[i] >= _0[i])
    {
      tlet[i] = '1';
    }
    else
    {
      tlet[i] = '0';
    }
  }

  // Oxygen
  PruneList(numbers, tlet, maxlen);
  // Carbon
  //PruneList(numbers, _eps, maxlen);

  //int gamma   = CharBinaryToDecimal(_gam, maxlen);
  //int epsilon = CharBinaryToDecimal(_eps, maxlen);
  //std::cerr << gamma * epsilon << std::endl;
  return 0;
}
