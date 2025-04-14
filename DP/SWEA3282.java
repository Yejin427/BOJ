import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 특정 물건을 가방에 넣거나, 넣지 않을 수 있으며, 최대 용량이 bagSize를 넘으면 안됨
 * 2. dp 2차원 배열을 통해서 문제를 해결
 * 	2-1. dp[i][j] : i번 물건까지 봤을 때 최대 j까지 넣을 때의 최대 cost
 * 3. index와 costvalue를 0부터 제한 size까지 돌면서
 * 	3-1. 만약 현재 costValue가 현재 index의 부피보다 작다면 -> 현재 index 물건을 추가할 수 없음 -> dp[index-1][value]로 초기화
 * 	3-2. 아니라면 -> 현재 index 물건을 추가했을 때와 dp[index-1][value]를 비교
 * 		 3-2-1. 현재 물건을 추가했을 때 : dp[index-1][val-volume[index]]+cost[index]
 * @author SSAFY
 *
 */
public class SWEA3282 {
	static int[] cost;
	static int[] volume;
	//2-1. dp[i][j] : i번 물건까지 봤을 때 최대 j까지 넣을 때의 최대 cost
	static int[][] dp;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int productSize = Integer.parseInt(st.nextToken());
			int bagSize = Integer.parseInt(st.nextToken());
			cost = new int[productSize+1];
			volume = new int[productSize+1];
			dp = new int[productSize+1][bagSize+1];
			for(int index = 1; index <= productSize; index++) {
				st = new StringTokenizer(br.readLine());
				volume[index] = Integer.parseInt(st.nextToken());
				cost[index] = Integer.parseInt(st.nextToken());
			}
			for(int index = 1; index <= productSize; index++) {
				for(int value = 0; value <= bagSize; value++) {
					//3-1. 만약 현재 costValue가 현재 index의 부피보다 작다면 -> 현재 index 물건을 추가할 수 없음 -> dp[index-1][value]로 초기화
					if(value < volume[index]) {
						dp[index][value] = dp[index-1][value];
					} else {
						//3-2. 아니라면 -> 현재 index 물건을 추가했을 때와 dp[index-1][value]를 비교
						//3-2-1. 현재 물건을 추가했을 때 : dp[index-1][val-volume[index]]+cost[index]
						dp[index][value] = Math.max(dp[index-1][value], dp[index-1][value-volume[index]] + cost[index]);
					}
				}
			}
			System.out.printf("#%d %d\n", test, dp[productSize][bagSize]);
		}
		
	}
}