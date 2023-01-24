#include<iostream>
using namespace std;
int coin[12];
int main() {
	int n, k, ans = 0, r, q;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	while (k != 0) {
		for (int i = 0; i < n; i++) {
			if (k / coin[i] == 0) break;
			q = k / coin[i];
			r = k % coin[i];
		}
		ans += q;
		k = r;
	}
	cout << ans;
}