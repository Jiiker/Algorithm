#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int N = 0;

	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= N; i++)
		Q.push(i);

	while (!Q.empty())
	{
		int temp = 0;

		Q.pop();
		if (Q.size() == 1)
			break;

		temp = Q.front();
		Q.pop();

		Q.push(temp);
	}

	cout << Q.front();

	return 0;
}