import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 입력받으면서 입력받는 높이의 최댓값을 maxHeight에 계속 update한다.
 * 2. maxHeight와 높이가 같은 봉우리들을 startList에 좌표를 저장한다.
 * 3. 좌표마다 1부터 K까지 깎으면서, startList의 좌표들에서 dp 함수 호출하고 최대값을 저장한다.
 * 	3-1. startDp 함수 : top-down 방식으로 최댓값 업데이트
 *  	3-1-1. 일단 최소 1이므로  dp값을 1로 초기화
 *  	3-1-2. 자신의 4방을 보면서, 그 중 자신보다 값이 작을 때 자신의 dp값을 다음 칸 dp값 +1과 비교 후 업데이트한다.
 *  	3-1-3. 만약 dp값이 저장되어있다면 저장된 값을 리턴하는 메모이제이션 진행.
 * @author SSAFY
 *
 */
public class SWEA1949 {
	static int[][] mountain;
	static int[][] dp;
	static int size;
	static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	static List<int[]> startList;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			size = Integer.parseInt(st.nextToken());
			int change = Integer.parseInt(st.nextToken());
			mountain = new int[size+1][size+1];
			dp = new int[size+1][size+1];
			startList = new ArrayList<>();
			int maxHeight = 0;
			for(int row = 1; row <= size; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= size; col++) {
					mountain[row][col] = Integer.parseInt(st.nextToken());
					//1. 입력받으면서 입력받는 높이의 최댓값을 maxHeight에 계속 update한다.
					maxHeight = Math.max(mountain[row][col], maxHeight);
				}
			}
			for(int row = 1; row <= size; row++) {
				for(int col = 1; col <= size; col++) {
					//2. maxHeight와 높이가 같은 봉우리들을 startList에 좌표를 저장한다.
					if(mountain[row][col] == maxHeight) {
						startList.add(new int[] {row, col});
					}
				}
			}
			int answer = 0;
			for(int changeRow = 1; changeRow <= size; changeRow++) {
				for(int changeCol = 1; changeCol <= size; changeCol++) {
					for(int amount = 1; amount <= change; amount++) {
						mountain[changeRow][changeCol] -= amount;
						
						for(int[] startPos: startList) {
							for(int row = 1; row <= size; row++) {
								for(int col = 1; col <= size; col++) {
									dp[row][col] = 0;
								}
							}
							//3. 좌표마다 1부터 K까지 깎으면서, startList의 좌표들에서 dp 함수 호출하고 최대값을 저장한다.
							int value = startDp(startPos[0], startPos[1]);
							answer = Math.max(value, answer);
						}
						mountain[changeRow][changeCol] += amount;
					}
				}
			}
			for(int[] startPos: startList) {
				for(int row = 1; row <= size; row++) {
					for(int col = 1; col <= size; col++) {
						dp[row][col] = 0;
					}
				}
				answer = Math.max(startDp(startPos[0], startPos[1]), answer);
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	static int startDp(int row, int col) {
		//3-1-3. 만약 dp값이 저장되어있다면 저장된 값을 리턴하는 메모이제이션 진행.
		if(dp[row][col] >= 1) return dp[row][col];
		//3-1-1. 일단 최소 1이므로  dp값을 1로 초기화
		dp[row][col] = 1;
		//3-1-2. 자신의 4방을 보면서, 그 중 자신보다 값이 작을 때 자신의 dp값을 다음 칸 dp값 +1과 비교 후 업데이트한다.
		for(int dir = 0; dir < 4; dir++) {
			int nxtRow = row + dx[dir];
			int nxtCol = col + dy[dir];
			if(1 <= nxtRow && nxtRow <= size && 1 <= nxtCol && nxtCol <= size && mountain[nxtRow][nxtCol] < mountain[row][col]) {
				dp[row][col] = Math.max(dp[row][col], startDp(nxtRow, nxtCol)+1);
			}
		}
		
		return dp[row][col];
	}
}