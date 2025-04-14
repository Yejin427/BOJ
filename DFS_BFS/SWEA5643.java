import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 키순서를 알 수 있으려면 모든 노드에 대해서 자신보다 작은 지 자신보다 큰 지 알 수 있어야 함.
 * 2. 자신보다 큰 방향으로  direct하는 DG 하나(graph), 자신보다 작은 방향으로 direct하는 DG 하나(reverseGraph)를 둔다.
 * 3. 각 학생들을 for문으로 돌면서 자신으로 시작하는 dfs와 rdfs로 자신보다 큰 학생, 작은 학생을 탐색하고, visited를 체크한다.
 * 4. 이후 visited가 체크되지 않은 노드가 있다면 그 사람은 자신보다 큰 지, 작은 지 알 수 없다.
 * 5. visited가 모두 체크되었을 때 answer을 1 추가한다.
 * @author SSAFY
 *
 */
public class SWEA5643 {
	//자신보다 큰 방향으로  direct하는 DG 하나(graph), 자신보다 작은 방향으로 direct하는 DG 하나(reverseGraph)를 둔다.
	static List<Integer>[] graph;
	static List<Integer>[] reverseGraph;
	static boolean[] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int testCase = Integer.parseInt(br.readLine());
		for(int test = 1; test <= testCase; test++) {
			int studentSize = Integer.parseInt(br.readLine());
			int compareSize = Integer.parseInt(br.readLine());
			graph = new ArrayList[studentSize+1];
			reverseGraph = new ArrayList[studentSize+1];
			for(int index = 1; index <= studentSize; index++) {
				graph[index] = new ArrayList<>();
				reverseGraph[index] = new ArrayList<>();
			}
			
			while(compareSize-- > 0) {
				st = new StringTokenizer(br.readLine());
				int student1 = Integer.parseInt(st.nextToken());
				int student2 = Integer.parseInt(st.nextToken());
				graph[student1].add(student2);
				reverseGraph[student2].add(student1);
			}
			int answer = 0;
			for(int studentIndex = 1; studentIndex <= studentSize; studentIndex++) {
				//3. 각 학생들을 for문으로 돌면서 자신으로 시작하는 dfs와 rdfs로 자신보다 큰 학생, 작은 학생을 탐색하고, visited를 체크한다.
				visited = new boolean[studentSize+1];
				dfs(studentIndex);
				reverseDfs(studentIndex);
				
				boolean canDecide = true;
				for(int node = 1; node <= studentSize; node++) {
					//4. 이후 visited가 체크되지 않은 노드가 있다면 그 사람은 자신보다 큰 지, 작은 지 알 수 없다.
					if(!visited[node]) {
						canDecide = false;
						break;
					}
				}
				//5. visited가 모두 체크되었을 때 answer을 1 추가한다.
				if(canDecide) answer++;
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	static void dfs(int node) {
		visited[node] = true;
		for(int next: graph[node]) {
			if(!visited[next]) {
				dfs(next);
			}
		}
	}
	static void reverseDfs(int node) {
		visited[node] = true;
		for(int next: reverseGraph[node]) {
			if(!visited[next]) {
				reverseDfs(next);
			}
		}
	}
}