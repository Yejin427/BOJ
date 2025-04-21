import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 입력받으면서 치킨의 좌표와 집의 좌표들을 저장한다.
 * 2. 치킨 집의 좌표를 부분집합으로 돌면서 해당 index 선택 /비선택의 dfs를 돌린다.
 * 	2-1. 재귀를 돌면서 해당 index 치킨집을 남긴다면 pickArray를 1로 저장한다. 
 * 3. 모든  치킨집의 index를 돌았다면 각 집을 기준으로 치킨 거리를 계산하고 도시치킨거리에 더한다.
 * 4. 최솟값을 계속 갱신한다.
 * @author SSAFY
 *
 */
public class BOJ15686 {
	static int[][] city;
	static List<int[]> chicken = new ArrayList<>();
	static List<int[]> house = new ArrayList<>();
	static int[] pickArray;
	static int answer, size, pickSize;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		size = Integer.parseInt(st.nextToken());
		pickSize = Integer.parseInt(st.nextToken());
		
		city = new int[size+1][size+1];
		answer = Integer.MAX_VALUE;
		for(int row = 1; row <= size; row++) {
			st = new StringTokenizer(br.readLine());
			for(int col = 1; col <= size; col++) {
				city[row][col] = Integer.parseInt(st.nextToken());
				//1. 입력받으면서 치킨의 좌표와 집의 좌표들을 저장한다.
				if(city[row][col] == 1) {
					house.add(new int[] {row, col});
				} else if(city[row][col] == 2) {
					chicken.add(new int[] {row, col});
				}
			}
		}
		pickArray = new int[chicken.size()];
		dfs(0, 0);
		System.out.println(answer);
	}
	public static void dfs(int lastIndex, int pickedCount) {
		//3. 모든  치킨집의 index를 돌았다면 각 집을 기준으로 치킨 거리를 계산하고 도시치킨거리에 더한다.
		if(lastIndex == chicken.size()) {
			int cityDistance = 0;
			if(pickedCount > 0) {
				for(int[] housePos: house) {
					int chickenDistance = Integer.MAX_VALUE;
					for(int chickenIndex = 0; chickenIndex < chicken.size(); chickenIndex++) {
						if(pickArray[chickenIndex] == 1) {
							chickenDistance = Math.min(chickenDistance, 
									Math.abs(housePos[0] - chicken.get(chickenIndex)[0]) + Math.abs(housePos[1] - chicken.get(chickenIndex)[1]));
						}
					}
					cityDistance += chickenDistance;
				}
				//4. 최솟값을 계속 갱신한다.
				answer = Math.min(cityDistance, answer);
			}
			return;
		}
		//2. 치킨 집의 좌표를 부분집합으로 돌면서 해당 index 선택 /비선택의 dfs를 돌린다.
		dfs(lastIndex + 1, pickedCount);
		if(pickedCount < pickSize) {
			//2-1. 재귀를 돌면서 해당 index 치킨집을 남긴다면 pickArray를 1로 저장한다. 
			pickArray[lastIndex] = 1;
			dfs(lastIndex + 1, pickedCount + 1);
			pickArray[lastIndex] = 0;
		}
	}
}