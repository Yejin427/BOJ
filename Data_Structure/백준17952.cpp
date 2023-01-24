#include<iostream>
#include<stack>
using namespace std;
struct hw {
	int score, minute;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<hw> s;
	int n,ans=0; 
	cin >> n;
	while (n--) {
		int input; cin >> input;
		if (input == 1) {
			struct hw H;
			cin >> H.score >> H.minute;
			H.minute--;
			if (H.minute) s.push(H);
			else ans += H.score;
		}
		else {
			if (!s.empty()) {
				if (s.top().minute) s.top().minute--;
				if (s.top().minute == 0) {
					struct hw front = s.top();
					s.pop();
					ans += front.score;
				}
			}
		}
	}
	cout << ans;
}