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
		if (a.m == b.m){//���� ������
			return a.v < b.v;//���� ������ ����
		}
		return a.m > b.m;//���� ������ �켱����
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
		while (!pq.empty() && pq.top().m <= c[i]) {//���� ���濡 ���� �� �ִ� �ĺ�����
			jewelry x = pq.top();
			pq.pop();
			pq2.push(x);//�ٸ� ��ť���� �������
		}
		if (!pq2.empty()) {//pq2�� ����ִٸ� �н�
			ans += pq2.top().v;//���� ��Ѱ� �߰�
			pq2.pop();//�߰������� �ĺ������� ����
		}
	}

	cout << ans;
}