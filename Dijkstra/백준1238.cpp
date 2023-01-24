#include<iostream>
#include<queue>
using namespace std;
vector<pair<int, int>> v[1001];//���¹���
vector<pair<int, int>> w[1001];//���� ����
int d[1001];//��Ƽ��->������
int b[1001];//������->��Ƽ��
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;
	while (m--) {
		int s, e, t;
		cin >> s >> e >> t;
		v[s].push_back({ e,t });
		w[e].push_back({ s,t });
	}
	//��Ƽ�忡�� �� �������� ���µ� �ɸ��� �ð� ����
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = pq.top().first;
		//cout << "cur: " << cur << "dist : " << dist << '\n';
		pq.pop();
		if (d[cur] != 0) continue;
		d[cur] = dist;
		for (int i = 0; i < v[cur].size(); i++) {
			if (d[v[cur][i].first] != 0) continue;
			pq.push({ dist + v[cur][i].second, v[cur][i].first });
		}
	}
	//cout << "\n";
	//�� �������� ��Ƽ����� ���µ� �ɸ��� �ð� ����
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = pq.top().first;
		//cout << "cur: " << cur << "dist : " << dist << '\n';
		pq.pop();
		if (b[cur] != 0) continue;
		b[cur] = dist;
		for (int i = 0; i < w[cur].size(); i++) {
			if (b[w[cur][i].first] != 0) continue;
			pq.push({ dist + w[cur][i].second, w[cur][i].first });
		}
	}

	int M = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		//cout <<i<<": "<< b[i] << " " << d[i] << '\n';
		M = max(M, b[i] + d[i]);
	}
	cout << M;
}