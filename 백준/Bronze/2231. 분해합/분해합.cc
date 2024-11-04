#include <iostream>

using namespace std;

int main() {
	
	int N;
	cin >> N;
	int ans = 0;
	int i = 1;
	while (i < N) {
		int sum = i;
		int num = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == N) {
			ans = i;
			break;
		}
		i++;
	}
	cout << ans << endl;
	

	return 0;
}
