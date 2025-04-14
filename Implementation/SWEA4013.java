import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 자석 배열을 입력받는다.
 * 2. 시계방향, 반시계방향 회전을 구현한다.(rotate 함수)
 * 	2-1. 시계방향 -> 마지막 index를 빼서 앞에 삽입, 반시계방향 -> 첫번째 index를 빼서 맨 뒤에 삽입
 * 3. 왼쪽의 2번 index와 오른쪽의 6번 index가 맞물리게 되며 만약 이 둘이 다르다면 이전 바퀴의 반대 방향으로 회전이 전파된다.
 * 	3-1. clock flag 변수를 두어 회전의 전파될때마다 이를 토글해서 회전한다.
 * 	3-2. 1번 회전 : 2->3->4로 전파,  4번 회전 : 3->2->1로 전파
 * 	3-3. 2번 회전 : 1, 3->4로 전파, 3번 회전 : 2->1, 4로 전파
 * 4. 중복회전하지 않도록 스택의 형태로 나중에 회전되는 것 확인 후 나중 것을 먼저 회전시킨다.
 * @author SSAFY
 *
 */
public class SWEA4013 {
	static int[][] magnet;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			magnet = new int[4][8];
			st = new StringTokenizer(br.readLine());
			int rotate = Integer.parseInt(st.nextToken());
			
			for(int magNum = 0; magNum < 4;magNum++) {
				st = new StringTokenizer(br.readLine());
				for(int nal = 0; nal < 8; nal++) {
					magnet[magNum][nal] = Integer.parseInt(st.nextToken());
				}
			}
			//시계방향 -> 뒤에서 빼서 앞에 삽입, 반시계방향 -> 앞에서 빼서 뒤에 삽입
			//1번의 2 - 2번의 6// 2번의 2 - 3번의 6 //3번의 2 - 4번의 6
			while(rotate-- > 0) {
				st = new StringTokenizer(br.readLine());
				int magnetNum = Integer.parseInt(st.nextToken());
				int rotateDir = Integer.parseInt(st.nextToken());
				boolean clock = rotateDir == 1;
				
				if(magnetNum == 1) {
					if(magnet[0][2] != magnet[1][6]) {
						if(magnet[1][2] != magnet[2][6]) {
							if(magnet[2][2] != magnet[3][6]) {
								rotate(!clock, magnet[3]);
							}
							rotate(clock, magnet[2]);
						}
						rotate(!clock, magnet[1]);
					}
					rotate(clock, magnet[0]);
				} 
				else if(magnetNum == 2) {
					if(magnet[1][2] != magnet[2][6]) {
						if(magnet[2][2] != magnet[3][6]) {
							rotate(clock, magnet[3]);
						}
						rotate(!clock, magnet[2]);
					}
					if(magnet[0][2] != magnet[1][6]) {
						rotate(!clock, magnet[0]);
					}
					rotate(clock, magnet[1]);
				}
				else if(magnetNum == 3) {
					if(magnet[2][2] != magnet[3][6]) {
						rotate(!clock, magnet[3]);
					}
					if(magnet[1][2] != magnet[2][6]) {
						if(magnet[0][2] != magnet[1][6]) {
							rotate(clock, magnet[0]);
						}
						rotate(!clock, magnet[1]);
					}
					rotate(clock, magnet[2]);
				}
				else {
					if(magnet[3][6] != magnet[2][2]) {
						if(magnet[2][6] != magnet[1][2]) {
							if(magnet[1][6] != magnet[0][2]) {
								rotate(!clock, magnet[0]);
							}
							rotate(clock, magnet[1]);
						}
						rotate(!clock, magnet[2]);
					}
					rotate(clock, magnet[3]);
				}
			}
			System.out.printf("#%d %d\n", test, magnet[0][0] + magnet[1][0] * 2 + magnet[2][0] * 4 + magnet[3][0] * 8);
		}
	}
	static void rotate(boolean clockwise, int[] magnetArr) {
		if(clockwise) {
			int last = magnetArr[7];
			for(int index = 6; index >= 0; index--) {
				magnetArr[index+1] = magnetArr[index];
			}
			magnetArr[0] = last;
		} else {
			int first = magnetArr[0];
			for(int index = 0; index <= 6; index++) {
				magnetArr[index] = magnetArr[index+1];
			}
			magnetArr[7] = first;
		}
	}
}