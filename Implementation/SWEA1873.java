import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 간단한 시뮬레이션 문제
 * 1. commandString을 순회하면서 명령어마다 그에 맞게 map 배열을 변경해준다.
 * 2. 전차가 움직이는 것에 dx, dy 배열을 사용한다 0, 1, 2, 3 index 각각 우, 하, 좌, 상 방향이다.
 * 3. U, D, L, R이 들어왔을 때 carDir을 바꿔주고 만약 한칸 이동했을 때 평지라면 carRow, carCol를 바꿔주고 차를 이동해준다.
 * 4. 만약 이동할 수 없는 곳이라면 현재 carRow, carCol의 map 상에서 기호만 바꿔준다.
 * 5. S입력 -> 현재방향으로 계속 전진하면서 순회 , 더이상 갈 수 없거나 강쳘 벽을 만났다면 순회 종료
 * 6. 벽돌 벽을 만났다면 벽을 .으로 바꾸고 순회 종료
 * @author SSAFY
 *
 */
public class SWEA1873{
	static char[][] map;
	//2. 전차가 움직이는 것에 dx, dy 배열을 사용한다 0, 1, 2, 3 index 각각 우, 하, 좌, 상 방향이다.
	static int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};	//우, 하, 좌, 상
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int height = Integer.parseInt(st.nextToken());
			int width = Integer.parseInt(st.nextToken());
			
			map = new char[height+1][width+1];
			int carRow = -1, carCol = -1, carDir = -1;
			for(int row = 1; row <= height; row++) {
				for(int col = 1; col <= width; col++) {
					map[row][col] = (char) br.read();
					if(map[row][col] == '^' || map[row][col] == 'v' || map[row][col] == '<' || map[row][col] == '>') {
						carRow = row; carCol = col;
						if(map[row][col] == '^') carDir = 3;
						else if(map[row][col] == 'v') carDir = 1;
						else if(map[row][col] == '<') carDir = 2;
						else carDir = 0;
					}
				}
				br.readLine();
			}
			
			st = new StringTokenizer(br.readLine());
			int length = Integer.parseInt(st.nextToken());
			String commandString = br.readLine();
			  
			for(int index = 0; index < length; index++) {
				int nxtPosRow = -1, nxtPosCol = -1;
				switch(commandString.charAt(index)) {
				case 'U':
					carDir = 3;
					nxtPosRow = carRow + dx[carDir];
					nxtPosCol = carCol + dy[carDir];
					//3. U, D, L, R이 들어왔을 때 carDir을 바꿔주고 만약 한칸 이동했을 때 평지라면 carRow, carCol를 바꿔주고 차를 이동해준다.
					if(1 <= nxtPosRow && nxtPosRow <= height 
							&& 1 <= nxtPosCol && nxtPosCol <= width && map[nxtPosRow][nxtPosCol] == '.') {
						map[carRow][carCol] = '.';
						carRow = nxtPosRow;
						carCol = nxtPosCol;
					}
					//4. 만약 이동할 수 없는 곳이라면 현재 carRow, carCol의 map 상에서 기호만 바꿔준다.
					map[carRow][carCol] = '^';
					break;
				case 'D':
					carDir = 1;
					nxtPosRow = carRow + dx[carDir];
					nxtPosCol = carCol + dy[carDir];
					if(1 <= nxtPosRow && nxtPosRow <= height 
							&& 1 <= nxtPosCol && nxtPosCol <= width && map[nxtPosRow][nxtPosCol] == '.') {
						map[carRow][carCol] = '.';
						carRow = nxtPosRow;
						carCol = nxtPosCol;
					}
					map[carRow][carCol] = 'v';
					break;
				case 'L':
					carDir = 2;
					nxtPosRow = carRow + dx[carDir];
					nxtPosCol = carCol + dy[carDir];
					if(1 <= nxtPosRow && nxtPosRow <= height 
							&& 1 <= nxtPosCol && nxtPosCol <= width && map[nxtPosRow][nxtPosCol] == '.') {
						map[carRow][carCol] = '.';
						carRow = nxtPosRow;
						carCol = nxtPosCol;
					}
					map[carRow][carCol] = '<';
					break;
				case 'R':
					carDir = 0;
					nxtPosRow = carRow + dx[carDir];
					nxtPosCol = carCol + dy[carDir];
					if(1 <= nxtPosRow && nxtPosRow <= height 
							&& 1 <= nxtPosCol && nxtPosCol <= width && map[nxtPosRow][nxtPosCol] == '.') {
						map[carRow][carCol] = '.';
						carRow = nxtPosRow;
						carCol = nxtPosCol;
					}
					map[carRow][carCol] = '>';
					break;
				default:
					//5. S입력 -> 현재방향으로 계속 전진하면서 순회 , 더이상 갈 수 없거나 강쳘 벽을 만났다면 순회 종료
					int currentRow = carRow;
					int currentColumn = carCol;
					while(true) {
						currentRow += dx[carDir];
						currentColumn += dy[carDir];
						if(currentRow < 1 || currentRow > height || currentColumn < 1 || currentColumn > width || map[currentRow][currentColumn] == '#') {
							break;
						}
						//6. 벽돌 벽을 만났다면 벽을 .으로 바꾸고 순회 종료
						if(map[currentRow][currentColumn] == '*') {
							map[currentRow][currentColumn] = '.';
							break;
						}
					}
					break;
				
				}
			}
			System.out.printf("#%d ", test);
			for(int row = 1; row <= height; row++) {
				for(int col = 1; col <= width; col++) {
					System.out.print(map[row][col]);
				}
				System.out.println();
			}
		}
	}
}