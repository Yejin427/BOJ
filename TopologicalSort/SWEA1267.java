import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;
/**
 * 위상정렬
 * 1. topology 배열 : 선-후가 주어졌을 때 후의 index를 1추가한다.
 * 2. graph 2차원 배열 : 선 index 배열에 후index를 추가한다.
 * 3. 현재 topology값이 0인 것들을 queue에 추가한다.
 * 4. queue를 돌면서 현재 값을 출력하고 현재 값의 after를 순회하면서 after의 topology 를 1씩 빼준다.
 * 5. topology를 빼서 0이 되었다면 이제 나올 수 있음 -> queue에 추가해준다.
 * @author SSAFY
 *
 */
public class SWEA1267{
	static int[] topology;
	static ArrayList<Integer>[] graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int test = 1; test <= 10; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			StringBuilder sb = new StringBuilder();
			int vertex = Integer.parseInt(st.nextToken());
			int edge = Integer.parseInt(st.nextToken());
			topology = new int[vertex+1];
			graph = new ArrayList[vertex+1];
			for(int index = 0; index <= vertex; index++) {
				graph[index] = new ArrayList<>();
			}
			st = new StringTokenizer(br.readLine());
			while(edge-- > 0) {
				int first = Integer.parseInt(st.nextToken());
				int second = Integer.parseInt(st.nextToken());
				graph[first].add(second);
				topology[second]++;
			}
			Queue<Integer> que = new ArrayDeque<>();
			for(int num = 1; num <= vertex; num++) {
				if(topology[num] == 0) que.offer(num);
			}
			sb.append("#").append(test);
			while(!que.isEmpty()) {
				int currentEdge = que.poll();
				sb.append(" ").append(currentEdge);
				for(int nextEdge: graph[currentEdge]) {
					if(--topology[nextEdge] == 0) que.offer(nextEdge);
				}
			}
			System.out.println(sb);
		}
	}
}