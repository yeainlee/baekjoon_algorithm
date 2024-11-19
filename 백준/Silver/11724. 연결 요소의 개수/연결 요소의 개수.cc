#include <iostream>

using namespace std;

int arr[1001][1001];
bool check[1001];
int n, m;

void dfs(int v) {

	check[v] = true;

	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1) {
			if (check[i] == false) {
				dfs(i);
			}
		}
	}
}


int main() {
	int cnt = 0;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			cnt++;
			dfs(i);
		}

	}

	cout << cnt << endl; 

	return 0;
}