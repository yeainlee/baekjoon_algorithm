#include <iostream>

using namespace std;

int main() {
	int num;
	int a, b;
	int ball = 1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		if (a == ball) {
			ball = b;
		}
		else if (b == ball) {
			ball = a;
		}
	}
	cout << ball << endl;
	
	return 0;
}
