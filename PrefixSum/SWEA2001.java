import java.util.Scanner;
/**
 * 1. 주어지는 파리 배열(flyArray), 2차원 누적합을 저장할 배열(prefixSum)을 할당한다
 * 	1-1. prefixSum[row][col] : (1,1)부터 (row,col)까지의 모든 배열의 원소를 합한 값
 * 2. prefixSum을 초기화함.
 * 	2-1. prefixSum(r, c) = prefixSum(r-1, c) + prefixSum(r, c-1) - prefixSum(r-1, c-1) + flyArray[r][c]를 만족함.
 * 3. row와 col을 1부터 ~ n-m+1까지 순회하면서 (row, col)~(row+m-1, col+m-1)로 이루어진 정사각형 모양의 합을 구한다
 *  3-1. 이는 (1,1)~(row+m-1, col+m-1)의 정사각형에서 (1,1)~(row-1, col+m-1)과 (1,1)~(row+m-1, col-1) 정사각형을 빼고
 *  (1,1)~(row-1, col-1)을 더한 값과 같다.
 * 4. 구한 후 maxFly을 계속 최대값으로 update한다.
 * @author SSAFY
 *
 */
public class SWEA2001 {
	static int flyArray[][] = new int[16][16];
	static int prefixSum[][] = new int[16][16];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for(int test = 1; test <= testCase; test++) {
			int size = sc.nextInt();
			int catchSize = sc.nextInt();
			int maxFly = 0;
			//fly input
			for(int row = 1; row <= size; row++) {
				for(int column = 1; column <= size; column++) {
					flyArray[row][column] = sc.nextInt();
				}
			}
			//prefixSum[row][col] : (1,1)부터 (row,col)까지의 모든 배열의 원소를 합한 값
			//prefixSum(r, c) = prefixSum(r-1, c) + prefixSum(r, c-1) - prefixSum(r-1, c-1) + flyArray[r][c]를 만족
			for(int row = 1; row <= size; row++) {
				for(int column = 1; column <= size; column++) {
					prefixSum[row][column] = prefixSum[row-1][column] + prefixSum[row][column-1] - prefixSum[row-1][column-1] + flyArray[row][column];
				}
			}
			//row와 col을 1부터 ~ n-m+1까지 순회하면서 (row, col)~(row+m-1, col+m-1)로 이루어진 정사각형 모양의 합을 구한다
			//이는 (1,1)~(row+m-1, col+m-1)의 정사각형에서 (1,1)~(row-1, col+m-1)과 (1,1)~(row+m-1, col-1) 정사각형을 빼고
			// (1,1)~(row-1, col-1)을 더한 값과 같다.
			for(int row = 1; row <= size - catchSize + 1; row++) {
				for(int column = 1; column <= size - catchSize + 1; column++) {
					int total = prefixSum[row + catchSize - 1][column + catchSize - 1] - 
							(prefixSum[row-1][column+catchSize-1] + prefixSum[row+catchSize-1][column-1] - prefixSum[row-1][column-1]);
					//구한 후 maxFly을 계속 최대값으로 update한다.
					maxFly = Math.max(total, maxFly);
				}
			}
			System.out.printf("#%d %d\n", test, maxFly);
		}
	}
}