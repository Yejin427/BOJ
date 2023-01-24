#include<iostream>
using namespace std;
int prime(int x) {
	int chk = 1;
	if (x == 0 || x == 1) return 0;
	else {
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				chk = 0;
				break;
			}
		}
	}
	return chk;
}
int main() {
	int n, a, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans += prime(a);
	}
	cout << ans;
}