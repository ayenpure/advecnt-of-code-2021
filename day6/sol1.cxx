#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char** argv)
{
  std::ifstream file;
  file.open(argv[1]);

  std::vector<long> ages(9,0);//{0, 1, 1, 2, 1, 0, 0, 0, 0};//(9, 0);
  while(!file.eof())
  {
    int age;
    file >> age;
    std::cerr << age << " ";
    ages[age]++;
  }

  ages[1]--;

/*   for(int j = 0; j <= 8; j++)
    std::cerr << ages[j] << "\t";
  std::cerr << std::endl;
*/
  for(int i = 0; i < 256; i++)
  {
    long reprod = ages[0];
    for(int j = 1; j <= 8; j++)
    {
      ages[j - 1] = ages[j];
    }
    ages[6] += reprod;
    ages[8] = reprod;
/*   std::cerr << "Day : " << i+1 << " : ";
   for(int j = 0; j <= 8; j++)
    std::cerr << ages[j] << "\t";
  std::cerr << std::endl;*/
  }

  long count = 0;
  for(int j = 0; j <= 8; j++)
    count += ages[j];

  std::cerr << count << std::endl;
  return 0;
}
