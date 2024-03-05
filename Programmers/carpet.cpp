#include <string>
#include <vector>

using namespace std;

pair<int, int> sim_equation(int b, int y)
{
  int width = 0, length = 0;
  
  for (int w = 1; w <= y; w++)
  {
    if (y % w != 0)
      continue;
      
    int l = y / w;
    if ((2 * w) + (2 * l) + 4 == b)
    {
      width = w;
      length = l;
      break;
  }
  }
  
  return {width + 2, length + 2};
}

vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  pair<int, int> result;
  
  result = sim_equation(brown, yellow);
  answer.push_back(result.second);
  answer.push_back(result.first);
  
  return answer;
}