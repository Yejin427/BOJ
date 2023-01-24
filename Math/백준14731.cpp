#include<iostream>
#define M 1000000007
using namespace std;
int c;
long long int k, ans, l;
long long int jegob(long long int x,long long int y) {
	if (y == 0) return 1;
	else if (y == 1) return x;
	if (y % 2 == 1) return jegob(x, y - 1) * x;
	long long int half = jegob(x, y / 2);
	half %= M;
	return (half * half) % M;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c >> k;
		l = (c * k) % M;
		ans += (l * jegob(2, k - 1) % M) % M;
	}
	cout << ans % M;
}