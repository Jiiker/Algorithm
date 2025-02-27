#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Node {
    int x, y, cost;
    string dir;
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    int cost[30][30][2];  // [row]와 [col]을 따로 관리
    fill(&cost[0][0][0], &cost[29][30][2], INT_MAX);
    
    queue<Node> Q;
    Q.push({0, 0, 0, "start"});
    
    cost[0][0][0] = cost[0][0][1] = 0;  // 시작점 비용 초기화
    
    while (!Q.empty()) {
        Node cur = Q.front();
        Q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 1) continue;

            int newCost = cur.cost + 100;
            int stateIdx = (dir == 0 || dir == 2) ? 0 : 1;  // 0: col(세로), 1: row(가로)

            if (cur.dir != "start" && 
                ((cur.dir == "col" && stateIdx == 1) || (cur.dir == "row" && stateIdx == 0))) {
                newCost += 500;  // 코너 비용 추가
            }

            if (cost[nx][ny][stateIdx] > newCost) {
                cost[nx][ny][stateIdx] = newCost;
                Q.push({nx, ny, newCost, (stateIdx == 0 ? "col" : "row")});
            }
        }
    }
    
    return min(cost[N - 1][N - 1][0], cost[N - 1][N - 1][1]);  // 두 방향 중 최소 비용 반환
}
