import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 각 원자의 정보를 저장하는 Atom class 생성, xpos, ypos, direction, energy 저장
 * 	1-1. comparable을 상속받아 x, y좌표대로 정렬할 수 있도록 한다.
 * 2. 입력받으면서 Atom을 atomList에 저장
 * 3. 각 원자의 이동 속도는 1이지만 0.5초 후에 겹칠 수도 있으므로 0.5씩 원자들을 고유 방향대로 움직여준다.
 * 4. 움직인 후 atomList를 정렬한다.
 * 5. 정렬 후 중복을 제거하는 함수 호출 후 atomList에 새로 할당해준다.
 * 6. removeDuplicates 함수 : 기준 index를 두고 뒤에것이 기준과 좌표가 같다면 count를 증가시킨다.
 * 	6-1. count가 1이면 중복이 없음 -> 새로운 list에 넣어주고, count가 1 이상이면 countEnergy에 더해준 에너지들을 answer에 더해준다.
 * 7. time을 1씩 증가시켜서 4000까지 돌린다. (만날 수 있는 두 원소의 최대 거리는 2000이고 0.5씩 증가시키므로 4000)
 * @author SSAFY
 *
 */
public class SWEA5648 {
	static int[][] map;
	static int[] dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
	static int answer;
	//1. 각 원자의 정보를 저장하는 Atom class 생성, xpos, ypos, direction, energy 저장
	static class Atom implements Comparable<Atom>{
		public double xpos, ypos;
		public int movedir, energy;

		public Atom(double xpos, double ypos, int movedir, int energy) {
			this.xpos = xpos;
			this.ypos = ypos;
			this.movedir = movedir;
			this.energy = energy;
		}

		//	1-1. comparable을 상속받아 x, y좌표대로 정렬할 수 있도록 한다.
		@Override
		public int compareTo(Atom o) {
			if(this.xpos == o.xpos) {
				return Double.compare(this.ypos, o.ypos);
			}
			return Double.compare(this.xpos, o.xpos);
		}

		@Override
		public String toString() {
			return "Atom [xpos=" + xpos + ", ypos=" + ypos + ", movedir=" + movedir + ", energy=" + energy + "]";
		}
		
	}
	static Atom[] atomList;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			map = new int[2001][2001];
			int atomSize = Integer.parseInt(st.nextToken());
			atomList = new Atom[atomSize];
			//2. 입력받으면서 Atom을 atomList에 저장
			for(int index = 0; index < atomSize; index++) {
				st = new StringTokenizer(br.readLine());
				double xpos = Double.parseDouble(st.nextToken());
				double ypos = Double.parseDouble(st.nextToken());
				int movedir = Integer.parseInt(st.nextToken());
				int energy = Integer.parseInt(st.nextToken());
				atomList[index] = new Atom(xpos, ypos, movedir, energy);
			}
			answer = 0;
			int time = 0;
			//7. time을 1씩 증가시켜서 4000까지 돌린다. (만날 수 있는 두 원소의 최대 거리는 2000이고 0.5씩 증가시키므로 4000)
			while(time++ <= 4000) {
				
				//3. 각 원자의 이동 속도는 1이지만 0.5초 후에 겹칠 수도 있으므로 0.5씩 원자들을 고유 방향대로 움직여준다.
				for(int index = 0; index < atomList.length; index++) {
					atomList[index].xpos += dx[atomList[index].movedir] * 0.5;
					atomList[index].ypos += dy[atomList[index].movedir] * 0.5;
				}
				//4. 움직인 후 atomList를 정렬한다.
				Arrays.sort(atomList);
				// 5. 정렬 후 중복을 제거하는 함수 호출 후 atomList에 새로 할당해준다.
				atomList = removeDuplicates(atomList);
			}
			System.out.printf("#%d %d\n", test, answer);
 		}
	}
	
	static Atom[] removeDuplicates(Atom[] list) {
		List<Atom> result = new ArrayList<>();
		int idx = 0;
		//6. removeDuplicates 함수 : 기준 index를 두고 뒤에것이 기준과 좌표가 같다면 count를 증가시킨다.
		while(idx < list.length) {
			int count = 1, countEnergy = list[idx].energy;
			while(idx + count < list.length && list[idx].xpos == list[idx + count].xpos 
					&& list[idx].ypos == list[idx+count].ypos) {
				countEnergy += list[idx+count].energy;
				count++;
			}
			//6-1. count가 1이면 중복이 없음 -> 새로운 list에 넣어주고, count가 1 이상이면 countEnergy에 더해준 에너지들을 answer에 더해준다.
			if(count == 1) {
				result.add(list[idx]);
			} else {
				answer += countEnergy;
			}
			idx += count;
		}
		return (Atom[]) result.toArray(new Atom[result.size()]);
	}
}