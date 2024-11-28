#include <iostream>
#include <algorithm>

using namespace std;

int N;
char street[1001];
int DP[1001];

void solution() {
	DP[1] = 0;
	for (int i = 1; i < N; i++) {
		if (street[i] == 'B') {
			for (int j = i + 1; j <= N; j++) {
				if (street[j] == 'O')
					DP[j] = min(DP[j], (j - i) * (j - i) + DP[i]);
			}
		}
		else if (street[i] == 'O') {
			for (int j = i + 1; j <= N; j++) {
				if (street[j] == 'J')
					DP[j] = min(DP[j], (j - i) * (j - i) + DP[i]);
			}
		}
		else {
			for (int j = i + 1; j <= N; j++) {
				if (street[j] == 'B')
					DP[j] = min(DP[j], (j - i) * (j - i) + DP[i]);
			}
		}
	}
	if (DP[N] == 9999999)
		cout << -1 << '\n';
	else
		cout << DP[N] << '\n';
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> street[i];
	}
	fill(DP, DP + 1001, 9999999);
	solution();
	return 0;
}