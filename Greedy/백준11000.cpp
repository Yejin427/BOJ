#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Class {
	int start;
	int finish;
	Class(int a, int b) :start(a), finish(b) {}
};
bool operator<(Class a, Class b) {
	if (a.start == b.start) {
		return a.finish < b.finish;
	}
	return a.start < b.start;
}
struct earlyend {
	bool operator()(Class a, Class b) {
		if (a.finish == b.finish) {
			return a.start > b.start;
		}
		return a.finish > b.finish;
	}
};
int main() {
	int n; cin >> n;
	vector<Class> c;
	priority_queue<Class, vector<Class>, earlyend> pq;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		c.push_back(Class(a, b));
	}
	sort(c.begin(), c.end());
	pq.push(c[0]);
	for (int i = 1; i <= n - 1; i++) {
		if (pq.top().finish > c[i].start) {
			pq.push(c[i]);
		}
		else {
			pq.pop();
			pq.push(c[i]);
		}
	}
	cout << pq.size();
}