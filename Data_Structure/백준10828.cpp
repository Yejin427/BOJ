#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> q;
int main() {
	int N, x;
	string s;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "top") {
			if (q.empty() == 0) {
				cout << q.top() << "\n";
			}
			else cout << "-1" << "\n";
		}
		else if (s == "pop") {
			if (q.empty() == 0) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << "-1" << "\n";
			}
		}
		else if (s == "size") cout << q.size() << "\n";
		else if (s == "empty") cout << q.empty() << "\n";
		else {
			cin >> x;
			q.push(x);
		}
	}
	return 0;
}