#include <bits/stdc++.h>

using namespace std;

bool check_password(string str)
{
  bool isIncludeVow = false;
  int continuousVowCnt = 0;
  int continuousConsCnt = 0;
  char prevChar = ' ';

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
    {
      isIncludeVow = true;
      continuousConsCnt = 0;
      continuousVowCnt++;
    }
    else
    {
      continuousConsCnt++;
      continuousVowCnt = 0;
    }

    if (continuousConsCnt >= 3 || continuousVowCnt >= 3)
      return false;
    
    if (prevChar == str[i] && str[i] != 'e' && str[i] != 'o')
      return false;

    prevChar = str[i];
  }
  if (!isIncludeVow)
    return false;
  
  return true;
}

int main()
{
  string str = "";

  while (1)
  {
    bool isOkay = false;
    cin >> str;

    if (str == "end")
      break;

    isOkay = check_password(str);
    if (isOkay)
      cout << '<' << str << "> is acceptable." << '\n';
    else
      cout << '<' << str << "> is not acceptable." << '\n';
  }

  return 0;
}