#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visited[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v[1001];
	int n, maxd = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int d, w; cin >> d >> w;
		for (int j = 1; j <= d; j++) {
			v[i].push_back(w);
		}
		maxd = max(maxd, d);
	}
	//for (int i = 1; i <= n; i++) {
		//cout << i << "의 사이즈" << v[i].size() << "\n";
	//}
	long long ans = 0;
	int visit = 0;
	for (int i = maxd; i >= 1; i--) {
		int max_p = 0;
		for (int j = 1; j <= n; j++) {
			if (v[j].size() >= i && !visited[j]) {
				if (v[j][i - 1] > max_p) {
					max_p = v[j][i - 1];
					visit = j;
				}
			}
		}
		visited[visit] = true;
		visit = 0;
		ans += max_p;
	}
	cout << ans;
}