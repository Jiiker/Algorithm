/* [PCCP 모의고사 #1] 1번 - 외톨이 알파벳 */ 

#include <string>
#include <vector>

using namespace std;

string solution(string input_string) {
    int check_cnt[26] = { 0 };
    string answer = "";
    
    for (int i = 0; i < input_string.length(); i++)
    {
        if (i == 0)
        {
            check_cnt[input_string[i] - 'a']++;
            continue;
        }
        if (input_string[i] == input_string[i-1])
        {
            continue;
        }
        check_cnt[input_string[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        char c = '\0';
        if (check_cnt[i] > 1)
        {
            c = i + 'a';
            answer = answer + c;
        }
    }
    if (answer.length() == 0)
    {
        return "N";
    }
    
    return answer;
}