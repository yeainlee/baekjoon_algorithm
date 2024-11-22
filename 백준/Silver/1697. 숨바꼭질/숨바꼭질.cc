#include <iostream>
#include <queue>

using namespace std;


int main() {
	int N, K;
	cin >> N >> K;
	queue<int> q;
	int minsec[100001] = { 0, };
	int nowN, sec = 0;
	
	q.push(N);
	while (!q.empty()) {
		nowN = q.front();
		q.pop();

		if (nowN < 0 || nowN > 100000) continue;
		if (nowN == K) {
			cout << minsec[nowN];
			break;
		}
		if (nowN - 1 >= 0 && minsec[nowN - 1] == 0) {
			minsec[nowN - 1] = minsec[nowN] + 1;
			q.push(nowN - 1);
		}
		if (nowN + 1 <= 100000 && minsec[nowN + 1] == 0) {
			minsec[nowN + 1] = minsec[nowN] + 1;
			q.push(nowN + 1);
		}
		if (2 * nowN <= 100000 && minsec[nowN * 2] == 0) {
			minsec[nowN * 2] = minsec[nowN] + 1;
			q.push(nowN * 2);
		}
	}


	return 0;
}