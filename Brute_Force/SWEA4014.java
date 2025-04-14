import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. inserted : 경사로를 설치했다면 true로 표시하는 배열
 * 2. 한 줄을 돌면서 전의 높이와 같다면 curHeighLength를 추가, 다르다면 경사로 로직 수행
 * 	2-1. 한 칸 오르막 : 여태까지 curHeight를  확인하고 활주로 길이보다 작으면 불가능
 * 		 이전 길이가 길어도 이전에 내리막을 설치했던 곳과 겹치면 불가능 
 * 	2-2. 한 칸 내리막 : for문으로 이후 높이를 탐색하며 같은 길이가 활주로 길이 이상으로 있는지 확인 & inserted true로
 * 		만약 이후를 탐색하다가 평평한 길이가 활주로 이하거나 범위를 넘어가면 불가능
 * @author SSAFY
 *
 */
public class SWEA4014 {
	static int[][] map;
	static boolean[][] inserted;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int testCase = Integer.parseInt(st.nextToken());
		
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int mapSize = Integer.parseInt(st.nextToken());
			int length = Integer.parseInt(st.nextToken());
			map = new int[mapSize+1][mapSize+1];
			
			for(int row = 1; row <= mapSize; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= mapSize; col++) {
					map[row][col] = Integer.parseInt(st.nextToken());
				}
			}
			//row 확인
			int answer = 0;
			for(int row = 1; row <= mapSize; row++) {
				int curHeightLength = 1;
				boolean canAdd = true;
				inserted = new boolean[mapSize+1][mapSize+1];
				
				for(int col = 2; col <= mapSize; col++) {
					if(map[row][col] == map[row][col-1]) {
						curHeightLength++;
					}
					else {
						//오르막으로 바뀐다면? -> 올라가는 순간 이전 k개에 설치
						if(map[row][col] == map[row][col-1] + 1) {
							if(curHeightLength < length) {
								canAdd = false;
								break;
							} else {
								for(int colidx = col-1; colidx >= col - length; colidx--) {
									if(inserted[row][colidx]) {
										canAdd = false;
										break;
									}
									inserted[row][colidx] = true;
								}
							}
						}
						else if(map[row][col] == map[row][col-1] - 1) {
							for(int colidx = col; colidx < col + length; colidx++) {
								if(colidx > mapSize || map[row][colidx] != map[row][col]) {
									canAdd = false;
									break;
								}
								inserted[row][colidx] = true;
							}
						}
						else {
							canAdd = false;
							break;
						}
						curHeightLength = 1;
					}
				}
				answer += canAdd ? 1 : 0;
			}
			//col 확인
			for(int col = 1; col <= mapSize; col++) {
				int curHeightLength = 1;
				boolean canAdd = true;
				inserted = new boolean[mapSize+1][mapSize+1];
				
				for(int row = 2; row <= mapSize; row++) {
					if(map[row-1][col] == map[row][col]) {
						curHeightLength++;
					}
					else {
						//오르막으로 바뀐다면? -> 올라가는 순간 이전 k개에 설치
						if(map[row][col] == map[row-1][col] + 1) {
							if(curHeightLength < length) {
								canAdd = false;
								break;
							} else {
								for(int rowidx = row-1; rowidx >= row - length; rowidx--) {
									if(inserted[rowidx][col]) {
										canAdd = false;
										break;
									}
									inserted[rowidx][col] = true;
								}
							}
						}
						else if(map[row][col] == map[row-1][col] - 1) {
							for(int rowidx = row; rowidx < row + length; rowidx++) {
								if(rowidx > mapSize || map[rowidx][col] != map[row][col]) {
									canAdd = false;
									break;
								}
								inserted[rowidx][col] = true;
							}
						}
						else {
							canAdd = false;
							break;
						}
						curHeightLength = 1;
					}
				}
//				if(canAdd) System.out.printf("%d ", col);
				answer += canAdd ? 1 : 0;
			}
			System.out.printf("#%d %d\n", test, answer);
		}
		
	}
}