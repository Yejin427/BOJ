#include<stdio.h>
char word[82];
int number(char x[80]) {
	int cnt = 0, ans = 0;
	if (x[0] == 'O') {
		ans++;
		cnt++;
	}
	for (int i = 1; x[i] != 0; i++) {
		if (x[i - 1] == 'O' && x[i] == 'O') {
			cnt += 1;
			ans += cnt;
		}
		else if (x[i - 1] == 'X' && x[i] == 'O') {
			cnt = 1;
			ans += cnt;
		}
	}
	return ans;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &word);
		printf("%d\n", number(word));
	}
	return 0;
}
