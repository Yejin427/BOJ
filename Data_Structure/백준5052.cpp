#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string word; cin >> word;
			v.push_back(word);
		}
		sort(v.begin(), v.end());
		cout << v.size() << '\n';
		bool flag = false;
		for (int i = 0; i < n - 1; i++) {
			int cur = v[i].length();
			int next = v[i + 1].length();
			if (cur < next) {
				string sub = v[i + 1].substr(0, cur);
				if (sub == v[i]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
		v.clear();
	}
}