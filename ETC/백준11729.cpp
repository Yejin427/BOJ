#include<stdio.h>
int k;//원판 옮긴 횟수
void hanoi(int n) {
	if (n == 1) {
		k++;
		return;
	}
	hanoi(n - 1);
	k++;
	hanoi(n - 1);
}
void hanoi2(int n, int from, int to, int by) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi2(n - 1, from, by, to);//출발 기둥의 원판 n-1개를 경유 기둥으로 옮기고
	printf("%d %d\n", from, to);//마지막 원판을 목적지 기둥으로 옮김
	hanoi2(n - 1, by, to, from);//경유 기둥에 쌓여있는 원판 n-1개를 목적지 기둥으로 이동
}
int main() {
	int N;
	scanf("%d", &N);
	if (N <= 20) {
		hanoi(N);
		printf("%d\n", k);
		//N개의 원판을 1번에서 3번으로 옮기는 과정 출력
		hanoi2(N, 1, 3, 2);
	}
	else {
		hanoi(N);
		printf("%d", k);
	}
}