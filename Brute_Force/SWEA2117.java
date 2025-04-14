import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 입력받으면서 1을 입력받으면 homePos에 좌표를 추가해준다.
 * 2. 홈방범 서비스의 중심을 모든 (row, col)좌표를 돌리면서 현재 좌표 기준으로 집들의 거리를 distance 배열에 저장
 * 3. 거리 배열을 정렬
 * 4. 거리 배열을 돌면서 현재 index 집의 거리와 같은 거리에 있는 집들을 돌면서 index증가 
 * 	4-1. index가 현재 거리의 서비스를 설치했을 때 서비스를 받을 수 있는 집의 수임
 * 	4-2. 거리가 d일 때 k=d+1이므로 serviceSize를 1 증가
 * 5. price * index - (k*k+(k-1)*(k-1))이 0이상일때마다 houseCount를 index로 초기화
 * 6. answer에 houseCount의 최대값을 계속 update
 * @author SSAFY
 *
 */
public class SWEA2117 {
	static int[][] city;
	static List<int[]> homePos;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int citySize = Integer.parseInt(st.nextToken());
			int price = Integer.parseInt(st.nextToken());
			city = new int[citySize+1][citySize+1];
			homePos = new ArrayList<>();
			for(int row = 1; row <= citySize; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= citySize; col++) {
					city[row][col] = Integer.parseInt(st.nextToken());
					//1. 입력받으면서 1을 입력받으면 homePos에 좌표를 추가해준다.
					if(city[row][col] == 1) {
						homePos.add(new int[] {row, col});
					}
				}
			}
			int answer = 0;
			for(int row = 1; row <= citySize; row++) {
				for(int col = 1; col <= citySize; col++) {
					//2. 홈방범 서비스의 중심을 모든 (row, col)좌표를 돌리면서 현재 좌표 기준으로 집들의 거리를 distance 배열에 저장
					List<Integer> distance = new ArrayList<>();
					for(int[] pos: homePos) {
						distance.add(Math.abs(row-pos[0])+Math.abs(col-pos[1]));
					}
					//3. 거리 배열을 정렬
					Collections.sort(distance);
					int index = 0, houseCount = 0;
					while(index < distance.size()) {
						int serviceSize = distance.get(index);
						//4. 거리 배열을 돌면서 현재 index 집의 거리와 같은 거리에 있는 집들을 돌면서 index증가 
						//4-1. index가 현재 거리의 서비스를 설치했을 때 서비스를 받을 수 있는 집의 수임
						while(index < distance.size() && distance.get(index) == serviceSize) {
							index++;
						}
						//4-2. 거리가 d일 때 k=d+1이므로 serviceSize를 1 증가
						serviceSize++;
						//price * index - (k*k+(k-1)*(k-1))이 0이상일때마다 houseCount를 index로 초기화
						if(price * index - (serviceSize * serviceSize + (serviceSize-1) * (serviceSize-1)) >= 0) {
							houseCount = index;
						}
					}
					//6. answer에 houseCount의 최대값을 계속 update
					answer = Math.max(houseCount, answer);
				}
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
}