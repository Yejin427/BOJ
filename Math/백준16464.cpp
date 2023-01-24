#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		while (k % 2 != 1) {
			k /= 2;
		}
		if (k == 1) cout << "GoHanGang" << '\n';
		else cout << "Gazua" << '\n';
	}
}