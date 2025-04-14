import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. for문을 0을 먹었을 때 ~ 최대 맛인 값(maxValue)로 순회해서 bfs를 돌린다.
 * 2. queue에 row, column 쌍을 넣어주기 위해 Point 객체를 선언한다.
 * 3. bfs에 현재 row, column값과 taste값도 넘겨줘서 bfs로 다음 칸을 갈 때 taste 값보다 낮은 칸은 이미 먹은 곳이므로 걸러준다.
 * 4. bfs를 처음 호출한 횟수만큼 덩어리가 있는 것임 -> count를 1씩 더해줌
 * 5. answer에 count의 최댓값을 계속 update함
 * 6. visited 배열은 taste가 증가할 때마다 초기화 해주어야 한다.
 * @author SSAFY
 *
 */
public class SWEA7733 {
	static int cheese[][];
	static boolean visited[][];
	static int size;
	static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	//2. queue에 row, column 쌍을 넣어주기 위해 Point 객체를 선언한다.
	static class Point{
		public int row, column;

		public Point(int row, int column) {
			this.row = row;
			this.column = column;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int testCase = Integer.parseInt(st.nextToken());
        
        for(int test = 1; test <= testCase; test++) {
        	st = new StringTokenizer(br.readLine());
        	size = Integer.parseInt(st.nextToken());
        	
        	cheese = new int[size+1][size+1];
        	int maxValue = 0;
        	for(int row = 1; row <= size; row++) {
        		st = new StringTokenizer(br.readLine());
        		for(int col = 1; col <= size; col++) {
        			cheese[row][col] = Integer.parseInt(st.nextToken());
        			maxValue = Math.max(cheese[row][col], maxValue);
        		}
        	}
        	int answer = 0;
        	//1. for문을 0을 먹었을 때 ~ 최대 맛인 값(maxValue)로 순회해서 bfs를 돌린다.
        	for(int taste = 0; taste <= maxValue; taste++) {
        		int count = 0;
        		//6. visited 배열은 taste가 증가할 때마다 초기화 해주어야 한다.
        		visited = new boolean[size+1][size+1];
        		for(int row = 1; row <= size; row++) {
            		for(int col = 1; col <= size; col++) {
            			if(visited[row][col] || cheese[row][col] <= taste) continue;
            			//4. bfs를 처음 호출한 횟수만큼 덩어리가 있는 것임 -> count를 1씩 더해줌
            			count++;
            			bfs(row, col, taste);
            		}
            	}
        		//answer에 count의 최댓값을 계속 update함
        		answer = Math.max(answer, count);
        	}
        	System.out.printf("#%d %d", test, answer);
        }
	}
	//3. bfs에 현재 row, column값과 taste값도 넘겨줘서 bfs로 다음 칸을 갈 때 taste 값보다 낮은 칸은 이미 먹은 곳이므로 걸러준다.
	static void bfs(int startRow, int startColumn, int taste) {
		Queue<Point> que = new ArrayDeque<>();
		que.offer(new Point(startRow, startColumn));
		visited[startRow][startColumn] = true;
		while(!que.isEmpty()) {
			Point current = que.poll();
			for(int dir = 0; dir < 4; dir++) {
				int nextRow = current.row + dx[dir];
				int nextColumn = current.column + dy[dir];
				if(nextRow < 1 || nextRow > size || nextColumn < 1 || nextColumn > size 
						|| visited[nextRow][nextColumn] || cheese[nextRow][nextColumn] <= taste) continue;
				visited[nextRow][nextColumn] = true;
				que.add(new Point(nextRow, nextColumn));
			}
		}
	}
}