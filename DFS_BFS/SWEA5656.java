import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 벽돌 깨는 위치의 array(shootPos)를 shootNum만큼 저장하고 이후 벽돌을 깨는 시뮬레이션을 진행
 * 2. simulation 함수 : shootPos대로 벽돌을 깨면서 깨지는 벽돌의 수를 리턴함.
 * 	2-1. 처음에 copyBlockMap으로 blockMap 복사. blockMap은 변하지 않아야 하기 때문.
 * 	2-2. shootPos에 저장한 column으로 구슬을 내렸을 때 구슬이 닿는 위치를 구함 (currentRow)
 * 	2-3. currentRow가 있다면 현 위치에서 깨지는 개수 breakBlock만큼 더함.
 * 	2-4. 이후 블럭을 밑으로 내림.
 * 		2-4-1. 큐에 끝에서부터 1이 아닌 블럭을 저장하고 이후에 끝에서부터 queue에서 뽑으면서 copyBlockMap을 초기화
 * 		2-4-2. 큐가 비었다면 나머지는 0으로 채움
 * 3. breakBlock(rowPos, colPos) 함수 : 현재 위치(rowPos, colPos)에 구슬이 닿았을 때 연쇄적으로 깨지는 블럭의 개수
 * 	3-1. 블럭값이 0이라면 그냥 0리턴
 * 	3-2. 아니면 현재 블럭 값을 0으로 바꾸고 이전의 블럭값만큼 사방에서 breakBlock을 재호출하면서 더해준다.
 * @author SSAFY
 *
 */
public class SWEA5656 {
	static int[][] blockMap, copyBlockMap;
	static int shootNum, width, height, answer;
	static int[] shootPos;
	static int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			shootNum = Integer.parseInt(st.nextToken());
			width = Integer.parseInt(st.nextToken());
			height = Integer.parseInt(st.nextToken());
			
			blockMap = new int[height+1][width+1];
			copyBlockMap = new int[height+1][width+1];
			shootPos = new int[shootNum];
			answer = 0;
			int sumBlock = 0;
			for(int row = 1; row <= height; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= width; col++) {
					blockMap[row][col] = Integer.parseInt(st.nextToken());
					if(blockMap[row][col] != 0) sumBlock++;
				}
			}
			dfs(0);
			simulation();
			System.out.printf("#%d %d\n", test, sumBlock-answer);
		}
	}
	//1. 벽돌 깨는 위치의 array(shootPos)를 shootNum만큼 저장하고 이후 벽돌을 깨는 시뮬레이션을 진행
	static void dfs(int depth) {
		if(depth == shootNum) {
			answer = Math.max(answer, simulation());
			return;
		}
		for(int col = 1; col <= width; col++) {
			shootPos[depth] = col;
			dfs(depth+1);
		}
	}
	//2. simulation 함수 : shootPos대로 벽돌을 깨면서 깨지는 벽돌의 수를 리턴함.
	static int simulation() {
		//2-1. 처음에 copyBlockMap으로 blockMap 복사. blockMap은 변하지 않아야 하기 때문.
		for(int row = 1; row <= height; row++) {
			for(int col = 1; col <= width; col++) {
				copyBlockMap[row][col] = blockMap[row][col];
			}
		}
		int count = 0;
		for(int index = 0; index < shootNum; index++) {
			int shootCol = shootPos[index];
			int currentRow = -1, currentCol = shootCol;
			//2-2. shootPos에 저장한 column으로 구슬을 내렸을 때 구슬이 닿는 위치를 구함 (currentRow)
			for(int row = 1; row <= height; row++) {
				if(copyBlockMap[row][shootCol] > 0) {
					currentRow = row;
					break;
				}
			}
			if(currentRow != -1) {
				//2-3. currentRow가 있다면 현 위치에서 깨지는 개수 breakBlock만큼 더함.
				count += breakBlock(currentRow, currentCol);
				//2-4. 이후 블럭을 밑으로 내림.
				for(int col = 1; col <= width; col++) {
					//2-4-1. 큐에 끝에서부터 1이 아닌 블럭을 저장하고 이후에 끝에서부터 queue에서 뽑으면서 copyBlockMap을 초기화
					Queue<Integer> queue = new ArrayDeque<>();
					for(int row = height; row >= 1; row--) {
						if(copyBlockMap[row][col] != 0) {
							queue.offer(copyBlockMap[row][col]);
						}
					}
					for(int row = height; row >= 1; row--) {
						if(!queue.isEmpty()) {
							copyBlockMap[row][col] = queue.poll();
						}
						else {//2-4-2. 큐가 비었다면 나머지는 0으로 채움
							copyBlockMap[row][col] = 0;
						}
					}
				}
			}
		}
		return count;
	}
	//3. breakBlock(rowPos, colPos) 함수 : 현재 위치(rowPos, colPos)에 구슬이 닿았을 때 연쇄적으로 깨지는 블럭의 개수
	static int breakBlock(int rowPos, int colPos) {
		//3-1. 블럭값이 0이라면 그냥 0리턴
		if(copyBlockMap[rowPos][colPos] == 0) return 0;
		int count = 1;
		int value = copyBlockMap[rowPos][colPos];
		copyBlockMap[rowPos][colPos] = 0;
		//3-2. 아니면 현재 블럭 값을 0으로 바꾸고 이전의 블럭값만큼 사방에서 breakBlock을 재호출하면서 더해준다.
		for(int cnt = 1; cnt < value; cnt++) {
			for(int dir = 0; dir < 4; dir++) {
				int nxtRow = rowPos + dx[dir] * cnt, nxtCol = colPos + dy[dir] * cnt;
				if(nxtRow < 1 || nxtRow > height || nxtCol < 1 || nxtCol > width) continue;
				count += breakBlock(nxtRow, nxtCol);
			}
		}
		return count;
	}
}