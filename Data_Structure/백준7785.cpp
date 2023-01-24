#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<string, bool, greater<string>> p;
	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name >> state;
		if (p.count(name)) {
			if (state == "enter") p[name] = true;
			else p[name] = false;
		}
		else {
			p.insert(make_pair(name, true));
		}
	}
	for (auto it = p.begin(); it != p.end(); it++) {
		if (it->second) cout << it->first.c_str() << "\n";
	}
}