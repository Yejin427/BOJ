import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 동전으로 특정 금액을 만들 수 있는 가짓수를 구한다.
 * 2. Knapsack dp를 통해 푼다.
 * 	2-1. dp[i][j] : i번째까지의 동전을 사용했을 때 j금액을 만들 수 있는 가짓수
 * 	2-2. dp[0][0] = 1로 초기화한다. 아무것도 없는 상태에서 0원을 만들수 있는 경우의 수 1가지
 * 	2-3. 만약 탐색 금액이 coin[index]보다 크다면 -> dp[index][price-coin[index]]를 dp에 더해준다.
 * @author SSAFY
 *
 */
public class BOJ9084{
	static int[] coin;
	static int[][] dp;
	static int coinSize, targetPrice, answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		while(testCase-- > 0) {
			st = new StringTokenizer(br.readLine());
			coinSize = Integer.parseInt(st.nextToken());
			coin = new int[coinSize+1];
			st = new StringTokenizer(br.readLine());
			for(int index = 1; index <= coinSize; index++) {
				coin[index] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			targetPrice = Integer.parseInt(st.nextToken());
			//2-1. dp[i][j] : i번째까지의 동전을 사용했을 때 j금액을 만들 수 있는 가짓수
			dp = new int[coinSize+1][targetPrice+1];
			//2-2. dp[0][0] = 1로 초기화한다. 아무것도 없는 상태에서 0원을 만들수 있는 경우의 수 1가지
			dp[0][0] = 1;
			for(int index = 1; index <= coinSize; index++) {
				for(int price = 0; price <= targetPrice; price++) {
					dp[index][price] = dp[index-1][price];
					//2-3. 만약 탐색 금액이 coin[index]보다 크다면 -> dp[index][price-coin[index]]를 dp에 더해준다.
					if(price >= coin[index]) dp[index][price] += dp[index][price-coin[index]];
				}
			}
			System.out.println(dp[coinSize][targetPrice]);
		}
	}
	
}