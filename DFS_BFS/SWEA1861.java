import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 정사각형 방을 dfs로 갈 수 없는 곳을 미리 가지치고 다음 재귀를 돌린다.
 * 	1-1. dx, dy 배열을 통해 현재 칸의 4방을 보면서 범위 내에 있고, currentNumber보다 다음 방의 room값이 1더 크면 다음 재귀를 호출한다.
 * 	1-2. canMove 변수를 놓고 더 이상 움직일 수 없다면 currentRoomNum을 update한다.
 * 2. 만약 maxRoomNum(최대 방의 개수)와 비교해서 currentRoomNum 더 크면 maxRoomNum과 answerRow, answerCol을 update 한다.
 * 3. 만약 maxRoomNum == currentRoomNum -> 문제 조건에 따라 room number가 더 작으면 answerRow, answerCol을 update해준다.
 * @author SSAFY
 *
 */
public class SWEA1861 {
	static int[][] room;
	static int maxRoomNum, currentRoomNum;
	static int answerRow, answerCol;
	static int roomSize;
	static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			roomSize = Integer.parseInt(st.nextToken());
			room = new int[roomSize+1][roomSize+1];
			maxRoomNum = 0;
			for(int row = 1; row <= roomSize; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= roomSize; col++) {
					room[row][col] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int row = 1; row <= roomSize; row++) {
				for(int col = 1; col <= roomSize; col++) {
					currentRoomNum = 0;
					move(row, col, room[row][col], 1);
					//2. 만약 maxRoomNum(최대 방의 개수)와 비교해서 currentRoomNum 더 크면 maxRoomNum과 answerRow, answerCol을 update 한다.
					if(maxRoomNum < currentRoomNum) {
						maxRoomNum = currentRoomNum;
						answerRow = row; 
						answerCol = col;
					}
					//3. 만약 maxRoomNum == currentRoomNum -> 문제 조건에 따라 room number가 더 작으면 answerRow, answerCol을 update해준다.
					else if(maxRoomNum == currentRoomNum) {
						if(room[row][col] < room[answerRow][answerCol]) {
							answerRow = row; 
							answerCol = col;
						}
					}
				}
			}
			System.out.printf("#%d %d %d\n", test, room[answerRow][answerCol], maxRoomNum);
		}
	}
	
	//1. 정사각형 방을 dfs로 갈 수 없는 곳을 미리 가지치고 다음 재귀를 돌린다.
	static void move(int startRow, int startCol, int currentNumber, int roomCount) {
//		System.out.printf("%d %d %d %d\n", startRow, startCol, currentNumber, roomCount);
		boolean canMove = false;
		//1-1. dx, dy 배열을 통해 현재 칸의 4방을 보면서 범위 내에 있고, currentNumber보다 다음 방의 room값이 1더 크면 다음 재귀를 호출한다.
		for(int direction = 0; direction < 4; direction++) {
			int nxtRow = startRow + dx[direction];
			int nxtCol = startCol + dy[direction];
			if(nxtRow < 1 || nxtRow > roomSize || nxtCol < 1 || nxtCol > roomSize) continue;
			if(room[nxtRow][nxtCol] == currentNumber + 1) {
				canMove = true;
				move(nxtRow, nxtCol, currentNumber + 1, roomCount + 1);
			}
		}
		//1-2. canMove 변수를 놓고 더 이상 움직일 수 없다면 currentRoomNum을 update한다.
		if(!canMove) {
			currentRoomNum = Math.max(roomCount, currentRoomNum);
		}
	}
}