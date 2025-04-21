import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 1. while문으로 입력받는 number부터 시작해서 짝수면 절반으로 나누고 홀수면 3배 +1을 하면서 count를 증가시킨다.
 * 2. 입력값이 크므로 dp배열로 풀면 메모리 초과가 난다.
 * @author SSAFY
 *
 */
public class SWEA24268 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int testCase = Integer.parseInt(br.readLine());
		
		for(int test = 1; test <= testCase; test++) {
			int num = Integer.parseInt(br.readLine());
			int count = 0;
			int currentNum = num;
			//1. while문으로 입력받는 number부터 시작해서 짝수면 절반으로 나누고 홀수면 3배 +1을 하면서 count를 증가시킨다.
			while(currentNum != 1) {
				if(currentNum % 2 == 1) currentNum = currentNum * 3 + 1;
				else currentNum /= 2;
				count++;
			}
			sb.append('#').append(test).append(' ').append(num).append(' ').append(count).append('\n');
		}
		System.out.print(sb);
	}
}