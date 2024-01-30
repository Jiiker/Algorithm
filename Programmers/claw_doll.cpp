#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  stack<int> S;
  
  S.push(0);
  for (int i = 0; i < moves.size(); i++)
  {
    for (int j = 0; j < board.size(); j++)
    {
      if (board[j][moves[i] - 1] != 0)
      {
        if (S.top() == board[j][moves[i] - 1])
        {
          board[j][moves[i] - 1] = 0;
          answer = answer + 2;
          S.pop();
          break;
        }
        
        S.push(board[j][moves[i] - 1]);
        board[j][moves[i] - 1] = 0;
        break;
      }
    }
  }
  
  return answer;
}
