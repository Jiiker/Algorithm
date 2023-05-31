#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0, result = 10000005;
	int arr[1005][3];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
			if (i > 0)
			{
				if (j == 0)
					arr[i][j] = arr[i][j] + min(arr[i - 1][1], arr[i - 1][2]);
				else if (j == 1)
					arr[i][j] = arr[i][j] + min(arr[i - 1][0], arr[i - 1][2]);
				else
					arr[i][j] = arr[i][j] + min(arr[i - 1][0], arr[i - 1][1]);
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (arr[N - 1][i] < result)
			result = arr[N - 1][i];
	}

	cout << result;
	
	return 0;
}