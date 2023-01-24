#include<iostream>
#include<stack>
using namespace std;
stack<pair<int, int>> s;
int N, H;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H;
		while (!s.empty()) {
			if (s.top().second > H) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) cout << 0 << " ";
		s.push(make_pair(i, H));
	}
	return 0;
}