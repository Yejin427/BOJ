import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA1486 {
	static int heightArray[] = new int[21];
	static int managerSize, bookcase;
	static int answer;
	static void solveMinHeight(int index, int currentHeight) {
		if(currentHeight >= bookcase) {
			answer = Math.min(answer, currentHeight);
			return;
		}
		if(index == managerSize) {
			return;
		}
		solveMinHeight(index + 1, currentHeight + heightArray[index]);
		solveMinHeight(index + 1, currentHeight);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int testCase = Integer.parseInt(st.nextToken());
		
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			managerSize = Integer.parseInt(st.nextToken());
			bookcase = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int index = 0; index < managerSize; index++) {
				heightArray[index] = Integer.parseInt(st.nextToken());
			}
			answer = Integer.MAX_VALUE;
			solveMinHeight(0, 0);
			System.out.printf("#%d %d", test, answer-bookcase);
		}
		
		
	}
}