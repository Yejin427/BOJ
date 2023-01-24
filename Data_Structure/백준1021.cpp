#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;
int main() {
	int count = 0;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		int index;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				index = i;
				break;
			}
		}
		if (index < dq.size() - index) {//수가 전체의 절반 이하일 때
			while(1) {
				if (dq.front() == num) {
					dq.pop_front();//맨앞에 수가 입력한 수면 뺌
					break;
				}
				count++;
				dq.push_back(dq.front());
				dq.pop_front();//왼쪽으로 한칸 이동
			}
		}
		else {//수가 전체의 절반 이상일때
			while(1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				count++;
				dq.push_front(dq.back());
				dq.pop_back();//오른쪽으로 한칸 이동
			}
		}
	}
	cout << count;
}