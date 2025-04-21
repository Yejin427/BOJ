import java.util.Scanner;
/**
 * 1. N개 중 중복과 순서를 고려하지 않고 M개를 추출 -> 재귀함수를 사용한다
 * 2. combination(int currentIndex, int currentNumber)
 * 	2-1. currentIndex : 현재까지 채워진 index를 저장
 *  2-2. currentNumber : 현재까지 저장한 가장 큰 수 
 * 3. 기저조건 : currentIndex가 M(selectCount)에 도달하면 -> 저장한 배열을 출력한다
 * 4. 재귀 : currentNumber보다 큰 수만 순회하여 printArray에 저장하고 재귀를 호출한다.
 * @author SSAFY
 *
 */
public class BOJ15650 {
	//selectCount = M, elementCount = N
	static int selectCount, elementCount;
	static int[] printArray;
	/**
	 * combination 재귀함수
	 * @param currentIndex : 현재까지 채워진 index를 저장
	 * @param currentNumber : 현재까지 저장한 가장 큰 수를 저장
	 */
	static void combination(int currentIndex, int currentNumber) {
		//3. 기저조건 : currentIndex가 M(selectCount)에 도달하면 -> 저장한 배열을 출력한다
		if(currentIndex == selectCount) {
			for(int value: printArray) {
				System.out.printf("%d ", value);
			}
			System.out.println();
			return;
		}
		//4. 재귀 : currentNumber보다 큰 수만 순회하여 printArray에 저장하고 재귀를 호출한다.
		for(int nxtNumber = currentNumber + 1; nxtNumber <= elementCount; nxtNumber++) {
			printArray[currentIndex] = nxtNumber;
			combination(currentIndex + 1, nxtNumber);
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		elementCount = sc.nextInt();
		selectCount = sc.nextInt();
		//뽑을 개수만큼 배열을 할당한다.
		printArray = new int[selectCount];
		combination(0, 0);
	}
}