import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. visited배열을 3차원 으로 선언해서 현재 (row, col)좌표를 말의 이동으로 몇 번 갔는지를 체크한다.
 * 2. 일반이동 dx, dy 외에도 말의 이동 dx, dy배열 horsedx, horsedy 8방을 저장한다.
 * 3. queue에 현재 row,column,말의 이동 횟수,총이동횟수를 저장한다.
 * 4. bfs를 돌면서 일반 4방 이동을 체크한다.
 * 5. 추가적으로 말의 8방 이동을 체크한다.
 * 	5-1. 말의 이동을 체크할 때는 이전 말의 이동 +1 해서 horseMove를 넘는지, 해당 row, col을 해당 횟수로 이동했는지를 추가적으로 체크한다.
 * 6. 오른쪽 끝으로 이동했다면 answer에 총 이동횟수를 저장하고 break
 * @author SSAFY
 *
 */
public class BOJ1600 {
	static int[][] zoo;
	//1. visited배열을 3차원 으로 선언해서 현재 (row, col)좌표를 말의 이동으로 몇 번 갔는지를 체크한다.
	static boolean[][][] visited;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	//2. 일반이동 dx, dy 외에도 말의 이동 dx, dy배열 horsedx, horsedy 8방을 저장한다.
	static int[] horsedx = {1, 1, -1, -1, 2, 2, -2, -2}, horsedy = {2, -2, 2, -2, 1, -1, 1, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int horseMove = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int colSize = Integer.parseInt(st.nextToken());
		int rowSize = Integer.parseInt(st.nextToken());
		zoo = new int[rowSize+1][colSize+1];
		visited = new boolean[rowSize+1][colSize+1][horseMove+1];

		for(int row = 1; row <= rowSize; row++) {
			st = new StringTokenizer(br.readLine());
			for(int col = 1; col <= colSize; col++) {
				zoo[row][col] = Integer.parseInt(st.nextToken());
			}
		}
		
		Queue<int[]> queue = new ArrayDeque<>();
		//3. queue에 현재 row,column,말의 이동 횟수,총이동횟수를 저장한다.
		queue.offer(new int[] {1, 1, 0, 0});
		visited[1][1][0] = true;
		int answer = -1;
		while(!queue.isEmpty()) {
			int[] front = queue.poll();
			//6. 오른쪽 끝으로 이동했다면 answer에 총 이동횟수를 저장하고 break
			if(front[0] == rowSize && front[1] == colSize) {
				answer = front[3];
				break;
			}
			//4. bfs를 돌면서 일반 4방 이동을 체크한다.
			for(int dir = 0; dir < 4; dir++) {
				int nxtRow = front[0] + dx[dir];
				int nxtCol = front[1] + dy[dir];
				if(nxtRow < 1 || nxtRow > rowSize || nxtCol < 1 || nxtCol > colSize ||
					zoo[nxtRow][nxtCol] == 1 ||	visited[nxtRow][nxtCol][front[2]]) continue;
				visited[nxtRow][nxtCol][front[2]] = true;
				queue.offer(new int[] {nxtRow, nxtCol, front[2], front[3]+1});
			}
			//5. 추가적으로 말의 8방 이동을 체크한다.
			for(int dir = 0; dir < 8; dir++) {
				int nxtRow = front[0] + horsedx[dir];
				int nxtCol = front[1] + horsedy[dir];
				//	5-1. 말의 이동을 체크할 때는 이전 말의 이동 +1 해서 horseMove를 넘는지, 해당 row, col을 해당 횟수로 이동했는지를 추가적으로 체크한다.
				if(nxtRow < 1 || nxtRow > rowSize || nxtCol < 1 || nxtCol > colSize || front[2]+1 > horseMove
					|| zoo[nxtRow][nxtCol] == 1 ||	visited[nxtRow][nxtCol][front[2]+1]) continue;
				visited[nxtRow][nxtCol][front[2]+1] = true;
				queue.offer(new int[] {nxtRow, nxtCol, front[2]+1, front[3]+1});
			}
		}
		System.out.println(answer);
	}
}