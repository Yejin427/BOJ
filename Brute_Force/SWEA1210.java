import java.util.Scanner;

public class SWEA1210 {
	/**
	 * dx, dy 배열 : /0번 index: 아래 이동, 1번 index: 오른쪽 이동, 2번 index: 왼쪽 이동
	 * ladder : 입력받을 사다리 (1~100 index를 사용하기 위해 101개 할당)
	 * 사다리의 열을 순회하면서 (1, col)이 1일 때 사다리를 타고 내려가는 로직 수행 -> 도착지점의 사다리가 2인지 확인 -> 맞으면 탐색 종료
	 */
	static int dx[] = {1, 0, 0}, dy[] = {0, 1, -1};	//0번 index: 아래 이동, 1번 index: 오른쪽 이동, 2번 index: 왼쪽 이동
	static int[][] ladder = new int[101][101];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int t = 1; t <= 10; t++) {
			//현재 test 번호를 입력받음
			int test = sc.nextInt();
			//100x100의 사다리 정보를 입력받음
			for(int row=1;row<=100;row++) {
				for(int col=1;col<=100;col++) {
					ladder[row][col] = sc.nextInt();
				}
			}
			
			int ansCol = -1;
			//현재 column에서 시작했을 때 어디 바닥으로 떨어지는지
			for(int col = 1; col <= 100; col++) {
				int curRow = 1, curCol = col;	//(1, col)에서 시작함
				if(ladder[curRow][curCol] == 0) continue;	//맨 위에 사다리가 없다면 continue;
				//맨 밑으로 내려갈 때까지 탐색함
				while(curRow < 100) {
					int goDir = 0;
					if(curCol > 1 && ladder[curRow][curCol-1] == 1) {
						goDir = 2;
					}
					if(curCol < 99 && ladder[curRow][curCol+1] == 1) {
						goDir = 1;
					}
					curRow = curRow + dx[goDir];
					curCol = curCol + dy[goDir];
					if(goDir != 0) {	//좌우로 이동
						//좌, 우로 이동해야함 -> 0이 아닐때까지 이동함
						while(1 <= curCol && curCol <= 100 && ladder[curRow][curCol] == 1) {
							curCol += dy[goDir];
						}
						curCol -= dy[goDir];
						//한 칸 밑으로 내려감 -> 계속 좌우로 왔다갔다하는 것을 방지함
						if(curRow <= 99) curRow++;
					}
				}
				//맨 밑으로 내려왔을 때 사다리가 2가 된다면 정답 기록 -> 탐색 종료
				if(ladder[curRow][curCol] == 2) {
					ansCol = col;
					break;
				}
			}
			System.out.printf("#%d %d\n", t, ansCol-1);
		}
	}
}