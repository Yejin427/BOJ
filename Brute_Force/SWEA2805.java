import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 정사각형 형태의 농장 내 마름모 꼴의 농장 내 범위를 구해야 한다.
 * 2. 테두리의 규칙을 알아내고 그 범위 내에 있을 때 농작물을 추가한다.
 * 3. 마름모의 위의 /, 밑에 /는 모두 (row, col)의 합이 같다는 특성이 있음 
 * 	3-1. 여기서는 각각 (n/2+1, 1) = n/2+2, (n/2+1, n) = n/2+n+1
 * 4. 위의 \, 밑의 \는 모두 (row, col)의 차가 같다는 특성이 있음. 
 * 	4-1. 여기서는 각각 n/2+1, -(n/2+1)
 * 5. row, col 합이 n/2+2 - n/2+n+1 사이면서 abs(row-col)이 n/2+1보다 작으면 된다.
 * @author SSAFY
 *
 */
public class SWEA2805 {
	static char farm[][] = new char[50][50];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int testCase = Integer.parseInt(st.nextToken());
		
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int farmSize = Integer.parseInt(st.nextToken());
			
			for(int row = 1; row <= farmSize; row++) {
				for(int column = 1; column <= farmSize; column++) {
					farm[row][column] = (char) br.read();
				}
				br.readLine();
			}
			
			int answer = 0;
			for(int row = 1; row <= farmSize; row++) {
				for(int column = 1; column <= farmSize; column++) {
					if((row+column >= farmSize/2+2 && row+column <= farmSize/2+farmSize+1)
							&& Math.abs(row-column) <= farmSize / 2) {
						answer += farm[row][column] - '0';
					}
				}
			}
			System.out.printf("#%d %d\n", test, answer);
		}
		
	}
}