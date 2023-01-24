#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> p;
priority_queue<p,vector<p>,greater<p>> q;
int main() {
	int N, n, x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		if (n == 0) {
			if (q.empty() == 1) {
				cout << "0\n";
			}
			else {
				cout << q.top().second << '\n';
				q.pop();
			}
			
		}
		else {
			q.push(make_pair(abs(n), n));
		}
	}
	return 0;
}