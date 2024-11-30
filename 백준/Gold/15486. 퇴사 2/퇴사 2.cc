#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500001];
int n, day, point;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> day >> point;
		dp[i + day] = max(dp[i + day], dp[i] + point);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}

	cout << dp[n + 1] << endl;

}