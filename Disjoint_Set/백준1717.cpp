#include<iostream>
using namespace std;
int parent[1000002];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void uni(int nodea, int nodeb) {
	int roota = find(nodea);
	int rootb = find(nodeb);
	parent[rootb] = roota;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, state, n1, n2;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		cin >> state >> n1 >> n2;
		if (!state) {
			uni(n1, n2);
		}
		else {
			if (find(n1)==find(n2)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}