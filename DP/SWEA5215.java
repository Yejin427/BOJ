import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. dp 냅색 문제를 통해서 해결
 * 2. dp[i][j] : i번 index까지 총 j까지의 칼로리를 먹었을 때 최대 점수
 * 3. 만약 j가 현재 index의 칼로리보다 작다면 -> dp[i][j] = dp[i-1][j]
 * 4. 아니라면 : dp[i][j-w] + score(현재 index의 음식을 먹었을 때)와 dp[i-1][j] 중 최대를 저장
 * @author SSAFY
 *
 */
public class SWEA5215 {
	static int[] score, calory;
	static int[][] dp;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
        	st = new StringTokenizer(br.readLine());
        	int ingredientCount = Integer.parseInt(st.nextToken());
        	int caloryLimit = Integer.parseInt(st.nextToken());
        	score = new int[ingredientCount+1];
        	calory = new int[ingredientCount+1];
        	for(int index = 1; index <= ingredientCount; index++) {
        		st = new StringTokenizer(br.readLine());
        		score[index] = Integer.parseInt(st.nextToken());
        		calory[index] = Integer.parseInt(st.nextToken());
        	}
        	dp = new int[ingredientCount+1][caloryLimit+1];
        	for(int index = 1; index <= ingredientCount; index++) {
        		for(int caloryAmount = 0; caloryAmount <= caloryLimit; caloryAmount++) {
        			if(caloryAmount < calory[index]) dp[index][caloryAmount] = dp[index-1][caloryAmount];
        			else dp[index][caloryAmount] = Math.max(dp[index-1][caloryAmount], dp[index-1][caloryAmount-calory[index]] + score[index]);
        		}
        	}
        	System.out.printf("#%d %d\n", test, dp[ingredientCount][caloryLimit]);
        }
	}
}