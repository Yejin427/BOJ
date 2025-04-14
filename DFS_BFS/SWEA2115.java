import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 완전탐색을 통해 두 벌통 채취 최댓값을 구한다.
 * 2. 벌통의 시작점을 기준으로 완전탐색을 한다. 이때 column은 col + selectSize-1 <= size 일때까지만 돌려 범위를 벗어나지 않도록 한다.
 * 3. isDuplicate 함수 : 두 벌통의 시작점을 parameter로 받아 두 벌통이 겹치지 않는지 판단하는 함수다.
 * 4. calcMaxProfit 함수 : dfs 재귀를 통해서 벌통을 포함 / 미포함 모든 경우의 수에 대해 최대 이익을 반환
 * 	4-1. 만약 depth가 벌통 size만큼 돌았다면 벌통 숫자의 합이 honeySize 제한보다 작으면 계산한 이익 반환, 아니면 계산하면 안되므로 0반환
 * 	4-2. 나머지 경우에 대해서 현재 벌통을 포함하는 경우, 포함하지 않는 경우 둘 중의 최대를 반환한다.
 * 5. maxProfitFirst + maxProfitSecond의 최대값을 계속 갱신한다.
 * @author SSAFY
 *
 */
public class SWEA2115{
	static int[][] honey;
	static int size, selectSize, honeySize, answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			size = Integer.parseInt(st.nextToken());
			selectSize = Integer.parseInt(st.nextToken());
			honeySize = Integer.parseInt(st.nextToken());
			honey = new int[size+1][size+1];
			answer = 0;
			for(int row = 1; row <= size; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= size; col++) {
					honey[row][col] = Integer.parseInt(st.nextToken());
				}
			}
			//2. 벌통의 시작점을 기준으로 완전탐색을 한다. 이때 column은 col + selectSize-1 <= size 일때까지만 돌려 범위를 벗어나지 않도록 한다.
			for(int firstRow = 1; firstRow <= size; firstRow++) {
				for(int firstCol = 1; firstCol + selectSize-1 <= size; firstCol++) {
					int maxProfitFirst = calcMaxProfit(firstRow, firstCol, 0, 0, 0);
					
					for(int secondRow = 1; secondRow <= size; secondRow++) {
						for(int secondCol = 1; secondCol + selectSize-1 <= size; secondCol++) {
							if(isDuplicate(firstRow, firstCol, secondRow, secondCol)) continue;
							int maxProfitSecond = calcMaxProfit(secondRow, secondCol, 0, 0, 0);
							//5. maxProfitFirst + maxProfitSecond의 최대값을 계속 갱신한다.
							answer = Math.max(answer, maxProfitFirst + maxProfitSecond);
						}
					}
					
				}
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	//3. isDuplicate 함수 : 두 벌통의 시작점을 parameter로 받아 두 벌통이 겹치지 않는지 판단하는 함수다.
	static boolean isDuplicate(int fr, int fc, int sr, int sc) {
		return fr == sr && ((fc <= sc && sc <= fc + selectSize-1) || (sc <= fc && fc <= sc + selectSize-1));
	}
	//4. calcMaxProfit 함수 : dfs 재귀를 통해서 벌통을 포함 / 미포함 모든 경우의 수에 대해 최대 이익을 반환
	static int calcMaxProfit(int row, int col, int depth, int curSum, int curProfit) {
		//4-1. 만약 depth가 벌통 size만큼 돌았다면 벌통 숫자의 합이 honeySize 제한보다 작으면 계산한 이익 반환, 아니면 계산하면 안되므로 0반환
		if(depth == selectSize) {
			if(curSum <= honeySize) {
				return curProfit;
			} else {
				return 0;
			}
		}
		//4-2. 나머지 경우에 대해서 현재 벌통을 포함하는 경우, 포함하지 않는 경우 둘 중의 최대를 반환한다.
		return Math.max(calcMaxProfit(row, col, depth+1, curSum, curProfit), 
				calcMaxProfit(row, col, depth+1, curSum + honey[row][col+depth], curProfit + honey[row][col+depth] * honey[row][col+depth]));
	}
}