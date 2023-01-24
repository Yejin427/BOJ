#include<iostream>
#include<algorithm>
using namespace std;
long int home[200001];
int main() {
	int n, c, l, r, mid, ans, d;
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> home[i];
	sort(home, home + n);
	
	l = 1, r = home[n - 1] - home[0];
	while (l <= r) {
		mid = (l + r) / 2;
		int start = home[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			d = home[i] - start;
			if (d >= mid) {
				cnt++;
				start = home[i];
			}
		}
		if (cnt >= c) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}