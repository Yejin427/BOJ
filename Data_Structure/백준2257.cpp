#include<stdio.h>
char chemi[105];//�Է� �޴� ȭ�н� �迭
int i;

int sol() {//��ȣ ������ ȭ�нķ� ���
	int m = 0;

	while (1) {//�ݺ������� chemi[i]�� ���캻��. while�� �ۿ��� return m
		if (chemi[i] == 0) break;
		if (chemi[i] == '(') {//���� ��ȣ ������
			i++;//��ȣ ���� �ε����� �̵�
			m += sol();//��� ȣ�� ��ݸ��� ��ȣ�� ȭ�нķ��� ���ؿͼ� ���Ѵ�.
		}
		if (chemi[i] == ')') {
			i++;
			if ('0' < chemi[i] && chemi[i] <= '9') {
				m = m * (chemi[i] - '0');
				i++;
			}//��ȣ ���� ���ڰ� �ֵ� ���� m�� ��ȣ�� �� ȭ�нķ��� ������ �̝���
			return m;//���ݱ����� ������ �����Ѵ�.
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