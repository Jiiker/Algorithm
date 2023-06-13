#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N = 0;
	int queue[2000000];
	int head = 0, tail = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		string cmd;

		cin >> cmd;

		if (cmd == "push")
			cin >> queue[tail++];
		else if (cmd == "pop")
		{
			if (head != tail)
				cout << queue[head++] << '\n';
			else
				cout << -1 << '\n';
		}
		else if (cmd == "size")
			cout << tail - head << '\n';
		else if (cmd == "empty")
		{
			if (head != tail)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (cmd == "front")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
				cout << queue[head] << '\n';
		}
		else if (cmd == "back")
		{
			if (head == tail)
				cout << -1 << '\n';
			else
			{
				cout << queue[--tail] << '\n';
				tail++;
			}
		}
	}


	return 0;
}