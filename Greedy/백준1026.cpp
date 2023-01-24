#include<iostream>
#include<algorithm>
using namespace std;
int a[51], b[51];
int main() {
	int n,ans=0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans;
}