import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/**
 * 1. N이 3000000이므로 O(N)에 문제를 해결해야 한다.
 * 2. 슬라이딩 윈도우를 통해 현재 초밥이 나온 횟수를 카운팅한다.
 * 3. startIndex = 0일때 window 초기화한다.
 * 	3-1. 만약 현재 접시 sushiEat을 더했을 때 1이 된다면 typeCount을 추가한다.
 * 	3-2. 만약 coupon에 해당하는 sushiEat이 0이라면 -> curtype에는 추가하지 않고 maxType에만 1을 추가한다.
 * 4. startIndex = 1부터 슬라이딩 윈도우를 진행
 * 	4-1. 이전 윈도우의 startIndex의 sushiEat을 1빼주고 빼서 0이 되었다면 curType을 1빼준다.
 * 	4-2. 현재 윈도우의 맨 끝 초밥(새로생김)의 sushiEat을 1 더해주고 더해서 1이 되었다면 curType에 1 더해준다.
 * 	4-2-1. 회전초밥이므로 (dishSize -> 0) endIdx에 dishSize를 나눈 나머지로 한다.
 * 5. 현재 sushiEat의 coupon index가 0이면 max에 curType에 +1한 값으로 update한다.
 * @author SSAFY
 *
 */
public class BO15961 {
	static int[] dish;
	static int[] sushiEat;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int dishSize = Integer.parseInt(st.nextToken());
		int sushiSize = Integer.parseInt(st.nextToken());
		int eatSize = Integer.parseInt(st.nextToken());
		int coupon = Integer.parseInt(st.nextToken());
		dish = new int[dishSize];
		sushiEat = new int[sushiSize+1];
		for(int index = 0; index < dishSize; index++) {
			dish[index] = Integer.parseInt(br.readLine());
		}
		int maxTypeCount = 0, curTypeCount = 0;
		//3. startIndex = 0일때 window 초기화한다.
		for(int index = 0; index < eatSize; index++) {
			//3-1. 만약 현재 접시 sushiEat을 더했을 때 1이 된다면 typeCount을 추가한다.
			if(sushiEat[dish[index]]++ == 0) curTypeCount++;
		}
		maxTypeCount = curTypeCount;
		//	3-2. 만약 coupon에 해당하는 sushiEat이 0이라면 -> curtype에는 추가하지 않고 maxType에만 1을 추가한다.
		if(sushiEat[coupon] == 0) maxTypeCount++;

		//4. startIndex = 1부터 슬라이딩 윈도우를 진행
		for(int startIndex = 1; startIndex < dishSize; startIndex++) {
			//4-1. 이전 윈도우의 startIndex의 sushiEat을 1빼주고 빼서 0이 되었다면 curType을 1빼준다.
			if(--sushiEat[dish[startIndex-1]] == 0) {
				curTypeCount--;
			}
			//4-2-1. 회전초밥이므로 (dishSize -> 0) endIdx에 dishSize를 나눈 나머지로 한다.
			int endIdx = (startIndex+eatSize-1) % dishSize;
			//4-2. 현재 윈도우의 맨 끝 초밥(새로생김)의 sushiEat을 1 더해주고 더해서 1이 되었다면 curType에 1 더해준다.
			if(++sushiEat[dish[endIdx]] == 1) {
				curTypeCount++;
			}
			//5. 현재 sushiEat의 coupon index가 0이면 max에 curType에 +1한 값으로 update한다.
			int flag = sushiEat[coupon] == 0 ? 1 : 0;
			maxTypeCount = Math.max(maxTypeCount, curTypeCount + flag);
		}
		System.out.println(maxTypeCount);
	}
}