import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 인접 리스트(contactGraph), 방문체크 배열(visited), 연락 받는 순서(depth)를 저장한다.
 * 2. contactGraph from index에 to 추가한다.
 * 3. bfs를 통해 그래프를 순회하면서 자식 index의 depth를 부모 index depth + 1로 저장한다.
 * 4. 순회하면서 최대 depth를 저장한다.
 * 5. 마지막으로 순회하면서 depth가 최대 depth와 같다면 answerNode를 초기화한다. (최대 index node를 저장할 수 있다.)
 * @author SSAFY
 *
 */
public class SWEA1238 {
	//1. 인접 리스트(contactGraph), 방문체크 배열(visited), 연락 받는 순서(depth)를 저장한다.
	static ArrayList<Integer>[] contactGraph;
	static boolean visited[];
	static int depth[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int test = 1; test <= 10; test++) {
			st = new StringTokenizer(br.readLine());
			int edgeSize = Integer.parseInt(st.nextToken());
			int startNode = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			//graph 관련 배열 메모리 초기화
			contactGraph = new ArrayList[101];
			visited = new boolean[101];
			depth = new int[101];
			for(int node = 1; node <= 100; node++) {
				contactGraph[node] = new ArrayList<>();
			}
			
			//2. contactGraph from index에 to 추가한다.
			for(int edge = 1; edge <= edgeSize; edge+=2) {
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				
				contactGraph[from].add(to);
			}
			Queue<Integer> queue = new ArrayDeque<>();
			queue.offer(startNode);
			visited[startNode] = true;
			depth[startNode] = 1;
			int maxDepth = 1;
			//3. bfs를 통해 그래프를 순회하면서 자식 index의 depth를 부모 index depth + 1로 저장한다.
			while(!queue.isEmpty()) {
				int curNode = queue.poll();
				for(int child: contactGraph[curNode]) {
					if(visited[child]) continue;
					queue.offer(child);
					visited[child] = true;
					depth[child] = depth[curNode] + 1;
					//4. 순회하면서 최대 depth를 저장한다.
					maxDepth = Math.max(maxDepth, depth[child]);
				}
			}
			//5. 마지막으로 순회하면서 depth가 최대 depth와 같다면 answerNode를 초기화한다. (최대 index node를 저장할 수 있다.)
			int answerNode = -1;
			for(int node = 1; node <= 100; node++) {
				if(depth[node] == maxDepth) {
					answerNode = node;
				}
			}
			System.out.printf("#%d %d\n", test, answerNode);
		}
	}

}