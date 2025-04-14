import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * 1. 움직이는 방향으로 만약에 같은 수가 있다면 합치고, 합친 부분은 한쪽은 *2, 밀린 쪽은 0이 된다.
 * 2. tmpArray에 합치고 밀린 수들을 다 담고 나중에 map에 update해준다.
 * 	2-1. 한 세로줄(up, down), 가로 줄(left, right)의 수들을 tmpArray에 0을 제외하고 담아준다. ex) 2 2 0 4 0 -> 2 2 4 0 0
 * 	2-2. tmpArray에 담아둔 수 중 up, left는 앞에서부터, down, right는 뒤에서부터 두개씩 봤을 때 같은 수가 있다면 합쳐준다
 * 		2-2-1. 만약 같은 수여서 합쳤다면 pointer를 2씩 빼고, 아니면 pointer를 1만 뺀다.
 * 		2 2 4 0 0 --> 4 0 4 0 0 (합쳐서 없어진 쪽은 0으로 채운다)
 * 	2-3ㅣtmpArray의 수들을 다시 map에 채운다. tmpArray가 0인 부분은 빼고 채워준다.
 * @author SSAFY
 *
 */
public class SWEA6109 {
	static int[][] map;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int size = Integer.parseInt(st.nextToken());
			String command = st.nextToken();
			
			map = new int[size+1][size+1];
			for(int row = 1; row <= size; row++) {
				st = new StringTokenizer(br.readLine());
				for(int column = 1; column <= size; column++) {
					map[row][column] = Integer.parseInt(st.nextToken());
				}
			}
			if(command.equals("up")) {
				//일단 빈 곳이 없게 다 밀어준다.
				//2-1. 한 세로줄(up, down), 가로 줄(left, right)의 수들을 tmpArray에 0을 제외하고 담아준다. ex) 2 2 0 4 0 -> 2 2 4 0 0
				for(int col = 1; col <= size; col++) {
					int[] tmpArray = new int[size+1];
					int tmpIdx = 1;
					for(int row = 1; row <= size; row++) {
						if(map[row][col] != 0) tmpArray[tmpIdx++] = map[row][col];
					}
					//2-2-1. 만약 같은 수여서 합쳤다면 pointer를 2씩 빼고, 아니면 pointer를 1만 뺀다.
					int rowIdx = 1;
					while(rowIdx < size) {
						if(tmpArray[rowIdx] == tmpArray[rowIdx+1]) {
							tmpArray[rowIdx] *= 2;
							tmpArray[rowIdx+1] = 0;
							rowIdx += 2;
						} else {
							rowIdx++;
						}
					}
					//2-3ㅣtmpArray의 수들을 다시 map에 채운다. tmpArray가 0인 부분은 빼고 채워준다.
					int idx = 1;
					for(int row = 1; row <= size; row++) {
						while(idx <= size && tmpArray[idx] == 0) idx++;
						map[row][col] = idx <= size ? tmpArray[idx++] : 0;
					}
				}
				
				
			} else if(command.equals("down")) {
				for(int col = 1; col <= size; col++) {
					int[] tmpArray = new int[size+1];
					int tmpIdx = size;
					for(int row = size; row >= 1; row--) {
						if(map[row][col] != 0) tmpArray[tmpIdx--] = map[row][col];
					}
					int rowIdx = size;
					while(rowIdx > 1) {
						if(tmpArray[rowIdx] == tmpArray[rowIdx-1]) {
							tmpArray[rowIdx] *= 2;
							tmpArray[rowIdx-1] = 0;
							rowIdx -= 2;
						} else {
							rowIdx--;
						}
					}
					int idx = size;
					for(int row = size; row >= 1; row--) {
						while(idx >= 1 && tmpArray[idx] == 0) idx--;
						map[row][col] = idx >= 1 ? tmpArray[idx--] : 0;
					}
				}
				
			} else if(command.equals("left")) {
				for(int row = 1; row <= size; row++) {
					int[] tmpArray = new int[size+1];
					int tmpIdx = 1;
					for(int col = 1; col <= size; col++) {
						if(map[row][col] != 0) tmpArray[tmpIdx++] = map[row][col];
					}
					int colIdx = 1;
					while(colIdx < size) {
						if(tmpArray[colIdx] == tmpArray[colIdx+1]) {
							tmpArray[colIdx] *= 2;
							tmpArray[colIdx+1] = 0;
							colIdx += 2;
						} else {
							colIdx++;
						}
					}
					int idx = 1;
					for(int col = 1; col <= size; col++) {
						while(idx <= size && tmpArray[idx] == 0) idx++;
						map[row][col] = idx <= size ? tmpArray[idx++] : 0;
					}
				}
				
			} else {
				for(int row = 1; row <= size; row++) {
					int[] tmpArray = new int[size+1];
					int tmpIdx = size;
					for(int col = size; col >= 1; col--) {
						if(map[row][col] != 0) tmpArray[tmpIdx--] = map[row][col];
					}
					int colIdx = size;
					while(colIdx > 1) {
						if(tmpArray[colIdx] == tmpArray[colIdx-1]) {
							tmpArray[colIdx] *= 2;
							tmpArray[colIdx-1] = 0;
							colIdx -= 2;
						} else {
							colIdx--;
						}
					}
					int idx = size;
					for(int col = size; col >= 1; col--) {
						while(idx >= 1 && tmpArray[idx] == 0) idx--;
						map[row][col] = idx >= 1 ? tmpArray[idx--] : 0;
					}
				}
				
			}
			System.out.println("#"+test);
			for(int row = 1; row <= size; row++) {
				for(int column = 1; column <= size; column++) {
					System.out.printf("%d ", map[row][column]);
				}
				System.out.println();
			}
		}
	}
}