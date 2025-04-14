import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 회사 -> 여러 멤버의 집 -> 집을 가는데 멤버들의 집을 방문하는 순서를 permutation으로 해결
 * 2. permutation 함수에 현재까지 방문한 멤버 수 : depth, 직전에 방문한 집 index : lastVisitedIndex, 현재까지 방문한 거리 : currentDistance를 매개변수로 넘김
 * 	2-1. 직전 방문 집을 넘겨줘야 댜음 집까지의 거리를 계산할 수 있다.
 * 3. 마지막 집을 모두 방문한 후 : (depth == size) => 현재까지의 거리와 집까지의 거리를 더해주고 answer를 최소로 update한다.
 * @author SSAFY
 *
 */
public class SWEA1247 {
	static class Point{
		public int x,y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
	}
	static Point[] member;
	static boolean[] visited;
	static int memberSize;
	static int answer;
	static Point company, home;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			memberSize = Integer.parseInt(st.nextToken());
			member = new Point[memberSize + 1];
			visited = new boolean[memberSize + 1];
			answer = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			company = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			home = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			member[0] = company;
			for(int index = 1; index <= memberSize; index++) {
				member[index] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			permutation(0, 0, 0);
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	/**
	 * 1. 회사 -> 여러 멤버의 집 -> 집을 가는데 멤버들의 집을 방문하는 순서를 permutation으로 해결
	 * @param depth :  현재까지 방문한 멤버 수
	 * @param lastVisitedIndex : 직전에 방문한 집 index
	 * @param currentDistance : 현재까지 방문한 거리
	 */
	static void permutation(int depth, int lastVisitedIndex, int currentDistance) {
		//3. 마지막 집을 모두 방문한 후 : (depth == size) => 현재까지의 거리와 집까지의 거리를 더해주고 answer를 최소로 update한다.
		if(depth == memberSize) {
			answer = Math.min(answer, currentDistance + Math.abs(member[lastVisitedIndex].x - home.x) 
			+ Math.abs(member[lastVisitedIndex].y - home.y));
		}
		for(int nxtMemberIndex = 1; nxtMemberIndex <= memberSize; nxtMemberIndex++) {
			if(!visited[nxtMemberIndex]) {
				visited[nxtMemberIndex] = true;
				//2-1. 직전 방문 집을 넘겨줘야 댜음 집까지의 거리를 계산할 수 있다.
				permutation(depth + 1, nxtMemberIndex, currentDistance + Math.abs(member[lastVisitedIndex].x - member[nxtMemberIndex].x) 
				+ Math.abs(member[lastVisitedIndex].y - member[nxtMemberIndex].y));
				visited[nxtMemberIndex] = false;
			}
		}
	}
}