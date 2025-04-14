import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 먼저 initBlock을 통해서 block 번호에 뚫려있는 곳을 true로 초기화
 * 2. 핀볼 맵을 돌면서 map 배열이 0인 곳에서 direction을 0~3까지 시작해보며 시뮬레이션 진행
 * 	2-1. count 변수를 0으로 초기화하고 go 함수 내에서 벽이나 블록에 부딪혔을 때 +1
 * 	2-2. 만약 블랙홀에 부딪혔다면 시뮬레이션 종료, 시작점에 도착했다면 종료
 * 	2-3. go 함수 : (startRow, startCol)을 받아서 curRow, curCol과 같아지면 go함수 break;
 * 		2-3-1. 빈 공간이 아니거나, 시작점에 도착했거나, 범위 내에 있을 때까지 핀볼 이동
 * 		2-3-2. 만약 벽에 도착했다면 ? curDir의 반대방향으로 한칸 back 후 방향을 반대로 바꿔줌 
 * 		2-3-3. 블록에 도착했다면? : 만약 blockOpen이 막혀있는 곳에 도착했다면 한 칸 back 후 방향 반대, blockOpen이 열려있다면 온 곳 말고 뚫려있는 다른 곳으로 이동, 방향 변환
 * 		2-3-4. 웜홀에 도착했다면? : curRow, curCol을 다른 웜홀 + 한 칸 이동한 곳으로 초기화 (무한루프 방지)
 * 3. count의 최댓값을 answer에 계속 update
 * @author SSAFY
 *
 */
public class SWEA5650 {
	static int[][] map;
	static boolean[][] blockOpen;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static int curRow, curCol, curDir, size, answer, count;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		
		int testCase = Integer.parseInt(st.nextToken());
		//1. 먼저 initBlock을 통해서 block 번호에 뚫려있는 곳을 true로 초기화
		initBlock();
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			size = Integer.parseInt(st.nextToken());
			map = new int[size+1][size+1];
			for(int row = 1; row <= size; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= size; col++) {
					map[row][col] = Integer.parseInt(st.nextToken());
				}
			}
			answer = 0;
			//2. 핀볼 맵을 돌면서 map 배열이 0인 곳에서 direction을 0~3까지 시작해보며 시뮬레이션 진행
			for(int startRow = 1; startRow <= size; startRow++) {
				for(int startCol = 1; startCol <= size; startCol++) {
					if(map[startRow][startCol] == 0) {
						for(int startDir = 0; startDir < 4; startDir++) {
							//2-1. count 변수를 0으로 초기화하고 go 함수 내에서 벽이나 블록에 부딪혔을 때 +1
							count = 0;
							curRow = startRow; curCol = startCol; curDir = startDir;
							while(true) {
								//2-2. 만약 블랙홀에 부딪혔다면 시뮬레이션 종료, 시작점에 도착했다면 종료
								if(1 <= curRow && curRow <= size && 1 <= curCol && curCol <= size && map[curRow][curCol] == -1) break;
								go(startRow, startCol);
								if(curRow == startRow && curCol == startCol) break;
							}
							//3. count의 최댓값을 answer에 계속 update
							answer = Math.max(answer, count);
						}
					}
				}
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	//2-3. go 함수 : (startRow, startCol)을 받아서 curRow, curCol과 같아지면 go함수 break;
	static void go(int startRow, int startCol) {
		//2-3-1. 빈 공간이 아니거나, 시작점에 도착했거나, 범위 내에 있을 때까지 핀볼 이동
		while(1 <= curRow && curRow <= size && 1 <= curCol && curCol <= size && map[curRow][curCol] == 0) {
			curRow += dx[curDir];
			curCol += dy[curDir];
			if(curRow == startRow && curCol == startCol) break;
		}
		//2-3-2. 만약 벽에 도착했다면 ? curDir의 반대방향으로 한칸 back 후 방향을 반대로 바꿔줌 
		if(curRow < 1 || curRow > size || curCol < 1 || curCol > size) {
			curRow -= dx[curDir];
			curCol -= dy[curDir];
			curDir ^= 2;
			count++;
		}
		//2-3-4. 웜홀에 도착했다면? : curRow, curCol을 다른 웜홀 + 한 칸 이동한 곳으로 초기화 (무한루프 방지)
		else if(map[curRow][curCol] >= 6) {
			for(int row = 1; row <= size; row++) {
				for(int col = 1; col <= size; col++) {
					if(!(curRow == row && curCol == col) && map[curRow][curCol] == map[row][col]) {
						curRow = row + dx[curDir]; curCol = col + dy[curDir];
						return;
					}
				}
			}
		}
		//2-3-3. 블록에 도착했다면? : 만약 blockOpen이 막혀있는 곳에 도착했다면 한 칸 back 후 방향 반대, blockOpen이 열려있다면 온 곳 말고 뚫려있는 다른 곳으로 이동, 방향 변환
		else if(map[curRow][curCol] >= 1) {
			if(!blockOpen[map[curRow][curCol]][curDir ^ 2]) {
				curRow -= dx[curDir];
				curCol -= dy[curDir];
				curDir ^= 2;
			} else {
				for(int direction = 0; direction < 4; direction++) {
					if(blockOpen[map[curRow][curCol]][direction] && direction != (curDir ^ 2)) {
						curRow += dx[direction];
						curCol += dy[direction];
						curDir = direction;
						break;
					}
				}
			}
			count++;
		}
	}
	static void initBlock() {
		blockOpen = new boolean[6][4];
		for(int blockIdx = 1; blockIdx <= 4; blockIdx++) {
			blockOpen[blockIdx][blockIdx-1] = true;
			blockOpen[blockIdx][blockIdx % 4] = true;
		}
	}
}