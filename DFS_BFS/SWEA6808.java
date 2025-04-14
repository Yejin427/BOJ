import java.util.Scanner;

public class SWEA6808 {
	/**
	 * kyuyoungcard[] : 입력받을 규영 소지 카드
	 * cardUsed[] : 재귀를 돌리면서 사용한 카드 체크 배열
	 * kyuyoungWin : 규영이가 이기는 경우의 수, inyoungWin : 인영이가 이기는 경우의 수
	 * idx를 증가시키면서 게임을 진행하며 점수 계산 
	 * -> 9번의 결과가 끝났을 때 kyuyoungScore, inyoungScore을 비교하고 win을 1씩 추가해줌
	 */
	static int kyuyoungcard[] = new int[10];
	//재귀를 돌리면서 사용한 카드를 체크하는 배열
	static boolean cardUsed[] = new boolean[20];
	//각각 규영, 인영이가 이기는 경우의 수
	static int kyuyoungWin = 0, inyoungWin = 0;
	//인자로 현재 차례, 현재 규영, 인영이의 score을 넘겨준다.
	static void game(int idx, int kyuyoungScore, int inyoungScore) {
		//기저조건
		if(idx == 9) {
			if(kyuyoungScore < inyoungScore) inyoungWin++;
			else if(kyuyoungScore > inyoungScore) kyuyoungWin++;
		}
		for(int c = 1; c <= 18; c++) {
			if(cardUsed[c]) continue;
			cardUsed[c] = true;
			if(c < kyuyoungcard[idx+1]) {
				game(idx+1, kyuyoungScore + c + kyuyoungcard[idx+1], inyoungScore);
			} else {
				game(idx+1, kyuyoungScore, inyoungScore + c + kyuyoungcard[idx+1]);
			}
			cardUsed[c] = false;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int test = 1; test <= t; test++) {
			for(int c = 1; c <= 9; c++) {
				kyuyoungcard[c] = sc.nextInt();
				//규영이가 갖고 있는 카드는 애초에 쓸 수 없으므로 cardUsed를 true로 해준다.
				cardUsed[kyuyoungcard[c]] = true;
			}
			game(0, 0, 0);
			System.out.printf("#%d %d %d\n", test, kyuyoungWin, inyoungWin);
			//다음 테케를 위해 배열과 변수를 초기화한다.
			for(int i=1;i<=18;i++) {
				cardUsed[i] = false;
			}
			kyuyoungWin = 0;
			inyoungWin = 0;
		}
	}
}