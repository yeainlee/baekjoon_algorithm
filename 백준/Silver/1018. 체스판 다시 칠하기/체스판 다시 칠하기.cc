#include <iostream>
#include <algorithm>

using namespace std;

char w[8][8] = { 
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

char b[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};



int main() {
	int N, M;
	cin >> N >> M;
	int min_w = 100000;
	int min_b = 100000;

	char nm[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> nm[i][j];
		}
	}

	int min_val = 100000;
	int ww = 0;
	int bb = 0;
	
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {

			for (int k = i; k < i + 8; k++) {
				for (int t = j; t < j + 8; t++) {
					
					if (w[k-i][t-j] != nm[k][t]) ww++;
					if (b[k-i][t-j] != nm[k][t]) bb++;
				}
			}
			min_val = min({ min_val, ww, bb });
			ww = 0;
			bb = 0;
		}
	}
	
	cout << min_val << endl;

	return 0;
}