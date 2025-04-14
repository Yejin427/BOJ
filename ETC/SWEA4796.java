import java.io.IOException;
import java.util.Scanner;

/**
 * 1. 배열을 순회하면서 증가 구간 길이, 감소 구간 길이를 통해 산의 개수를 저장한다.
 * 2. 하나의 큰 산이 만들어지고 끝날 때까지 increaseLength와 decreaseLength를 증가시킨다.
 * 3. 감소 구간에서는 앞선 증가 구간이 있어야 산이 될 수 있으므로 증가구간 길이가 1이상일 때 감소 구간을 추가한다.
 * 4. 증가 구간에서 만약 increaseLength decreaseLength모두 1보다 크다면 이전 산이 끝난 것이므로
 * 5. 산의 개수를 추가해준다.
 * 	5-1. 이때 산은 increaseLength * decreaseLength 만큼 만들 수 있다.
 * 6. 배열 순회가 끝났을 때도 산이 있다면 추가해준다.
 * @author SSAFY
 *
 */
public class SWEA4796{
	static int mountain[] = new int[50001];
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for(int test = 1; test <= testCase; test++) {
			int size = sc.nextInt();
			
			for(int mtIndex = 1; mtIndex <= size; mtIndex++) {
				mountain[mtIndex] = sc.nextInt();
			}
			int mountainCount = 0;
			
			int increaseLength = 0, decreaseLength = 0;
			//2. 하나의 큰 산이 만들어지고 끝날 때까지 increaseLength와 decreaseLength를 증가시킨다.
			for(int mtIndex = 2; mtIndex <= size; mtIndex++) {
				if(mountain[mtIndex-1] < mountain[mtIndex]) {
					//4. 증가 구간에서 만약 increaseLength decreaseLength모두 1보다 크다면 이전 산이 끝난 것이므로
					if(increaseLength > 0 && decreaseLength > 0) {
						//5. 산의 개수를 추가해준다.
						// 5-1. 이때 산은 increaseLength * decreaseLength 만큼 만들 수 있다.
						mountainCount += increaseLength * decreaseLength;
						increaseLength = 0;
						decreaseLength = 0;
					}
					increaseLength++;
				}
				//3. 감소 구간에서는 앞선 증가 구간이 있어야 산이 될 수 있으므로 증가구간 길이가 1이상일 때 감소 구간을 추가한다.
				else if(mountain[mtIndex-1] > mountain[mtIndex]){
					if(increaseLength > 0) {
						decreaseLength++;
					}
				}
			}
			//6. 배열 순회가 끝났을 때도 산이 있다면 추가해준다.
			if(increaseLength > 0 && decreaseLength > 0) {
				mountainCount += increaseLength * decreaseLength;
			}
			System.out.printf("#%d %d\n", test, mountainCount);
		}
	}
}