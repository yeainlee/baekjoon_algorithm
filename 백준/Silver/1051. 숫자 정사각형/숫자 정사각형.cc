#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

bool func(int N, int M, int max_size, int arr[][51]) {
	for (int i = 0; i <= N - max_size; i++) {
		for (int j = 0; j <= M - max_size; j++) {
			if (arr[i][j] == arr[i + max_size-1][j]
				&& arr[i + max_size-1][j] == arr[i + max_size-1][j + max_size-1]
				&& arr[i + max_size-1][j + max_size-1] == arr[i][j + max_size-1]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	int arr[51][51];
	
	string a[51];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = a[i][j] - '0';
		}
	}
	
	int max_size = min(N, M);

	bool ck = false;
	
	while (1) {
		
		if (max_size == 1) {
			break;
		}

		ck = func(N, M, max_size, arr);
		
		if (ck == true) break;
		else max_size--; // ck == false


	}

	cout << max_size * max_size << endl;
	
	return 0;
}