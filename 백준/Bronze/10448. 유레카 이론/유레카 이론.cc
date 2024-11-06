#include <iostream>
#include <vector>

using namespace std;

//세개의 값 더해서 Tn[i]와 같으면 1, 없으면 0 return
int func(vector<int> tri_num, int tn) {
	int sum = 0;
	for (int i = 0; i < tri_num.size(); i++) {
		for (int j = 0; j < tri_num.size(); j++) {
			for (int k = 0; k < tri_num.size(); k++) {
				sum = tri_num[i] + tri_num[j] + tri_num[k];
				if (sum == tn) return 1;
				else sum = 0;
			}
		}
	}
	return 0;	
}

int main() {
	int n;
	vector<int> Tn;
	vector<int> tri_num;
	vector<int> ans;
	int tt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tt;
		Tn.push_back(tt);
	}

	for (int i = 0; i < n; i++) {
		// Tn[i]보다 작은 삼각수 구하기
		// Tn[i]보다 작은 삼각수 값 tri_num에 저장
		int nn = 1;
		while (nn * (nn + 1) < 2 * Tn[i]) {
			tri_num.push_back(nn * (nn + 1) / 2);
			nn++;
		}	
		
		ans.push_back(func(tri_num, Tn[i]));
		tri_num.clear();
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}


	return 0;
}