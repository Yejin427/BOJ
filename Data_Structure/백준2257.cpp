#include<stdio.h>
char chemi[105];//입력 받는 화학식 배열
int i;

int sol() {//괄호 단위로 화학식량 계산
	int m = 0;

	while (1) {//반복문으로 chemi[i]를 살펴본다. while문 밖에서 return m
		if (chemi[i] == 0) break;
		if (chemi[i] == '(') {//여는 괄호 만나면
			i++;//괄호 다음 인덱스로 이동
			m += sol();//재귀 호출 방금만난 괄호의 화학식량을 구해와서 더한다.
		}
		if (chemi[i] == ')') {
			i++;
			if ('0' < chemi[i] && chemi[i] <= '9') {
				m = m * (chemi[i] - '0');
				i++;
			}//괄호 옆에 숫자가 있든 없든 m은 괄호의 총 화학식량을 가지고 이씅ㅁ
			return m;//지금까지의 질량을 리턴한다.
		}
		if (chemi[i] == 'C') {
			i++;
			if ('0' < chemi[i] && chemi[i] < '9') {
				m += 12 * (chemi[i] - '0');
				i++;
			}
			else m += 12;
		}
		else if (chemi[i] == 'H') {
			i++;
			if ('0' < chemi[i] && chemi[i] <= '9') {
				m += 1 * (chemi[i] - '0');
				i++;
			}
			else m += 1;
		}
		else if (chemi[i] == 'O') {
			i++;
			if ('0' < chemi[i] && chemi[i] <= '9') {
				m += 16 * (chemi[i] - '0');
				i++;
			}
			else m += 16;
		}
	}
	return m;
}
int main() {
	scanf("%s", chemi);
	printf("%d", sol());
}