#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main() {
	int N, K;
	int x;
	cin >> N >> K;
	cout << "<";
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size() !=1) {
		for (int i = 1; i < K; i++) {
			x = q.front();
			q.pop();
			q.push(x);
		}
		cout << q.front()<<", ";
		q.pop();
	}
	cout << q.front() << ">";
	return 0;
}