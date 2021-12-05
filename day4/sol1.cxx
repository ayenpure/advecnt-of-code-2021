#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Board
{
public:
  Board(std::vector<int>& _numbers)
  : numbers(_numbers)
  {
    this->mark = std::vector<int>(25, 0);
  }

  int CheckRows()
  {
    int found = 0;
    for(int i = 0; i < 5; i++)
    {
      int valid = 0;
      for(int j = 0; j < 5; j++)
      {
        int ind = (i*5) + j;
        if(mark[ind] == 1)
        {
          valid++;
        }
        else
          break;
      }
      if(valid == 5)
      {
        found = 1;
        break;
      }
    }
    if(found)
    {
      int sum = 0;
      for(int i = 0; i < 25; i++)
      {
        sum += (mark[i] == 0) ? numbers[i] : 0;
      }
      return sum;
    }
    return 0;
  }

  int CheckColumns()
  {
    int found = 0;
    for(int j = 0; j < 5; j++)
    {
      int valid = 0;
      for(int i = 0; i < 5; i++)
      {
        int ind = (i*5) + j;
        if(mark[ind] == 1)
        {
          valid++;
        }
        else
          continue;
      }
      if(valid == 5)
      {
        found = 1;
        break;
      }
    }
    if(found)
    {
      int sum = 0;
      for(int i = 0; i < 25; i++)
      {
        sum += (mark[i] == 0) ? numbers[i] : 0;
      }
      return sum;
    }
    return 0;
  }

  void Mark(int pick)
  {
    for(int i = 0; i < 25; i++)
      if(numbers[i] == pick)
        mark[i] = 1;
  }

private:
  std::vector<int> numbers;
  std::vector<int> mark;
};

int main()
{
  std::vector<int> picks;
  std::vector<Board> boards;
  std::string _picks;
  std::ifstream file;
  file.open("input");
  // Read Draws;
  if(!file.eof())
    std::getline(file, _picks);
  std::stringstream picker(_picks);

  for (int i; picker >> i;) {
    picks.push_back(i);
    if (picker.peek() == ',')
      picker.ignore();
  }

  while(!file.eof())
  {
    std::vector<int> _numbers;
    int num;
    for(int i = 0; i < 25 && !file.eof(); i++)
    {
      file >> num;
      _numbers.push_back(num);
    }
    if(_numbers.size() != 25)
      break;
    std::cerr << std::endl;
    std::cerr << std::endl;
    Board board(_numbers);
    boards.push_back(board);
  }
  file.close();

  for(int i = 0; i < picks.size(); i++)
  {
    int pick = picks[i];
    for(int j = 0; j < boards.size(); j++)
    {
      Board& board = boards[j];
      board.Mark(pick);
      int sum;
      sum = board.CheckRows();
      if( sum != 0 )
      {
        std::cerr << sum * pick << std::endl;
        return 0;
      }
      sum = board.CheckColumns();
      if( sum != 0 )
      {
        std::cerr << sum * pick << std::endl;
        return 0;
      }
    }
  }

  return 0;
}

