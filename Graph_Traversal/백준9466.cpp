#include<iostream>
#include<cstring>
#include<vector>
int arr[100001];//i��° �л��� ������ �л� arr[i]
bool visited[100001];//�湮�ϴ� ������ �������༭ ���Դ� ��尡 �ٽ� ������ Ž���� ������
int cycle[100001];//0 : ���� �������� ���� 1 : cycle���� -1 : cycle�Ұ���
std::vector<int> v;//����� ��θ� ��������
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
			if (cycle[i] != 0) continue;//������������ pass
			int next = arr[i];
			v.push_back(i);
			while (true) {
				if (cycle[next] != 0) {//���ٰ� �߰��� Ȯ���� ��尡 �ִٸ�
					for (int i = 0; i < v.size(); i++) cycle[v[i]] = -1;//�� ��� ��� ����Ŭ �Ұ�
					v.clear();//���Ž���� ���������� vector�� ������
					break;
				}
				v.push_back(next);
				if (i == next) {//÷���� ����Ŭ�� ��� ã��
					for (int i = 0; i < v.size() - 1; i++) {
						cycle[v[i]] = 1;//��� ����Ŭ ����
					}
					v.clear();
					break;
				}
				if (visited[next]) {//���ٰ� �߰��� ����Ŭ
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