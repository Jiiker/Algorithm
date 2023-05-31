#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 0, n = 0;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int arr[11] = { 0 };
		cin >> n;

		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for (int j = 4; j <= n; j++)
			arr[j] = arr[j - 3] + arr[j - 2] + arr[j - 1];

		cout << arr[n] << '\n';
	}

	return 0;
}