import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. BFS를 통해서 비버 굴로 이동하는 최단시간을 구하되, 해당 칸의 장애물, 물이 차는 시간을 고려해야 한다.
 * 2. 먼저 BFS로 해당 칸에 물이 차는 시간인 waterTime 배열을 채운다.
 * 	2-1. 맨 처음엔 큰 수로 초기화하며, *인 칸에는 0으로 채운다.
 * 	2-2. BFS를 돌면서 이때 X나 D면 채우지 않도록 한다.
 * 3. 이후 고슴도치의 이동 BFS를 돌린다. 이 때는 D가 있는 곳에 도착했을 때의 시간을 count하기 위해 queue에 시간을 같이 넣어준다.
 * 4. 범위를 벗어났거나, 방문한 칸이거나, X인 칸이거나, waterTime이 currenttime+1보다 작을 때 (물이 잠긴 후 도달하려고 할 때 )를 거르고 queue에 넣는다.
 * 5. D인 칸에 도착했을 때 answer를 저장하고 break;
 * @author SSAFY
 *
 */
public class BOJ3055 {
	static char[][] forest;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static boolean[][] visited;
	static int[][] waterTime;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int rowSize = Integer.parseInt(st.nextToken());
		int colSize = Integer.parseInt(st.nextToken());
		int startRow = -1, startCol = -1;
		forest = new char[rowSize+1][colSize+1];
		visited = new boolean[rowSize+1][colSize+1];
		waterTime = new int[rowSize+1][colSize+1];
		
		for(int row = 1; row <= rowSize; row++) {
			String str = br.readLine();
			for(int col = 1; col <= colSize; col++) {
				forest[row][col] = str.charAt(col-1);
				if(forest[row][col] == 'S') {
					startRow = row;
					startCol = col;
				}
			}
		}
		//waterTime 해당칸에 물이 몇분 후에 차는지 저장
		//2. 먼저 BFS로 해당 칸에 물이 차는 시간인 waterTime 배열을 채운다.
		Queue<int[]> waterq = new ArrayDeque<>();
		
		for(int row = 1; row <= rowSize; row++) {
			for(int col = 1; col <= colSize; col++) {
				//2-1. 맨 처음엔 큰 수로 초기화하며, *인 칸에는 0으로 채운다.
				if(forest[row][col] == '*') {
					waterTime[row][col] = 0;
					waterq.offer(new int[]{row, col});
				}
				else waterTime[row][col] = 10000;
			}
		}
		while(!waterq.isEmpty()) {
			int[] current = waterq.poll();
			
			for(int dir = 0; dir < 4; dir++) {
				int nxtRow = current[0] + dx[dir];
				int nxtCol = current[1] + dy[dir];
				//2-2. BFS를 돌면서 이때 X나 D면 채우지 않도록 한다.
				if(nxtRow < 1 || nxtRow > rowSize || nxtCol < 1 || nxtCol > colSize 
					|| waterTime[nxtRow][nxtCol] != 10000 || forest[nxtRow][nxtCol] == 'D' || forest[nxtRow][nxtCol] == 'X') continue;
				waterTime[nxtRow][nxtCol] = waterTime[current[0]][current[1]] + 1;
				waterq.offer(new int[] {nxtRow, nxtCol});
			}
		}

		//3. 이후 고슴도치의 이동 BFS를 돌린다. 이 때는 D가 있는 곳에 도착했을 때의 시간을 count하기 위해 queue에 시간을 같이 넣어준다.
		Queue<int[]> queue = new ArrayDeque<>();
		queue.offer(new int[] {startRow, startCol, 0});
		visited[startRow][startCol] = true;
		int answer = -1;
		while(!queue.isEmpty()) {
			int[] current = queue.poll();
			//5. D인 칸에 도착했을 때 answer를 저장하고 break;
			if(forest[current[0]][current[1]] == 'D') {
				answer = current[2];
				break;
			}
			for(int dir = 0; dir < 4; dir++) {
				int nxtRow = current[0] + dx[dir];
				int nxtCol = current[1] + dy[dir];
				// 4. 범위를 벗어났거나, 방문한 칸이거나, X인 칸이거나, waterTime이 currenttime+1보다 작을 때 (물이 잠긴 후 도달하려고 할 때 )를 거르고 queue에 넣는다.
				if(nxtRow < 1 || nxtRow > rowSize || nxtCol < 1 || nxtCol > colSize || waterTime[nxtRow][nxtCol] <= current[2]+1
						|| visited[nxtRow][nxtCol] || forest[nxtRow][nxtCol] == 'X') continue;
				visited[nxtRow][nxtCol] = true;
				queue.offer(new int[] {nxtRow, nxtCol, current[2]+1});
			}
		}
		if(answer != -1) System.out.println(answer);
		else System.out.println("KAKTUS");
	}
}