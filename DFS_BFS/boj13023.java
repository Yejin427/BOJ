import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. 그래프 탐색을 통해 한 줄로 이어진 5개의 노드가 있는지 찾아야한다.
 * 2. startNode를 1부터 size까지 돌려서 거기서부터 dfs를 돌린다.
 * 	2-1. size가 최대 2000이므로 O(n^2)을 해도 무방하다.
 * 3. dfs를 0부터 시작했을 때 4까지 depth가 도달할 수 있다면 abcde가 존재하는 것이다.
 * 	3-1. 이때 사이클이 발생할 수 있으므로 노드 방문마다 방문체크를 해주어야한다.
 * 	3-2. 현재 경로에서 abcde를 만들지 못했어도 이 노드가 다음 경로에 쓰여 abcde를 만들 수 있기 때문에 visited를 false로 바꾼다.
 * @author SSAFY
 *
 */
public class BOJ13023 {
	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	static boolean abcde;
	static void dfs(int depth, int node) {
		//3. dfs를 0부터 시작했을 때 4까지 depth가 도달할 수 있다면 abcde가 존재하는 것이다.
		if(depth == 4) {
			abcde = true;
			return;
		}
		for(int next: graph[node]) {
			//3-1. 이때 사이클이 발생할 수 있으므로 노드 방문마다 방문체크를 해주어야한다.
			if(!visited[next]) {
				visited[node] = true;
				dfs(depth + 1, next);
				//3-2. 현재 경로에서 abcde를 만들지 못했어도 이 노드가 다음 경로에 쓰여 abcde를 만들 수 있기 때문에 visited를 false로 바꾼다.
				visited[node] = false;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int size = Integer.parseInt(st.nextToken());
        int relation = Integer.parseInt(st.nextToken());
        graph = new ArrayList[size+1];
        visited = new boolean[size+1];
        for(int index = 0; index <= size; index++) {
        	graph[index] = new ArrayList<>();
        }
        while(relation-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	int person1 = Integer.parseInt(st.nextToken());
        	int person2 = Integer.parseInt(st.nextToken());
        	graph[person1].add(person2);
        	graph[person2].add(person1);
        }
        //2. startNode를 1부터 size까지 돌려서 거기서부터 dfs를 돌린다.
        
        //2-1. size가 최대 2000이므로 O(n^2)을 해도 무방하다.
        for(int startPerson = 1; startPerson <= size; startPerson++) {
        	Arrays.fill(visited, false);
        	visited[startPerson] = true;
        	dfs(0, startPerson);
        	if(abcde) break;
        }
        System.out.printf("%d", abcde ? 1 : 0);
	}
}