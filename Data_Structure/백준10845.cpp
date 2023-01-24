#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int> q;
int main() {
	int N, x;
	string s;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "front") {
			if (q.empty() == 0) {
				cout << q.front() << "\n";
			}
			else cout << "-1" << "\n";
		}
		else if (s == "pop") {
			if (q.empty() == 0) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1" << "\n";
			}
		}
		else if (s == "size") cout << q.size()<<"\n";
		else if (s == "empty") cout<< q.empty()<<"\n";
		else if (s == "back") {
			if (q.empty() == 0) {
				cout << q.back() << "\n";
			}
			else cout << "-1" << "\n";
		}
		else {
			cin >> x;
			q.push(x);
		}
	}
}