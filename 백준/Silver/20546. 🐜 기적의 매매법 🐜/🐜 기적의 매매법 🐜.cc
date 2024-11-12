#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	int b_num = 0;
	int t_num = 0;
	int bnp, timing;
	int coin;
	vector<int> chart;
	int a;

	cin >> coin;
	for (int i = 0; i < 14; i++) {
		cin >> a;
		chart.push_back(a);
	}

	//준현이
	int coin_b = coin;
	for (int i = 0; i < 14; i++) {
		b_num += coin_b / chart[i];
		coin_b %= chart[i];
	}
	bnp = b_num * chart[13] + coin_b;

	//성민이
	int coin_t = coin;
	for (int i = 3; i < 14; i++) {
		//3일 연속 상승 -> 전량 매도
		if (chart[i] > chart[i - 1] && chart[i - 1] > chart[i - 2] && chart[i-2] > chart[i-3] && t_num != 0) {
			coin_t += chart[i] * t_num;
			t_num = 0;
		}
		//3일 연속 하락 -> 전량 매수
		else if (chart[i] < chart[i - 1] && chart[i - 1] < chart[i - 2] && chart[i-2] < chart[i-3] && coin_t >= chart[i]) {
			t_num += coin_t / chart[i];
			coin_t %= chart[i];
		}
	}
	timing = t_num * chart[13] + coin_t;

	if (bnp > timing) cout << "BNP" << endl;
	else if (bnp < timing) cout << "TIMING" << endl;
	else cout << "SAMESAME" << endl;

	return 0;
}