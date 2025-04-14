import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 맨홀 현재위치로부터 bfs로 이동하면서 제한시간까지 이동한다.
 * 2. initPipe함수 : 파이프 번호마다 사방 중 dx, dy 방향index에 맞춰서 뚫린 곳을 true로 저장한다.
 * 3. isLinked함수 : 현재 pipe번호, 다음 pipe번호, 연결 확인 방향을 매개변수로 넘겨받아서 pipedirection[현재pipe][dir] pipedirection[다음pipe][반대dir]이 모두 true인지 확인
 * 4. bfs를 돌면서 확인하려는 다음 칸이 범위를 넘어가는지, 이미 방문했는지, 연결되어있는지 확인하고 만족하면 queue에 넣어준다.
 * 5. visited배열에 이전 pipe 시간 + 1로 저장해준다.
 * 6. 방문할때마다 value를 추가해주고, front의 time이 이동시간과 같다면 더 탐색하지 않는다.
 * @author SSAFY
 *
 */
public class SWEA1953 {
	static int rowSize, colSize;
	static int[][] basementMap;
	static int[][] visited;
	static boolean[][] pipedirection;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		initPipe();
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			rowSize = Integer.parseInt(st.nextToken());
			colSize = Integer.parseInt(st.nextToken());
			int manholeRow = Integer.parseInt(st.nextToken());
			int manholeCol = Integer.parseInt(st.nextToken());
			int time = Integer.parseInt(st.nextToken());
			basementMap = new int[rowSize+1][colSize+1];
			visited = new int[rowSize+1][colSize+1];
			for(int row = 1; row <= rowSize; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= colSize; col++) {
					basementMap[row][col] = Integer.parseInt(st.nextToken());
				}
			}

			System.out.printf("#%d %d\n", test, bfs(manholeRow+1, manholeCol+1, time));
		}
	}
	static int bfs(int row, int col, int time) {
		Queue<int[]> queue = new ArrayDeque<>();
		visited[row][col] = 1;
		queue.offer(new int[] {row, col, 1});
		int value = 0;
		while(!queue.isEmpty()) {
			int[] front = queue.poll();
			//6. 방문할때마다 value를 추가해주고, front의 time이 이동시간과 같다면 더 탐색하지 않는다.
			value++;
			if(front[2] == time) continue;
			for(int dir = 0; dir < 4; dir++) {
				int nxtRow = front[0] + dx[dir], nxtCol = front[1] + dy[dir];
				//4. bfs를 돌면서 확인하려는 다음 칸이 범위를 넘어가는지, 이미 방문했는지, 연결되어있는지 확인하고 만족하면 queue에 넣어준다.
				if(nxtRow < 1 || nxtRow > rowSize || nxtCol < 1 || nxtCol > colSize
						|| visited[nxtRow][nxtCol] != 0 || !isLinked(basementMap[front[0]][front[1]], basementMap[nxtRow][nxtCol], dir))
					continue;
				//5. visited배열에 이전 pipe 시간 + 1로 저장해준다.
				visited[nxtRow][nxtCol] = front[2]+1;
				queue.add(new int[] {nxtRow, nxtCol, front[2]+1});
			}
		}
		return value;
	}
	//3. isLinked함수 : 현재 pipe번호, 다음 pipe번호, 연결 확인 방향을 매개변수로 넘겨받아서 pipedirection[현재pipe][dir] pipedirection[다음pipe][반대dir]이 모두 true인지 확인
	static boolean isLinked(int curType, int nextType, int direction) {
//		System.out.println("curtype: "+curType+" nxtType: "+nextType+" direction: "+direction);
		return pipedirection[curType][direction] && pipedirection[nextType][direction ^ 2];
	}
	//2. initPipe함수 : 파이프 번호마다 사방 중 dx, dy 방향index에 맞춰서 뚫린 곳을 true로 저장한다.
	static void initPipe() {
		pipedirection = new boolean[8][4];
		pipedirection[1][0] = true;
		pipedirection[1][1] = true;
		pipedirection[1][2] = true;
		pipedirection[1][3] = true;
		pipedirection[2][0] = true;
		pipedirection[2][2] = true;
		pipedirection[3][1] = true;
		pipedirection[3][3] = true;
		pipedirection[4][0] = true;
		pipedirection[4][3] = true;
		pipedirection[5][2] = true;
		pipedirection[5][3] = true;
		pipedirection[6][1] = true;
		pipedirection[6][2] = true;
		pipedirection[7][0] = true;
		pipedirection[7][1] = true;
	}
}