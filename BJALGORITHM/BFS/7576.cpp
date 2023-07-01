#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, cnt = 0, max = 0;
	int arr[1005][1005] = { 0 };
	int vis[1005][1005] = { 0 };
	queue<pair<int, int> > Q;
	int start_i = 0, start_j = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				cnt++;
			if (arr[i][j] == 1)
			{
				Q.push({ i, j });
				vis[i][j] = 1;
			}
		}
	}

	if (cnt == 0)
	{
		cout << 0;
		return 0;
	}

	while (!Q.empty())
	{
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (arr[nx][ny] == -1 || arr[nx][ny] == 1 || vis[nx][ny] == 1)
				continue;

			Q.push({ nx, ny });
			cnt--;
			vis[nx][ny] = 1;
			arr[nx][ny] = arr[cur.first][cur.second] + 1;
			if (arr[nx][ny] > max)
				max = arr[nx][ny];
		}
	}

	if (cnt == 0)
		cout << max - 1;

	else
		cout << -1;

	
	return 0;
}