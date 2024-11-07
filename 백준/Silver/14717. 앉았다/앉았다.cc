#include <iostream>
using namespace std;

int total = 153; // 18C2 = 18*17/2*1
float ans; 
int main() {
	int A, B;
	cin >> A >> B;
	if (A == B) {
		ans = (float)(153 - (10 - A)) / 153;
	}
	else {
		int cnt = 0;
		for (int i = 1; i <= 10; i++) {
			for (int j = i + 1; j <= 10; j++) {
				if ((A + B) % 10 > (i + j) % 10) {
					if (A != i && A != j && B != i && B != j) {
						cnt += 4;
					}
					else {
						cnt += 2;
					}
				} 
			}
		}
		ans = (float)cnt / 153;
	}

	cout << fixed;
	cout.precision(3);
	cout << ans << endl;

	return 0;
}