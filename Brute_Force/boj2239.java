import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1. 스도쿠를 입력받고, 각 행, 열, 정사각형에서 1~9까지 중복없이 나오도록 비트마스킹을 사용한다.
 * 	1-1. rowBit, colBit, squareBit의 변수로 나타낸다.
 * 2. sudoku[row][col]의 수를 or연산을 통해 rowBit, colBit와 이에 해당하는 squareBit에 해당 수가 나왔음을 표시해준다.
 * 	2-1. squareBit는 가로로 0, 1, 2/ 3, 4, 5/6, 7, 8이므로 해당하는 index -> (row/3)*3+(col/3)
 * 3. backtracking을 통해 0인 곳을 각종 가능한 수로 채워준다.
 * 	3-1. 만약 매개변수 current가 81이상이면 다채운 것임 -> sudoku 배열을 출력하고 found flag 변수를 true로 한다.
 * 	3-2. 사전순으로 가장 작은 것만 출력할 것이므로 found가 true면 current가 몇이든 더이상 탐색하지 않는다.
 * 	3-3. num이 채워져있다면 바로 다음으로 넘어간다.
 * 	3-4. num이 0이라면 -> 해당 row, col위치에 num이 들어갈 수 있는지 rowBit, colBit, squareBit 확인 
 * 		3-4-1. 만약 채울 수 있다면 (or 연산이 0이라면) 해당 bit를 xor 연산을 통해 toggle하고 sudoku 배열을 num으로 채운다.
 * 		3-4-2. 재귀 호출 후 bit들과 sudoku배열을 다시 0으로 초기화한다.
 * @author SSAFY
 *
 */
public class BOJ2239{
	static int[][] sudoku = new int[9][9];
	// * 1. 스도쿠를 입력받고, 각 행, 열, 정사각형에서 1~9까지 중복없이 나오도록 비트마스킹을 사용한다.
	// * 	1-1. rowBit, colBit, squareBit의 변수로 나타낸다.
	static int[] rowBit = new int[9];
	static int[] colBit = new int[9];
	static int[] squareBit = new int[9];
	static boolean found = false;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int row = 0; row < 9; row++) {
			String str = br.readLine();
			for(int col = 0; col < 9; col++) {
				sudoku[row][col] = str.charAt(col) - '0';
			}
		}
		for(int row = 0; row < 9; row++) {
			for(int col = 0; col < 9; col++) {
				//2. sudoku[row][col]의 수를 or연산을 통해 rowBit, colBit와 이에 해당하는 squareBit에 해당 수가 나왔음을 표시해준다.
				rowBit[row] |= (1 << sudoku[row][col]);
				colBit[col] |= (1 << sudoku[row][col]);
				//2-1. squareBit는 가로로 0, 1, 2/ 3, 4, 5/6, 7, 8이므로 해당하는 index -> (row/3)*3+(col/3)
				squareBit[(row / 3) * 3 + (col / 3)] |= (1 << sudoku[row][col]);
			}
		}
		btrk(0);
	}
	static void btrk(int current) {
		//3-2. 사전순으로 가장 작은 것만 출력할 것이므로 found가 true면 current가 몇이든 더이상 탐색하지 않는다.
		if(found) return;
		if(current >= 81) {
			//3-1. 만약 매개변수 current가 81이상이면 다채운 것임 -> sudoku 배열을 출력하고 found flag 변수를 true로 한다.
			for(int row = 0; row < 9; row++) {
				for(int col = 0; col < 9; col++) {
					System.out.print(sudoku[row][col]);
				}
				System.out.println();
			}
			found = true;
			return;
		}
		int row = current / 9;
		int col = current % 9;
		//3-3. num이 채워져있다면 바로 다음으로 넘어간다.
		if(sudoku[row][col] != 0) btrk(current+1);
		else {
			for(int num = 1; num <= 9; num++) {
				//3-4. num이 0이라면 -> 해당 row, col위치에 num이 들어갈 수 있는지 rowBit, colBit, squareBit 확인 
				if((rowBit[row] & (1 << num)) == 0 && (colBit[col] & (1 << num)) == 0 && (squareBit[(row / 3) * 3 + (col / 3)] & (1 << num)) == 0) {
					//3-4-1. 만약 채울 수 있다면 (or 연산이 0이라면) 해당 bit를 xor 연산을 통해 toggle하고 sudoku 배열을 num으로 채운다.
					sudoku[row][col] = num;
					rowBit[row] ^= (1 << num);
					colBit[col] ^= (1 << num);
					squareBit[(row / 3) * 3 + (col / 3)] ^= (1 << num);
					btrk(current+1);
					//3-4-2. 재귀 호출 후 bit들과 sudoku배열을 다시 0으로 초기화한다.
					rowBit[row] ^= (1 << num);
					colBit[col] ^= (1 << num);
					squareBit[(row / 3) * 3 + (col / 3)] ^= (1 << num);
					sudoku[row][col] = 0;
				}
			}
		}
	}
}