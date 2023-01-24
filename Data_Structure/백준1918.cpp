#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
char word[102];
stack<char> s;
int main() {
	cin >> word;
	string ans = "";
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			ans += word[i];
		}
		else if (word[i] == '(') {
			s.push(word[i]);
		}
		else if (word[i] == '*' || word[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				ans += s.top();
				s.pop();
			}
			s.push(word[i]);
		}
		else if (word[i] == '+' || word[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				ans += s.top();
				s.pop();
			}
			s.push(word[i]);
		}
		else if (word[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				ans += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}