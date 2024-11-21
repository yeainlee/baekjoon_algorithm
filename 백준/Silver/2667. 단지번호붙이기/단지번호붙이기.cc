#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n;
int arr[26][26];
int num = 0;
vector<int> people;
int cnt;
int xpos[4] = { 0, 0, 1, -1 };
int ypos[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	
	arr[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + xpos[i];
		int yy = y + ypos[i];

		if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
		if (arr[xx][yy] == 1) {
			cnt++;
			dfs(xx, yy);
		}

	}

}

int main() {
	cin >> n;

	string str;
	
	for (int i = 0; i < n; i++) {
		cin >> str;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '1') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				cnt = 1;
				num++;
				dfs(i, j);
				people.push_back(cnt);
			}
		}
	}

	cout << num << endl;
	sort(people.begin(), people.end());


	for (int i = 0; i < people.size(); i++) {
		cout << people[i] << endl;
	}

	return 0;
}
