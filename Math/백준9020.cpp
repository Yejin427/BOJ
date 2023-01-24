#include<iostream>
#include<cmath>
using namespace std;
bool sosu[10001];//1이 합성수 0이 소수
int main() {
	int t; cin >> t;
	sosu[1] = 1;
	for (int i = 4; i <= 10000; i++) {
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				sosu[i] = 1;//합성수임
				break;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		int num; cin >> num;
		for (int j = num / 2; j > 0; j--) {
			if (!sosu[j] && !sosu[num - j]) {
				cout << j << " " << num - j << "\n";
				break;
			}
		}
	}
}