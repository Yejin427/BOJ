import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 궁수 세 명을 (rowSize, 0)~(rowSize, colSize-1)까지 배치 가능
 * 2. 3곳을 선택하는 중복조합을 dfs로 돌린다.
 * 	2-1. 매개변수로 lastIndex, depth를 받아서 depth가 3이면 궁수 선택이 완료된 것이다.
 * 3. 궁수를 모두 선택했다면 map 배열을 복사한 copyMap 배열을 두고 시뮬레이션얼 진행한다. (다음 궁수 선택 시 map이 그대로 남아있어야 하기 때문이다.)
 * 4. countKill 변수를 두고 궁수 세명이서 활을 쏘는 위치에 적이 있다면 증가시킨다.
 * 5. 적을 선택하는 기준이 거리 가까운 순 -> column이 낮은 순 
 * 	5-1. for문을  distance를 1부터 돌리고, 그 내부에 column을 -dis ~ +dis까지 돌리고 그 내부에 row를 돌리는 방식으로 해결했다.
 * 6. enemy 존재하면 -> 그 enemy 배열을 -1로 바꿔준다(바로 0으로 바꿀 시 중복 제거가 불가능하기 때문이다.)
 * 	6-1. enemy가 존재하지만 이미 -1이 된 곳이라면 -> countKill을 증가시키지 않는다.
 * 7. hasEnemy = true라면 해당 궁수의 공격이 종료되며, 적이 한 칸 내려간다.
 * 	7-1. 이 때 -1로 바꿔준  배열 칸들을 다시 0으로 바꿔준다.
 * 8. 이후 적이 있는지 판단 -> 없다면 시뮬레이션을 종료한다.
 * 9. countKill을 maxKill에 최댓값으로 update한다.
 * @author SSAFY
 *
 */
public class BOJ17135 {
	static int[][] map;
	static int rowSize, colSize, distance;
	static int[] attackerPos = new int[3];
	static int maxKill;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		
		rowSize = Integer.parseInt(st.nextToken());
		colSize = Integer.parseInt(st.nextToken());
		distance = Integer.parseInt(st.nextToken());
		map = new int[rowSize][colSize];
		for(int row = 0; row < rowSize; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int col = 0; col < colSize; col++) {
				map[row][col] = Integer.parseInt(st.nextToken());
			}
		}
		//궁수 3명이 있는 칸 정하기
		dfs(-1, 0);
		System.out.println(maxKill);
	}
	//2. 3곳을 선택하는 중복조합을 dfs로 돌린다.
	static void dfs(int lastIndex, int depth) {
		//2-1. 매개변수로 lastIndex, depth를 받아서 depth가 3이면 궁수 선택이 완료된 것이다.
		if(depth == 3) {
//			System.out.println(Arrays.toString(attackerPos));
			//3. 궁수를 모두 선택했다면 map 배열을 복사한 copyMap 배열을 두고 시뮬레이션얼 진행한다. (다음 궁수 선택 시 map이 그대로 남아있어야 하기 때문이다.)
			int[][] copyMap = new int[rowSize][colSize];
			for(int row = 0; row < rowSize; row++) {
				for(int col = 0; col < colSize; col++) {
					copyMap[row][col] = map[row][col];
				}
			}
			//궁수 3명 배치 완료 -> 공격
			//4. countKill 변수를 두고 궁수 세명이서 활을 쏘는 위치에 적이 있다면 증가시킨다.
			int countKill = 0;
			while(true) {
				for(int attackIndex = 0; attackIndex < 3; attackIndex++) {
					//가장 가까운 적 없애기
					// 5. 적을 선택하는 기준이 거리 가까운 순 -> column이 낮은 순 
					//5-1. for문을  distance를 1부터 돌리고, 그 내부에 column을 -dis ~ +dis까지 돌리고 그 내부에 row를 돌리는 방식으로 해결했다.
					boolean hasEnemy = false;
					for(int dis = 1; dis <= distance; dis++) {
						// hasEnemy = true라면 해당 궁수의 공격이 종료되며, 적이 한 칸 내려간다.
						if(hasEnemy) break;
						for(int col = -dis; col <= dis; col++) {
							if(hasEnemy) break;
							for(int row = -(dis-Math.abs(col)); row < 0; row++) {
								if(isInside(rowSize+row, attackerPos[attackIndex]+col) 
										&& copyMap[rowSize+row][attackerPos[attackIndex]+col] != 0) {
									hasEnemy = true;
									//6. enemy 존재하면 -> 그 enemy 배열을 -1로 바꿔준다(바로 0으로 바꿀 시 중복 제거가 불가능하기 때문이다.)
									if(copyMap[rowSize+row][attackerPos[attackIndex]+col] != -1) {
										copyMap[rowSize+row][attackerPos[attackIndex]+col] = -1;	//죽었지만 다른사람이 더 쏠 수도 있음
										countKill++;
									}
									//6-1. enemy가 존재하지만 이미 -1이 된 곳이라면 -> countKill을 증가시키지 않는다.
									break;
								}
							}
						}
					}
				}
				
				//공격 완료 -> 한칸 내리기
				for(int row = rowSize-1; row >= 0; row--) {
					for(int col = 0; col < colSize; col++) {
						if(copyMap[row][col] == 1) {
							if(row < rowSize-1) {
								copyMap[row+1][col] = 1;
							}
							copyMap[row][col] = 0;
						} else if(copyMap[row][col] == -1) {
							//7-1. 이 때 -1로 바꿔준  배열 칸들을 다시 0으로 바꿔준다.
							copyMap[row][col] = 0;
						}
					}
				}
				//8. 이후 적이 있는지 판단 -> 없다면 시뮬레이션을 종료한다.
				boolean enemyLeft = false;
				for(int row = rowSize-1; row >= 0; row--) {
					for(int col = 0; col < colSize; col++) {
						if(copyMap[row][col] == 1) {
							enemyLeft = true;
							break;
						}
					}
				}
				if(!enemyLeft) break;
			}
			//9. countKill을 maxKill에 최댓값으로 update한다.
			if(maxKill < countKill) {
				maxKill = Math.max(countKill, maxKill);
			}
			return;
		}
		for(int nxtIndex = lastIndex + 1; nxtIndex < colSize; nxtIndex++) {
			attackerPos[depth] = nxtIndex;
			dfs(nxtIndex, depth+1);
		}
	}
	static boolean isInside(int row, int col) {
		return 0 <= row && row < rowSize && 0 <= col && col < colSize;
	}
}