import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 한 지점에서 다음 지점으로 이동하려면 거리가 50X20 = 1000이하여야 한다.
 * 2. BFS로 탐색함. 처음에  queue에 home의 좌표를 넣는다.
 * 3. 편의점 배열들을 돌면서 아직 방문하지 않았거나 맨해튼 거리가 1000 이하면 방문 체크 후 큐에 넣는다.
 * 4. 만약 페스티벌까지의 거리가 1000이하면 페스티벌도 방문가능, 큐에 넣는다.
 * 5. queue에서 뽑은 좌표가 페스티벌에 좌표면 이동 가능하다.
 * @author SSAFY
 *
 */
public class BOJ9205 {
	static int[][] storePos;
	static int[] home, festival;
	static int storeSize;
	static boolean[] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		while(testCase-- > 0) {
			st = new StringTokenizer(br.readLine());
			storeSize = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			home = new int[2];
			home[0] = Integer.parseInt(st.nextToken());
			home[1] = Integer.parseInt(st.nextToken());
			storePos = new int[storeSize+1][2];
			for(int index = 1; index <= storeSize; index++) {
				st = new StringTokenizer(br.readLine());
				storePos[index][0] = Integer.parseInt(st.nextToken());
				storePos[index][1] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			festival = new int[2];
			festival[0] = Integer.parseInt(st.nextToken());
			festival[1] = Integer.parseInt(st.nextToken());
			visited = new boolean[storeSize+1];
			
			Queue<int[]> queue = new ArrayDeque<>();
			//2. BFS로 탐색함. 처음에  queue에 home의 좌표를 넣는다.
			queue.offer(new int[] {home[0], home[1]});
			String answer = "sad";
			while(!queue.isEmpty()) {
				int[] current = queue.poll();
				//5. queue에서 뽑은 좌표가 페스티벌에 좌표면 이동 가능하다.
				if(current[0] == festival[0] && current[1] == festival[1]) {
					answer = "happy";
					break;
				}
				for(int index = 1; index <= storeSize; index++) {
					//3. 편의점 배열들을 돌면서 아직 방문하지 않았거나 맨해튼 거리가 1000 이하면 방문 체크 후 큐에 넣는다.
					if(!visited[index] && Math.abs(current[0] - storePos[index][0]) + Math.abs(current[1] - storePos[index][1]) <= 1000) {
						visited[index] = true;
						queue.offer(new int[] {storePos[index][0], storePos[index][1]});
					}
				}
				//4. 만약 페스티벌까지의 거리가 1000이하면 페스티벌도 방문가능, 큐에 넣는다.
				if(Math.abs(current[0] - festival[0])+Math.abs(current[1] - festival[1]) <= 1000) {
					queue.offer(new int[] {festival[0], festival[1]});
				}
			}
			System.out.println(answer);
		}
		
	}
}