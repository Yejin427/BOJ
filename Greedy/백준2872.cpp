#include<iostream>
using namespace std;
int book[300005];
int main() {
	int n, ans = 0,check;
	cin >> n;
	check = n;
	for (int i = 1; i <= n; i++) {
		cin >> book[i];
	}
	for (int i = n; i >= 1; i--) {
		if (book[i] == check) {
			check--;
		}
		else {
			ans++;
		}
	}
	cout << ans;
}