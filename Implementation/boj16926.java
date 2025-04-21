import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 한 rotate cycle에 rowStart, colStart, rowEnd, colEnd의 테두리를 지정한다.
 * 2. 해당 테두리 내에서 반 시계 방향 한 바퀴를 돌린다.
 * 	2-1. 먼저 테두리 꼭짓점의 변수들을 모두 저장해서 따로 빼놓고 (돌리면서 index가 범위를 넘어가는 것을 방지)
 * 	2-2. 그 사이 변들의 값만 반시계로 한칸씩 옮긴다.
 * 	 2-2-1. row나 column이 작아지는 방향으로 이동한다면 앞에서부터 옮겨주고, 커지는 방향으로 이동하면 뒤에서부터 옮겨준다.
 * 		-> 값이 덮어씌워지는 것을 방지
 * 	2-3. 그리고 나중에 저장한 꼭짓점들을 옮길 위치에 덮어씌운다.
 * 3. 한 cycle이 끝나면 rowStart, colStart를 하나씩 키워주고, rowEnd, colEnd는 하나씩 줄여준다.
 * 4. row나 column 중 하나라도 start와 end가 반전되면 한 cycle이 끝난다.
 * @author SSAFY
 *
 */
public class BOJ16926 {
	static int array[][];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int rowSize = Integer.parseInt(st.nextToken());
		int colSize = Integer.parseInt(st.nextToken());
		int rotate = Integer.parseInt(st.nextToken());
		array = new int[rowSize+1][colSize+1];
		for(int row = 1; row <= rowSize; row++) {
			st = new StringTokenizer(br.readLine());
			for(int col = 1; col <= colSize; col++) {
				array[row][col] = Integer.parseInt(st.nextToken());
			}
		}
		
		while(rotate-- > 0) {
			int rowStart = 1, colStart = 1, rowEnd = rowSize, colEnd = colSize;
			while(true) {
				//4. row나 column 중 하나라도 start와 end가 반전되면 한 cycle이 끝난다.
				if(rowStart > rowEnd || colStart > colEnd) break;
				
				//2-1. 먼저 테두리 꼭짓점의 변수들을 모두 저장해서 따로 빼놓고 (돌리면서 index가 범위를 넘어가는 것을 방지)
				int peek1 = array[rowStart][colStart];
				int peek2 = array[rowStart][colEnd];
				int peek3 = array[rowEnd][colStart];
				int peek4 = array[rowEnd][colEnd];
				//2-2. 그 사이 변들의 값만 반시계로 한칸씩 옮긴다.
				// 2-2-1. row나 column이 작아지는 방향으로 이동한다면 앞에서부터 옮겨주고, 커지는 방향으로 이동하면 뒤에서부터 옮겨준다.
				// -> 값이 덮어씌워지는 것을 방지
				for(int col = colStart + 1; col < colEnd; col++) {
					array[rowStart][col-1] = array[rowStart][col];
				}
				for(int row = rowEnd - 1; row > rowStart; row--) {
					array[row+1][colStart] = array[row][colStart];
				}
				for(int col = colEnd - 1; col > colStart; col--) {
					array[rowEnd][col+1] = array[rowEnd][col];
				}
				for(int row = rowStart + 1; row < rowEnd; row++) {
					array[row-1][colEnd] = array[row][colEnd];
				}
				//2-3. 그리고 나중에 저장한 꼭짓점들을 옮길 위치에 덮어씌운다.
				array[rowStart+1][colStart] = peek1;
				array[rowEnd][colStart+1] = peek3;
				array[rowStart][colEnd-1] = peek2;
				array[rowEnd-1][colEnd] = peek4;
				//3. 한 cycle이 끝나면 rowStart, colStart를 하나씩 키워주고, rowEnd, colEnd는 하나씩 줄여준다.
				rowStart++; colStart++; rowEnd--; colEnd--;
			}
		}
		for(int row = 1; row <= rowSize; row++) {
			for(int col = 1; col <= colSize; col++) {
				sb.append(array[row][col]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}