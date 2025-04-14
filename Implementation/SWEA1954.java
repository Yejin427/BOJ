import java.util.Scanner;
/**
 * 1. 달팽이는 오른쪽, 아래, 왼쪽, 위의 순서로 순회함. 이에 맞춰 dx, dy배열 생성
 * 	1-1. dx, dy의 0, 1, 2, 3 index로 생성함.
 * 2. currentRow, currentColumn을 (1,1)부터 시작해서 update 해줄것임
 * 3. num을 1부터 n*n까지 순회하면서 currentDirection만큼 이동시키면서 snail배열을 채움
 * 4. 만약 해당 방향으로 더이상 갈 수 없다면(snail의 범위를 지났거나, 해당 칸을 지나쳤다면)
 * 5. currentDirection을 1 증가해줌  (3다음 0번 방향을 지정하기 위해 % 4를 해줌)
 * @author SSAFY
 *
 */
public class SWEA1954 {
	static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	static int snail[][] = new int[11][11];	//달팽이 출력 배열
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int test = 1; test <= t; test++) {
			int snailSize = sc.nextInt();
			//현재 행과 열을 저장하는 변수. (1,1)부터 시작할 것임.
			int currentRow = 1, currentColumn = 1;
			int currentDirection = 0;	//현재 방향 index 저장 변수, 0, 1, 2, 3을 반복할 것임.
			
			for(int num = 1; num <= snailSize*snailSize; num++) {
				snail[currentRow][currentColumn] = num;
				int nextRow = currentRow + dx[currentDirection];
				int nextColumn = currentColumn + dy[currentDirection];
				//현재 방향으로 한 칸 더 간 달팽이 위치가 1~n의 범위 내에 존재하고, 해당 칸을 지나가지 않았다면
				if(1 <= nextRow && nextRow <= snailSize && 1 <= nextColumn && nextColumn <= snailSize && snail[nextRow][nextColumn] == 0) {
					currentRow = nextRow;
					currentColumn = nextColumn;
				} else {
					//그렇지 않다면 다음 방향으로 전환함 (3다음 0번 방향을 지정하기 위해 % 4를 해줌)
					currentDirection = (currentDirection + 1) % 4;
					currentRow += dx[currentDirection];
					currentColumn += dy[currentDirection];
				}
			}
			System.out.printf("#%d\n", test);
			for(int row = 1; row <= snailSize; row++) {
				for(int col = 1; col <= snailSize; col++) {
					System.out.printf("%d ", snail[row][col]);
				}
				System.out.println();
			}
			//다음 테케를 위해 snail 배열 초기화
			for(int row = 1; row <= n; row++) {
				for(int col = 1; col <= n; col++) {
					snail[row][col] = 0;
				}
			}
		}
	}
}