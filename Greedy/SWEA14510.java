import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. 나무가 홀수날은1, 짝수날은2 자라는데, 모든 나무를 딱 최대높이만큼 자라도록 해야한다.
 * -> 최대한 홀수날을 최소한으로 하도록 해야 날짜가 최소다
 * 2. 일단 모든 나무들을 돌면서 홀수만큼 남았다면 1을 무조건 주어야함 -> odd 변수 추가
 * 3. 총 남은 높이(total)에서 (odd)를 빼고 2를 나누면 2만큼 주어야 하는 날 even
 * 4. 일단 answer 날짜에 둘 중 작은 것 * 2만큼 추가해준다.
 * 5-1. 만약 odd>even -> 1212...1_1_ -> answer에 (odd-even)*2-1
 * 5-2. even>odd -> even-odd 수에 따라 다르게 처리
 * 	5-2-1. mod3 ==1 -> _2 그냥 2 추가
 * 	5-2-2. mod3==2 -> _2_2 -> 121로 변경 +3
 * 	5-2-3. mod3==0 -> _2_2_2 -> 1212로 변경이 최적 +4
 * 	5-2-4. 일단 even-odd의 3으로 나눈 몫만큼 *4 해주고 나머지를 위와같이 처리
 * @author SSAFY
 *
 */
public class SWEA14510 {
	static int[] tree;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int treeSize = Integer.parseInt(st.nextToken());
			tree = new int[treeSize+1];
			
			int maxHeight = 0;
			st = new StringTokenizer(br.readLine());
			for(int index = 1; index <= treeSize; index++) {
				tree[index] = Integer.parseInt(st.nextToken());
				maxHeight = Math.max(maxHeight, tree[index]);
			}
			int odd = 0, total = 0;
			for(int index = 1; index <= treeSize; index++) {
				int left = maxHeight - tree[index];
				//2. 일단 모든 나무들을 돌면서 홀수만큼 남았다면 1을 무조건 주어야함 -> odd 변수 추가
				if(left % 2 == 1) {
					odd++;
				}
				total += left;
			}
			//3. 총 남은 높이(total)에서 (odd)를 빼고 2를 나누면 2만큼 주어야 하는 날 even
			int even = (total - odd) / 2;
			//4. 일단 answer 날짜에 둘 중 작은 것 * 2만큼 추가해준다.
			int answer = Math.min(odd, even) * 2;
			if(odd > even) {
				//5-1. 만약 odd>even -> 1212...1_1_ -> answer에 (odd-even)*2-1
				answer += (odd-even)*2-1;
			} else {
				//5-2. even>odd -> even-odd 수에 따라 다르게 처리
				int day2left = even - odd;
				//	5-2-3. mod3==0 -> _2_2_2 -> 1212로 변경이 최적 +4
				//5-2-4. 일단 even-odd의 3으로 나눈 몫만큼 *4 해주고 나머지를 위와같이 처리
                answer += 4 * (day2left / 3);
                //5-2-1. mod3 ==1 -> _2 그냥 2 추가
                if(day2left % 3 == 1) answer += 2;
                //5-2-2. mod3==2 -> _2_2 -> 121로 변경 +3
                else if(day2left % 3 == 2) answer += 3;
			}
			
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	
}