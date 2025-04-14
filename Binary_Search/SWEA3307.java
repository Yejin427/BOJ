import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. LIS문제를 이분탐색을 통해 푼다.
 * 2. lis 배열을 최대 size+1만큼 선언한다. (최대 size만큼 증가하는 부분수열임
 * 3. 만약 현재 lisSize가 0이거나 lis의 끝의 값보다 현재 array[index]가 크다면 -> lisSize에 array[index]를 넣고 size를 증가시킨다.
 * 4. 그렇지 않다면 lis에서 Arrays.binarySearch함수를 통해서 현재 array[index]의 lower_bound index를 찾는다.
 * 5. 만약 Arrays.binarySearch값이 0보다 크다면 -> 해당 값이 있으므로 continue;
 * 6. 그렇지 않다면 -index-1하여 lis의 해당 index 값을 바꿔준다.
 * @author SSAFY
 *
 */
public class SWEA3307 {
	static int[] array;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int size = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			array = new int[size+1];
			for(int index = 1; index <= size; index++) {
				array[index] = Integer.parseInt(st.nextToken());
			}
			//2. lis 배열을 최대 size+1만큼 선언한다. (최대 size만큼 증가하는 부분수열임
			int[] lis = new int[size+1];
			int lisSize = 0;
			for(int index = 1; index <= size; index++) {
				//3. 만약 현재 lisSize가 0이거나 lis의 끝의 값보다 현재 array[index]가 크다면 -> lisSize에 array[index]를 넣고 size를 증가시킨다.
				if(lisSize == 0 || lis[lisSize-1] < array[index]) {
					lis[lisSize++] = array[index];
				} else {
					//4. 그렇지 않다면 lis에서 Arrays.binarySearch함수를 통해서 현재 array[index]의 lower_bound index를 찾는다.
					int pos = Arrays.binarySearch(lis, 0, lisSize, array[index]);
					//5. 만약 Arrays.binarySearch값이 0보다 크다면 -> 해당 값이 있으므로 continue;
					if(pos >= 0) continue;
					//6. 그렇지 않다면 -index-1하여 lis의 해당 index 값을 바꿔준다.
					lis[-pos-1] = array[index];
				}
			}
			System.out.printf("#%d %d\n", test, lisSize);
		}
	}
}