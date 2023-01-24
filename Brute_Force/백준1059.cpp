#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	int n, k, l, ans, a, b = 0;
	cin >> n;
	while (n--) {
		cin >> k;
		v.push_back(k);
	}
	cin >> l;
	sort(v.begin(), v.end());
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (*iter > l) {
			a = *iter;
			ans = (a - b - 2) + (l - b - 1) * (a - l - 1);
			break;
		}
		else if (*iter < l) b = *iter;
		else {
			ans = 0;
			break;
		}
	}
	cout << ans;
}//¾î¿ì¾¾ µåµð¾î ¸ÂÃè³×;;