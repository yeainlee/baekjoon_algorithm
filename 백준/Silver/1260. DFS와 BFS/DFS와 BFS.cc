#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
queue <int> q;
queue <int> q2;
queue <int> bb;

#define MAX 1001

int n, m, v;
int arr[MAX][MAX];
bool check[MAX];
bool check2[MAX];

void BFS(int kk) {
	check2[kk] = true;
	bb.push(kk);
	while (!bb.empty()) {
		kk = bb.front();
		bb.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[kk][i] == 1) {
				if (check2[i] == false) {
					check2[i] = true;
					bb.push(i);
					q2.push(i);
				}
			}
		}
	}
}

void DFS(int kk) {
	for (int i = 1; i <= n; i++) {
		if (arr[kk][i] == 1){
			if (check[i] == false){
				q.push(i);
				check[i] = true;
				DFS(i);
			}
		}
	}
}


int main() {
	cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	//DFS
	q.push(v);
	check[v] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1) {
			if (check[i] == false) {
				check[i] = true;
				q.push(i);
				DFS(i);
			}
		}
	}

	while(!q.empty()) {
		int nn = q.front();
		q.pop();
		cout << nn << " ";
	}
	cout << endl;

	//BFS
	q2.push(v);
	BFS(v); 

	while (!q2.empty()) {
		int nn = q2.front();
		q2.pop();
		cout << nn << " ";
	}
	return 0;
}
