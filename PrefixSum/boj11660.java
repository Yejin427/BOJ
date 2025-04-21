import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * 만약 naive하게 쿼리마다 이차원배열의 합을 구한다면 O(n^2*M) = O(10^11)로 시간초과가 날 수 있다.
 * 이를 방지하기 위해 이차원 누적합 알고리즘을 사용해서 쿼리마다 O(1)로 값을 구할 수 있도록 할 수 있다.
 * 1. 주어지는 배열(numArray), 2차원 누적합을 저장할 배열(prefixSum)을 할당한다
 * 	1-1. prefixSum[row][col] : (1,1)부터 (row,col)까지의 모든 배열의 원소를 합한 값
 * 2. prefixSum을 초기화함.
 *  2-1. prefixSum(r, c) = prefixSum(r-1, c) + prefixSum(r, c-1) - prefixSum(r-1, c-1) + numArray[r][c]를 만족함.
 * 3. query값이 들어올 때마다 값을 구한다.
 *  3-1. (startRow, startColumn)~(endRow, endColumn)까지의 합 
 *  = prefixSum[endRow][endColumn] - (prefixSum[startRow-1][endColumn] + prefixSum[endRow][startColumn-1] - prefixSum[startRow-1][startColumn-1]
 * @author SSAFY
 *
 */
public class BOJ11660 {
	static int numArray[][] = new int[1025][1025];
	//prefixSum[row][col] : (1,1)부터 (row,col)까지의 모든 배열의 원소를 합한 값
	static int prefixSum[][] = new int[1025][1025];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int arraySize = Integer.parseInt(st.nextToken());
		int querySize = Integer.parseInt(st.nextToken());
		
		for(int row = 1; row <= arraySize; row++) {
			st = new StringTokenizer(br.readLine());
			for(int col = 1; col <= arraySize; col++) {
				numArray[row][col] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 2. prefixSum을 초기화함.
		// 2-1. prefixSum(r, c) = prefixSum(r-1, c) + prefixSum(r, c-1) - prefixSum(r-1, c-1) + numArray[r][c]
		for(int row = 1; row <= arraySize; row++) {
			for(int col = 1; col <= arraySize; col++) {
				prefixSum[row][col] = prefixSum[row-1][col] + prefixSum[row][col-1] 
						- prefixSum[row-1][col-1] + numArray[row][col];
			}
		}
		//querySize를 감소시키면서 querySize개수만큼 입력받음
		while(querySize > 0) {
			st = new StringTokenizer(br.readLine());
			int startRow = Integer.parseInt(st.nextToken());
			int startColumn = Integer.parseInt(st.nextToken());
			int endRow = Integer.parseInt(st.nextToken());
			int endColumn = Integer.parseInt(st.nextToken());
			
			//(startRow, startColumn)~(endRow, endColumn)까지의 합을 구한다.
			System.out.println(prefixSum[endRow][endColumn] - 
					(prefixSum[startRow-1][endColumn] + prefixSum[endRow][startColumn-1] - prefixSum[startRow-1][startColumn-1]));
			querySize--;
		}
	}
}