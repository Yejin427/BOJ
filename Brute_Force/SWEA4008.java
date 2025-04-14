import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


import java.util.StringTokenizer;

/**
 * 1. 숫자들의 위치는 고정이고 연산자들의 순서가 바뀔 수 있으므로 연산자들에 대해 nextPermutation을 사용한다.
 * 2. operator들의 크기를 비교할 수 있도록 +, -, *, /를 각각 0, 1, 2, 3으로 operators array에 저장한다.
 * 3. +,-,*,/ 개수를 입력받고 operators에 저장하는데 이때 operators는 미리 정렬되어 있어 정렬하지 않아도 된다.
 * 4. swap을 해야할 index가 존재하지 않을 때까지 (가장 큰 값의 index = 0) npOps 함수를 돌리며 operator 순열을 기록한다.
 * 5. 해당 순서의 연산자 배열에 따른 연산을 수행한다.
 *  5-1. calculated에 먼저 가장 첫 수를 저장한다.
 *  5-2. operators를 순회하며 0, 1, 2, 3일 때 각각 calculated 변수에 다음값을 +, -, *, / 연산해서 누적해준다. 
 * 6. 정답을 출력할 minValue, maxValue를 선언해주는데 각각 Math.min과 Math.max로 값을 update해주기 위해 각각 최대값, 최솟값으로 저장한다.
 * @author SSAFY
 *
 */
public class SWEA4008 {
	static int nums[];
	static int operators[];
	static int numSize;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int test = Integer.parseInt(st.nextToken());
		for(int testCase = 1; testCase <= test; testCase++) {
			st = new StringTokenizer(br.readLine());
			numSize = Integer.parseInt(st.nextToken());
			
			nums = new int[numSize];
			operators = new int[numSize-1];
			//6. 정답을 출력할 minValue, maxValue를 선언해주는데 각각 Math.min과 Math.max로 값을 update해주기 위해 각각 최대값, 최솟값으로 저장한다.
			int minValue = 100000001;
			int maxValue = -100000001;
			
			st = new StringTokenizer(br.readLine());
			
			int plusCount = Integer.parseInt(st.nextToken());
			int opIndex = 0;
			while(plusCount-- > 0) {
				operators[opIndex++] = 0;
			}
			int minusCount = Integer.parseInt(st.nextToken());
			while(minusCount-- > 0) {
				operators[opIndex++] = 1;
			}
			int mulCount = Integer.parseInt(st.nextToken());
			while(mulCount-- > 0) {
				operators[opIndex++] = 2;
			}
			int divCount = Integer.parseInt(st.nextToken());
			while(divCount-- > 0) {
				operators[opIndex++] = 3;
			}
			
			st = new StringTokenizer(br.readLine());
			for(int index = 0; index < numSize; index++) {
				nums[index] = Integer.parseInt(st.nextToken());
			}
			
			/**
			 * 5. 해당 순서의 연산자 배열에 따른 연산을 수행한다.
			 *  5-1. calculated에 먼저 가장 첫 수를 저장한다.
			 *  5-2. operators를 순회하며 0, 1, 2, 3일 때 각각 calculated 변수에 다음값을 +, -, *, / 연산해서 누적해준다. 
			 */
			do {
				int calculated = nums[0];
				for(int index = 0; index < numSize - 1; index++) {
					if(operators[index] == 0) {
						calculated += nums[index+1];
					} else if(operators[index] == 1) {
						calculated -= nums[index+1];
					} else if(operators[index] == 2) {
						calculated *= nums[index+1];
					} else {
						calculated /= nums[index+1];
					}
				}
				maxValue = Math.max(maxValue,  calculated);
				minValue = Math.min(minValue, calculated);
			} while(npOps());

			System.out.printf("#%d %d\n", testCase, maxValue - minValue);
			
		}
	}
	
	/**
	 * 1. 숫자들의 위치는 고정이고 연산자들의 순서가 바뀔 수 있으므로 연산자들에 대해 nextPermutation을 사용한다.
	 * 2. operator들의 크기를 비교할 수 있도록 +, -, *, /를 각각 0, 1, 2, 3으로 operators array에 저장한다.
	 * 3. +,-,*,/ 개수를 입력받고 operators에 저장하는데 이때 operators는 미리 정렬되어 있어 정렬하지 않아도 된다.
	 * 4. swap을 해야할 index가 존재하지 않을 때까지 (가장 큰 값의 index = 0) npOps 함수를 돌리며 operator 순열을 기록한다.
	 * @return
	 */
	static boolean npOps() {
		int biggestIdx = numSize-2;
		while(biggestIdx > 0 && operators[biggestIdx-1] >= operators[biggestIdx]) --biggestIdx;
		if(biggestIdx == 0) return false;

		int nxtBiggestIdx = numSize-2;
		while(operators[biggestIdx-1] >= operators[nxtBiggestIdx]) --nxtBiggestIdx;
		swapOps(biggestIdx-1, nxtBiggestIdx);
		
		int swapIndex = numSize-2;
		while(biggestIdx < swapIndex) swapOps(biggestIdx++, swapIndex--);
		
		return true;
	}

	
	static void swapOps(int leftIdx, int rightIdx) {
		int temp = operators[leftIdx];
		operators[leftIdx] = operators[rightIdx];
		operators[rightIdx] = temp;
	}

}