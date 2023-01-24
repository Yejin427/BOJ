#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int a, b, count = 0, d = 0;
	int ans = 0;
	cin >> a >> b;
	while (1) {
		count++;
		for (int i = 1; i <= count; i++) {
			v.push_back(count);
			d++;
		}
		if (b < d) break;
	}
	for (int i = a-1; i <= b-1; i++) {
		ans += v[i];
	}
	cout << ans;
}