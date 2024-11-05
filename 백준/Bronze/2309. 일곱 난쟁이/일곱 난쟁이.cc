#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main() {
	int tall[9];
	int n_tall[7];
	int sum = 0;
	int ind_1;
	int ind_2;
	for (int i = 0; i < 9; i++) {
		cin >> tall[i];
		sum += tall[i];
	}
	int two = sum - 100;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) continue;
			else {
				if (tall[i] + tall[j] == two) {
					ind_1 = i;
					ind_2 = j;
					break;
				}
			}
		}
	}

	int jj = 0;
	for (int i = 0; i < 9; i++) {
		if (i == ind_1 || i == ind_2)continue;
		n_tall[jj] = tall[i];
		jj++;
	}
	sort(n_tall, n_tall + 7);

	for (int i = 0; i < 7; i++) {
		cout << n_tall[i] << endl;
	}
	return 0;

}