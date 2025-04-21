import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. 현재 뱀의 길이보다 작으면 해당 과일을 먹고 뱀의 길이가 1 자란다.
 * 2. 최대로 커지려면(최대로 많이 먹으려면) => 과일을 정렬하고 하나씩 먹는다
 * 3. 만약 뱀의 길이보다 크다면 -> 더이상 먹을 수 없다.
 * @author SSAFY
 *
 */
public class BOJ16435 {
	static int fruits[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int fruitSize = Integer.parseInt(st.nextToken());
		int snakeLength = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		fruits = new int[fruitSize+1];
		for(int fruitIdx = 1; fruitIdx <= fruitSize; fruitIdx++) {
			fruits[fruitIdx] = Integer.parseInt(st.nextToken());
		}
		//2. 최대로 커지려면(최대로 많이 먹으려면) => 과일을 정렬하고 하나씩 먹는다
		Arrays.sort(fruits);
		
		for(int fruitIdx = 1; fruitIdx <= fruitSize; fruitIdx++) {
			if(fruits[fruitIdx] <= snakeLength) {
				snakeLength++;
			} else {
				//3. 만약 뱀의 길이보다 크다면 -> 더이상 먹을 수 없다.
				break;
			}
		}
		System.out.println(snakeLength);
	}
}