#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int bandage_cnt = 0;
    int finish_time = attacks[attacks.size() - 1][0];
    int attack_cnt = 0;
    int max_health = health;
    
    for (int i = 1; i <= finish_time; i++)
    {
        bandage_cnt++;
        if (i == attacks[attack_cnt][0])
        {
            health = health - attacks[attack_cnt][1];
            bandage_cnt = 0;
            attack_cnt++;
            if (health <= 0)
                return -1;
            continue;
        }
        if (health == max_health)
            continue;
        
        health = health + bandage[1];
        if (bandage_cnt == bandage[0])
        {
            health = health + bandage[2];
            bandage_cnt = 0;
        }
        if (health > max_health)
            health = max_health;
        
    }
    
    answer = health;
    
    return answer;
}