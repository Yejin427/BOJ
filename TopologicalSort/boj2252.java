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
 * 2. after 2차원 배열 : 선 index 배열에 후index를 추가한다.
 * 3. 현재 topology값이 0인 것들을 queue에 추가한다.
 * 4. queue를 돌면서 현재 값을 출력하고 현재 값의 after를 순회하면서 after의 topology 를 1씩 빼준다.
 * 5. topology를 빼서 0이 되었다면 이제 나올 수 있음 -> queue에 추가해준다.
 * @author SSAFY
 *
 */
public class BOJ2252 {
	//1. topology 배열 : 선-후가 주어졌을 때 후의 index를 1추가한다.
	static int[] topology;
	//2. after 2차원 배열 : 선 index 배열에 후index를 추가한다.
	static ArrayList<Integer>[] after;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int size = Integer.parseInt(st.nextToken());
		int query = Integer.parseInt(st.nextToken());
		topology = new int[size+1];
		after = new ArrayList[size+1];
		for(int index = 1; index <= size; index++) {
			after[index] = new ArrayList<Integer>();
		}
		while(query-- > 0) {
			st = new StringTokenizer(br.readLine());
			int first = Integer.parseInt(st.nextToken());
			int second = Integer.parseInt(st.nextToken());
			after[first].add(second);
			topology[second]++;
		}
		
		Queue<Integer> que = new ArrayDeque<>();
		//3. 현재 topology값이 0인 것들을 queue에 추가한다.
		for(int num = 1; num <= size; num++) {
			if(topology[num] == 0) que.offer(num);
		}
		while(!que.isEmpty()) {
			int current = que.poll();
			sb.append(current).append(" ");
			//4. queue를 돌면서 현재 값을 출력하고 현재 값의 after를 순회하면서 after의 topology 를 1씩 빼준다.
			for(int next: after[current]) {
				if(--topology[next] == 0) {
					//5. topology를 빼서 0이 되었다면 이제 나올 수 있음 -> queue에 추가해준다.
					que.offer(next);
				}
			}
		}
		System.out.println(sb);
	}
}