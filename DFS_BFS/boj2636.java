import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

/**
 * 1. while문을 한시간마다 돌리면서 totalTime을 올려준다.
 * 2. 현재 치즈에서 바깥을 체크해준다. (isOutside가 전에 치즈가 녹으면서 새로 추가된 부분만 체크해준다)
 * 	2-1. isOutside가 false고 cheese가 0일 때 새로운 outside의 후보가 될 수 있다.
 * 3. checkOutside 함수에서 현재 칸에서 테두리거나, 사방  중 하나라도 isOutside라면 새로 outside가 된다.
 * 4. outside가 되었다면 사방 중 새로운 outside 후보로 재귀를 돌린다. (2-1 조건과 같다)
 * 5. 재귀를 빠져나왔다면 cheese배열에서 사방 중 outside가 true인 것이 있다면 녹여준다
 * 6. 이후 녹은 이후 치즈를 currentCheeseCount에 세준다.
 * 7. 치즈가 0이면 while문을 break, 아니면 cheeseCount에 currentCheeseCount를 update해준다.
 * @author SSAFY
 *
 */
public class BOJ2636 {
	static int[][] cheese;
	static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	static boolean[][] isOutside;
	static int rowSize, colSize;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        rowSize = Integer.parseInt(st.nextToken());
        colSize = Integer.parseInt(st.nextToken());
        cheese = new int[rowSize+1][colSize+1]; 
        isOutside = new boolean[rowSize+1][colSize+1]; 
        int totalTime = 0;
        int cheeseCount = 0;
        for(int row = 1; row <= rowSize; row++) {
        	st = new StringTokenizer(br.readLine());
        	for(int column = 1; column <= colSize; column++) {
        		cheese[row][column] = Integer.parseInt(st.nextToken());
        		if(cheese[row][column] == 1) cheeseCount++;
        	}
        }
        
        while(true) {
        	//1. while문을 한시간마다 돌리면서 totalTime을 올려준다.
        	totalTime++;

        	//2. 현재 치즈에서 바깥을 체크해준다. (isOutside가 전에 치즈가 녹으면서 새로 추가된 부분만 체크해준다)
        	for(int row = 1; row <= rowSize; row++) {
            	for(int column = 1; column <= colSize; column++) {
            		//2-1. isOutside가 false고 cheese가 0일 때 새로운 outside의 후보가 될 수 있다.
            		if(cheese[row][column] == 0 && !isOutside[row][column]) {
            			checkOutside(row, column);
            		}
            	}
            }
        	//5. 재귀를 빠져나왔다면 cheese배열에서 사방 중 outside가 true인 것이 있다면 녹여준다
        	for(int row = 1; row <= rowSize; row++) {
            	for(int column = 1; column <= colSize; column++) {
            		if(cheese[row][column] == 0) continue;
            		boolean melt = false;
            		for(int dir = 0; dir < 4; dir++) {
            			if(isOutside[row + dx[dir]][column + dy[dir]]) {
            				melt = true;
            				break;
            			}
            		}
            		if(melt) cheese[row][column] = 0;
            	}
            }
        	//6. 이후 녹은 이후 치즈를 currentCheeseCount에 세준다.
        	int currentCheeseCount = 0;
        	for(int row = 1; row <= rowSize; row++) {
            	for(int column = 1; column <= colSize; column++) {
            		if(cheese[row][column] == 1) currentCheeseCount++;
            	}
            }
        	//7. 치즈가 0이면 while문을 break, 아니면 cheeseCount에 currentCheeseCount를 update해준다.
        	if(currentCheeseCount == 0) break;
        	cheeseCount = currentCheeseCount;
        }
        System.out.println(totalTime);
        System.out.println(cheeseCount);
	}
	//치즈가 없는 칸 중 isOutside 체크 안되어있는 칸 탐색
	//사방 중 한 곳이라도 outside면 outside임
	static void checkOutside(int startRow, int startCol) {
		//3. checkOutside 함수에서 현재 칸에서 테두리거나, 사방  중 하나라도 isOutside라면 새로 outside가 된다.
		for(int dir = 0; dir < 4; dir++) {
			int nextRow = startRow + dx[dir];
			int nextCol = startCol + dy[dir];
			if(nextRow < 1 || nextRow > rowSize || nextCol < 1 || nextCol > colSize || isOutside[nextRow][nextCol]) {
				isOutside[startRow][startCol] = true;
				break;
			}
		}
		if(!isOutside[startRow][startCol]) return;
		//4. outside가 되었다면 사방 중 새로운 outside 후보로 재귀를 돌린다. (2-1 조건과 같다)
		for(int dir = 0; dir < 4; dir++) {
			int nextRow = startRow + dx[dir];
			int nextCol = startCol + dy[dir];
			if(nextRow < 1 || nextRow > rowSize || nextCol < 1 || nextCol > colSize) continue;
			if(cheese[nextRow][nextCol] == 0 && !isOutside[nextRow][nextCol]) {
				checkOutside(nextRow, nextCol);
			}
		}
	}
}