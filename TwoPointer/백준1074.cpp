#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	ll n, r, c;
	cin >> n >> r >> c;
	ll ans = pow(4, n);
	ll r1 = r + 1; ll c1 = c + 1;
	ll left_c = 1; ll right_c = pow(2, n);
	ll left_r = 1; ll right_r = pow(2, n);
	while (n>0) {
		ll mid_c = (left_c + right_c) / 2;
		ll mid_r = (left_r + right_r) / 2;
		if (r1 <= mid_r && c1 <= mid_c) {//1사분면
			right_r = mid_r;
			right_c = mid_c;
			ans -= 3 * pow(4, n - 1);
		}
		else if (r1 > mid_r && c1 <= mid_c) {//3사분면
			left_r = mid_r + 1;
			right_c = mid_c;
			ans -= pow(4, n - 1);
		}
		else if (r1 <= mid_r && c1 > mid_c) {//2사분면
			left_c = mid_c + 1;
			right_r = mid_r;
			ans -= 2 * pow(4, n - 1);
		}
		else {//4사분면
			left_r = mid_r + 1;
			left_c = mid_c + 1;
		}
		n--;
	}
	std::cout << ans - 1;
} 