#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<int> v[200001];
queue<int> q;
queue<int> sq;
int arr[200001];//i번째 학생이 루머 믿는 시간
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		int x;
		while (cin >> x && x) {
			v[i].push_back(x);
		}
	}
	int num; cin >> num;
	for(int i = 1; i <= num; i++) {
		int k; cin >> k;
		q.push(k);
		arr[k] = 0;
	}
	while (!q.empty()) {
		int front = q.front();
		//cout << front << ": " << arr[front] << " ";
		q.pop();
		for (int i = 0; i < v[front].size(); i++) {
			if (arr[v[front][i]] != -1) continue;

			int cnt = 0;
			for (auto next : v[v[front][i]]) {
				if (arr[next] != -1)cnt++;
			}
			if (v[v[front][i]].size() <= cnt * 2) sq.push(v[front][i]);
		}
		if (q.empty()) {
			while (!sq.empty()) {
				int node = sq.front(); sq.pop();
				arr[node] = arr[front] + 1;
				q.push(node);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
}