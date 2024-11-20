#include <iostream>

using namespace std;

int arr[51][51];
int check[51];
int t, m, n, k, x, y;
int cnt = 0;
int xpos[4] = { 0, 0, -1, 1 };
int ypos[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	arr[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + xpos[i];
		int yy = y + ypos[i];
		if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
		if (arr[xx][yy] == 1) dfs(xx, yy);
	}
}


int main() {


	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k; //m : 가로 길이 n : 세로 길이 k : 배추 개수
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int p = 0; p < m; p++) {
			for (int q = 0; q < n; q++) {
				if (arr[p][q] == 1) {
					dfs(p, q);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		for (int p = 0; p < m; p++) {
			for (int q = 0; q < n; q++) {
				arr[p][q] = 0;
			}
		}
	}



	return 0;
}