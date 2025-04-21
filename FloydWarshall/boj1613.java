import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. 플로이드-워셜로 두 선후관계가 명확한지 확인
 * 2. 처음에 dist를 모두 -1로 초기화 입력받으면서 dist[prev][next] = 1로 초기화
 * 3. 경유지, 출발지, 도착지를 돌면서 만약 출발-경유, 경유-도착이 모두 연결되어있다면 해당 출발-도착지는 연결되어 있는 것임
 * 4. 이후 dist[prev][next]가 1이면 prev가 먼저 dist[next][prev]면 next가 먼저, 둘다 아니면 알 수 없는 것임.
 * @author SSAFY
 *
 */
public class BOJ1613 {
	static int[][] dist;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int size = Integer.parseInt(st.nextToken());
		int relation = Integer.parseInt(st.nextToken());
		dist = new int[size+1][size+1];
		for(int index = 1; index <= size; index++) {
			Arrays.fill(dist[index], -1);
		}
		while(relation-- > 0) {
			//2. 처음에 dist를 모두 -1로 초기화 입력받으면서 dist[prev][next] = 1로 초기화
			st = new StringTokenizer(br.readLine());
			int prev = Integer.parseInt(st.nextToken());
			int next = Integer.parseInt(st.nextToken());
			dist[prev][next] = 1;
		}
		for(int via = 1; via <= size; via++) {
			for(int start = 1; start <= size; start++) {
				for(int end = 1; end <= size; end++) {
					//3. 경유지, 출발지, 도착지를 돌면서 만약 출발-경유, 경유-도착이 모두 연결되어있다면 해당 출발-도착지는 연결되어 있는 것임
					if(dist[start][via] == 1 && dist[via][end] == 1) {
						dist[start][end] = 1;
					}
				}
			}
		}
		int query = Integer.parseInt(br.readLine());
		while(query-- > 0) {
			//4. 이후 dist[prev][next]가 1이면 prev가 먼저 dist[next][prev]면 next가 먼저, 둘다 아니면 알 수 없는 것임.
			st = new StringTokenizer(br.readLine());
			int prev = Integer.parseInt(st.nextToken());
			int next = Integer.parseInt(st.nextToken());
			
			if(dist[prev][next] == 1) {
				sb.append(-1).append('\n');
			} else if(dist[next][prev] == 1) {
				sb.append(1).append('\n');
			} else {
				sb.append(0).append('\n');
			}
		}
		System.out.println(sb);
	}
}