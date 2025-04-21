import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. dfs를 통해 파이프의 오른쪽 끝점 움직이면서 (n,n)에 다다르면 answer를 추가해준다.
 * 2. direction: 0(가로) 1(세로) 2(대각선)
 * 3. 처음엔 가로방향에 파이프 오른쪽 끝점이 (1,2)이므로 dfs(0, 1, 2) 호출
 * 4. direction을 가로-> 세로, 세로 -> 가로는 안되므로 continue
 * 5. nxtRow, nxtCol이 범위를 벗어나거나 끝 점에 pipeMap이 존재한다면 continue
 * 6. 대각선 방향이라면 그 왼쪽과 위 방향을 추가로 확인해서 pipeMap이 존재하면 continue
 * @author SSAFY
 *
 */
public class BOJ17070 {
	static int[][] pipeMap;
	static int size, answer;
	//2. direction: 0(가로) 1(세로) 2(대각선)
	static int[] dx = {0, 1, 1}, dy = {1, 0, 1};
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		size = Integer.parseInt(br.readLine());
		pipeMap = new int[size+1][size+1];
		for(int row = 1; row <= size; row++) {
			st = new StringTokenizer(br.readLine());
			for(int col = 1; col <= size; col++) {
				pipeMap[row][col] = Integer.parseInt(st.nextToken());
			}
		}
		//3. 처음엔 가로방향에 파이프 오른쪽 끝점이 (1,2)이므로 dfs(0, 1, 2) 호출
		dfs(0, 1, 2);
		System.out.println(answer);
	}
	static void dfs(int direction, int rowPos, int colPos) {
		//1. dfs를 통해 파이프의 오른쪽 끝점 움직이면서 (n,n)에 다다르면 answer를 추가해준다.
		if(rowPos == size && colPos == size) {
			answer++;
			return;
		}
		for(int dir = 0; dir < 3; dir++) {
			int nxtRow = rowPos + dx[dir];
			int nxtCol = colPos + dy[dir];
			//4. direction을 가로-> 세로, 세로 -> 가로는 안되므로 continue
			if((direction == 0 && dir == 1) || (direction == 1 && dir == 0)) continue;
			//5. nxtRow, nxtCol이 범위를 벗어나거나 끝 점에 pipeMap이 존재한다면 continue
			if(nxtRow < 1 || nxtRow > size || nxtCol < 1 || nxtCol > size || pipeMap[nxtRow][nxtCol] == 1) continue;
			if(dir == 2) {
				//6. 대각선 방향이라면 그 왼쪽과 위 방향을 추가로 확인해서 pipeMap이 존재하면 continue
				if(pipeMap[rowPos][colPos+1] == 1 || pipeMap[rowPos+1][colPos] == 1) continue;
			}
			dfs(dir, nxtRow, nxtCol);
		}
	}
}