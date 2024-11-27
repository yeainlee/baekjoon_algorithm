#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[301]; //a층의 계단의 점수
int dp[301];  //a층 계단 까지의 최댓값

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n] << endl;

	return 0;
}