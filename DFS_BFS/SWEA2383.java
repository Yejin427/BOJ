import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 입력을 받으면서 계단 정보와 사람 정보를 저장한다.
 * 2. 먼저 dfs를 돌려 해당 index의 사람이 통해 0번계단과 1번 계단 중 선택한다.
 * 3. depth가 사람 size만큼 된다면 해당 계단까지의 거리를 구하고 각각 stair1, stair2에 저장
 * 4. stair1, stair2 정렬한다.
 * 5. 큐에 계단 내려간 직후의 시간을 저장한다.
 * 	5-1. 만약 queue size가 3이라면 queue 맨 앞의 값과 starttime을 비교한다.
 * 	5-2. 만약 맨 앞이 아직 내려가지 않았다면 큐에 맨 앞을 뽑고 맨앞이 다내려간시간 + 계단 내려가는 시간을 넣는다.
 * 6. 마지막 내려가는 시간이 답이며, stair1finish, stair2finish 중 큰 것이 답이다.
 * @author SSAFY
 *
 */
public class SWEA2383 {
	static int[][] room;
	static int[][] peoplePosition;
	static int[] stairArray;
	static List<int[]> stairInfo;
	static int peopleSize, answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int size = Integer.parseInt(st.nextToken());
			room = new int[size+1][size+1];
			peoplePosition = new int[10][2];
			stairInfo = new ArrayList<>();
			peopleSize = 0;
			answer = Integer.MAX_VALUE;
			
			for(int row = 1; row <= size; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= size; col++) {
					room[row][col] = Integer.parseInt(st.nextToken());
					if(room[row][col] >= 2) {
						stairInfo.add(new int[] {room[row][col], row, col});
					} else if(room[row][col] == 1) {
						peoplePosition[peopleSize][0] = row;
						peoplePosition[peopleSize++][1] = col;
					}
				}
			}
			stairArray = new int[peopleSize];
			dfs(0);
			System.out.printf("#%d %d\n",test,answer);
		}
	}
	
	static void dfs(int depth) {
		if(depth == peopleSize) {
			List<Integer> stair1 = new ArrayList<>();
			List<Integer> stair2 = new ArrayList<>();
			for(int index = 0; index < peopleSize; index++) {
				int distance = Math.abs(peoplePosition[index][0] - stairInfo.get(stairArray[index])[1])
						+ Math.abs(peoplePosition[index][1] - stairInfo.get(stairArray[index])[2]);
				if(stairArray[index] == 0) stair1.add(distance);
				else stair2.add(distance);
			}
			Collections.sort(stair1);
			Collections.sort(stair2);
			
			//stair1 simulation 시작
			int stair1finish = 0, stair2finish = 0;
			Queue<Integer> queue1 = new ArrayDeque<>();
			for(int dis: stair1) {
				if(queue1.size() == 3) {
					if(dis >= queue1.peek()) {	
						queue1.offer(dis + stairInfo.get(0)[0] + 1);
					} else {
						int waitAfter = queue1.poll();
						queue1.offer(waitAfter + stairInfo.get(0)[0]);
					}
				} else {
					queue1.offer(dis + stairInfo.get(0)[0] + 1);
				}
			}
			while(!queue1.isEmpty()) {
				stair1finish = queue1.poll();
			}
			Queue<Integer> queue2 = new ArrayDeque<>();
			for(int dis: stair2) {
				if(queue2.size() == 3) {
					if(dis >= queue2.peek()) {	
						queue2.offer(dis + stairInfo.get(1)[0] + 1);
					} else {
						int waitAfter = queue2.poll();
						queue2.offer(waitAfter + stairInfo.get(1)[0]);
					}
				} else {
					queue2.offer(dis + stairInfo.get(1)[0] + 1);
				}
			}
			while(!queue2.isEmpty()) {
				stair2finish = queue2.poll();
			}
			answer = Math.min(Math.max(stair1finish, stair2finish), answer);
			
			return;
		}
		stairArray[depth] = 0;
		dfs(depth+1);
		stairArray[depth] = 1;
		dfs(depth+1);
	}
}