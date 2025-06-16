#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
int result = -1;

void dfs(string cur, string dest) {
    if (cur.length() == 5) {
        cnt++;
        if (cur == dest) {
            result = cnt;
        }
        return;
    }

    for (int i = 0; i <= 5; i++) {
        if (i == 0) {
            if (cur.length() == 0) continue;
            
            cnt++;
            if (cur == dest) {
                result = cnt;
                return;
            }
            continue;
        }
        
        if (i == 1) {
            cur += 'A';
        } else if (i == 2) {
            cur += 'E';
        } else if (i == 3) {
            cur += 'I';
        } else if (i == 4) {
            cur += 'O';
        } else if (i == 5) {
            cur += 'U';
        }
        
        dfs(cur, dest);
        cur = cur.substr(0, cur.length() - 1);
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs("", word);
    answer = result;
    
    return answer;
}