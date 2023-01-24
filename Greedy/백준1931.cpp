#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct conference {
	int start;
	int finish;
	conference(int a, int b) :start(a), finish(b) {}
};
bool operator<(conference a, conference b) {
	if (a.finish == b.finish) {
		return a.start < b.start;
	}
	return a.finish < b.finish;
}
int main() {
	int n; cin >> n;
	vector<conference> v;
	for (int i = 0; i < n; i++) {
		int start_time, end_time;
		cin >> start_time >> end_time;
		v.push_back(conference(start_time, end_time));
	}
	sort(v.begin(), v.end());
	int answer = 1;
	int before_conference = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].start >= v[before_conference].finish) {
			before_conference = i;
			answer++;
		}
	}
	cout << answer;
}