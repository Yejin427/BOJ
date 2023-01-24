#include<iostream>
#include<vector>
using namespace std;
int parent[3001];
int cnt[3001];
struct line {
	int x1, y1, x2, y2;
};
vector<line> v;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;
	if (a < b) return 1;
	else if (a > b) return -1;
	else return 0;
}
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	int rx = find(x);
	int ry = find(y);
	parent[ry] = rx;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		struct line l = { x1,y1,x2,y2 };
		v.push_back(l);
		parent[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int x1 = v[i].x1; int x2 = v[i].x2; int x3 = v[j].x1; int x4 = v[j].x2;
			int y1 = v[i].y1; int y2 = v[i].y2; int y3 = v[j].y1; int y4 = v[j].y2;
			int abc = ccw(x1, y1, x2, y2, x3, y3);
			int abd = ccw(x1, y1, x2, y2, x4, y4);
			int cda = ccw(x3, y3, x4, y4, x1, y1);
			int cdb = ccw(x3, y3, x4, y4, x2, y2);
			if (abc * abd <= 0 && cdb * cda <= 0) {
				if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) || (x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) continue;
				if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) || (y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) continue;
				uni(i, j);
			}
		}
	}
	int max = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cnt[find(i)]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] != 0) ans++;
		if (max < cnt[i]) max = cnt[i];
	}
	cout << ans << '\n' << max << '\n';
}