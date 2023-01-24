#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int c[300001];
struct jewelry {
	int m, v;
};
struct cmp1 {
	bool operator()(jewelry a, jewelry b) {
		if (a.m == b.m){//무게 같을땐
			return a.v < b.v;//가격 높은거 먼저
		}
		return a.m > b.m;//무게 작은거 우선순위
	}
};
struct cmp2 {
	bool operator()(jewelry a, jewelry b) {
		if (a.v == b.v) {
			return a.m > b.m;
		}
		return a.v < b.v;
	}
};
priority_queue<jewelry, vector<jewelry>, cmp1> pq;
priority_queue<jewelry, vector<jewelry>, cmp2> pq2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		struct jewelry j;
		cin >> j.m >> j.v;
		pq.push(j);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
	sort(c + 1, c + k + 1);
	long long int ans = 0;
	for (int i = 1; i <= k; i++) {
		while (!pq.empty() && pq.top().m <= c[i]) {//현재 가방에 넣을 수 있는 후보군들
			jewelry x = pq.top();
			pq.pop();
			pq2.push(x);//다른 피큐투에 집어넣음
		}
		if (!pq2.empty()) {//pq2가 비어있다면 패스
			ans += pq2.top().v;//가장 비싼것 추가
			pq2.pop();//추가했으면 후보군에서 제외
		}
	}

	cout << ans;
}