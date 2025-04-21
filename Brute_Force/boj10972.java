import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * nextPermutation 기법을 통해 사전 순의 다음 수를 빠르게 구할 수 있다.
 * 1. 현재 기준으로 가장 큰 수의 index를 구한다.
 * 2. biggestIndex-1번째의 값과 biggestIndex이후 biggestIndex-1의 값 보다 큰 값의 index(nxtBiggestIndex)를 저장해준다.
 * 3. 그 두 값을 swap한다
 * 4. 그 이후의 값을 오름차순으로 바꾸기위해 biggestIndex와 swapIndex의 값을 비교하고 swap한다.
 * 5. 사전 순으로 마지막 순열일 땐 (biggestIndex = 0) 바로 false를 리턴한다.
 * @author SSAFY
 *
 */
public class BO10972 {
	static int size;
	static int numArray[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		size = Integer.parseInt(st.nextToken());
		numArray = new int[size];
		st = new StringTokenizer(br.readLine());
		for(int index = 0; index < size; index++) {
			numArray[index] = Integer.parseInt(st.nextToken());
		}
		
		if(!np()) {
			System.out.println(-1);
		} else {
			for(int value: numArray) {
				System.out.printf("%d ", value);
			}
		}
	}
	
	static boolean np() {
		int biggestIdx = size-1;
		//1. 현재 기준으로 가장 큰 수의 index를 구한다.
		while(biggestIdx > 0 && numArray[biggestIdx-1] >= numArray[biggestIdx]) --biggestIdx;
		//사전 순으로 마지막 순열일 땐 (biggestIndex = 0) 바로 false를 리턴한다.
		if(biggestIdx == 0) return false;

		//biggestIndex-1번째의 값과 biggestIndex이후 biggestIndex-1의 값 보다 큰 값의 index(nxtBiggestIndex)를 저장해준다.
		int nxtBiggestIdx = size-1;
		while(numArray[biggestIdx-1] >= numArray[nxtBiggestIdx]) --nxtBiggestIdx;
		
		//그 두 값을 swap한다
		swap(biggestIdx-1, nxtBiggestIdx);
		//그 이후의 값을 오름차순으로 바꾸기위해 biggestIndex와 swapIndex의 값을 비교하고 swap한다.
		int swapIndex = size-1;
		while(biggestIdx < swapIndex) swap(biggestIdx++, swapIndex--);
		
		return true;
	}

	
	static void swap(int leftIdx, int rightIdx) {
		int temp = numArray[leftIdx];
		numArray[leftIdx] = numArray[rightIdx];
		numArray[rightIdx] = temp;
	}
}