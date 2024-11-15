#include <iostream>

using namespace std;

int N;
int ans = 1000000000;
bool check[22];
int stats[21][21];

void dfs(int x, int pos) //x는 카운트 수, pos는 다음값
{
	if (x == N / 2) {
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i] == true && check[j] == true) start += stats[i][j];
				if (check[i] == false && check[j] == false) link += stats[i][j];
			}
		}

		int temp = abs(start - link);
		if (ans > temp) ans = temp;

		return;
	}
	
	for (int i = pos; i < N; i++) {
		check[i] = true;
		dfs(x + 1, i + 1);
		check[i] = false;
	}
}



int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> stats[i][j];
		}
	}

	dfs(0, 1);
	cout << ans;
	return 0;
}