#include <iostream>

using namespace std;

int cnt[12] = { 0, };

void func(int a, int arr[][5]){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a == arr[i][j]) {
				cnt[i]++;
				cnt[5 + j]++;
				if (i == j) cnt[10]++;
				if (i + j == 4) cnt[11]++;
				return;
			}
		}
	}
	return;
}


int main() {
	int arr[5][5];
	int a;
	int ans;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a;
			arr[i][j] = a;
		}
	}

	int num = 1; //사회자가 부른 숫자 갯수
	int raw_num = 0;
	bool ck = true;
	while (ck) {

		cin >> a;
		func(a, arr);
		raw_num = 0; // 빙고 선 갯수
		for (int k = 0; k < 12; k++) {
			if (cnt[k] == 5) {
				raw_num++;	
			}
		}

		if (raw_num >= 3) {
			ck = false;
			ans = num;
		}
	
		num++;
	
	}

	cout << ans << endl;

	
	return 0;
}