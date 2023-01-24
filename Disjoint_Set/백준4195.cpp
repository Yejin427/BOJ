#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
map<string, int> m;
int parent[200001];
int arr[200001];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void uni(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota != rootb) {
		parent[rootb] = roota;
		arr[roota] += arr[rootb];
		arr[rootb] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, f; cin >> t;
	while (t--) {
		cin >> f;
		memset(parent, 0, sizeof(parent));
		memset(arr, 1, sizeof(arr));
		int idx = 1;
		m.clear();
		for (int i = 0; i < f; i++) {
			string a, b; cin >> a >> b;
			if (!m.count(a)) {
				m[a] = idx;
				parent[idx] = idx;
				arr[idx] = 1;
				idx++;
			}
			if (!m.count(b)) {
				m[b] = idx;
				parent[idx] = idx;
				arr[idx] = 1;
				idx++;
			}
			int fa = find(m[a]);
			int fb = find(m[b]);
			if (fa != fb) uni(fa, fb);
			cout << max(arr[fa], arr[fb]) << "\n";
			
		}
	}

}