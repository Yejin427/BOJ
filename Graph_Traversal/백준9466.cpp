#include<iostream>
#include<cstring>
#include<vector>
int arr[100001];//i번째 학생의 선택한 학생 arr[i]
bool visited[100001];//방문하는 노드들을 저장해줘서 나왔던 노드가 다시 나오면 탐색을 멈춰줌
int cycle[100001];//0 : 아직 결정되지 않음 1 : cycle가능 -1 : cycle불가능
std::vector<int> v;//노드의 경로를 저장해줌
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> arr[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cycle[i] != 0) continue;//정해졌을때는 pass
			int next = arr[i];
			v.push_back(i);
			while (true) {
				if (cycle[next] != 0) {//가다가 중간에 확정된 노드가 있다면
					for (int i = 0; i < v.size(); i++) cycle[v[i]] = -1;//그 경로 모두 사이클 불가
					v.clear();//경로탐색이 끝날때마다 vector을 지워줌
					break;
				}
				v.push_back(next);
				if (i == next) {//첨부터 사이클인 경로 찾음
					for (int i = 0; i < v.size() - 1; i++) {
						cycle[v[i]] = 1;//모두 사이클 가능
					}
					v.clear();
					break;
				}
				if (visited[next]) {//가다가 중간에 사이클
					for (int i = 0; i < v.size() - 1; i++) {
						if (v[i] == next) {
							for (int j = i; j < v.size() - 1; j++) {
								cycle[v[j]] = 1;
							}
							break;
						}
						else cycle[v[i]] = -1;
					}
					v.clear();
					break;
				}
				visited[next] = true;
				next = arr[next];
			}
		}
		for (int i = 1; i <= n; i++) {
			if (cycle[i] == -1) {
				ans++;
			}
		}
		std::cout << ans << '\n';
		memset(cycle, 0, sizeof(cycle));
		memset(visited, false, sizeof(visited));
	}
}