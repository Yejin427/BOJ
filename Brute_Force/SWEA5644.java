import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. dx, dy 배열을 주어지는 방향 index에 맞게 초기화 시켜준다. (0,0), (-1, 0), (0, 1), (1, 0), (0, -1)
 * 2. 충전기 객체 생성 : x,y좌료와 range, performance를 가짐
 * 3. aPosX, aPosY, bPosX, bPosY 변수를 시간에 따라 변화시키면서 현재 위치에서 충전할 수 있는 최대치를 반환하는 함수를 호출한다.
 * 4. getCurrentMaxSum 함수
 * 	4-1. 충전기들을 순회하면서 A, B의 위치에서 현재 공유기와의 거리, range를 비교 후 범위 내에 있다면 canChargeA, canChargeB에 추가한다.
 * 	4-2. 만약 canChargeA, canChargeB 둘 중 하나가 비었다면 나머지 배열만 순회해서 performance maximum 값을 리턴한다.
 * 	4-3. 만약 canChargeA, canChargeB 둘 다 차있다면 -> 둘 다 순회하면서 두 공유기를 택했을 때 performance 합을 구하고 최댓값에 업데이트한다.
 * 	4-4. 이 때 두 공유기의 index가 같다면 그냥 해당 공유기의 performance만을 더한다. (둘이 충전해도 한 명분밖에 충전할 수 없음)
 * @author SSAFY
 *
 */
public class SWEA5644 {
	static int[] aMoveDir;
	static int[] bMoveDir;
	static BC[] bcArray;
	//1. dx, dy 배열을 주어지는 방향 index에 맞게 초기화 시켜준다. (0,0), (-1, 0), (0, 1), (1, 0), (0, -1)
	static int[] dx = {0, -1, 0, 1, 0}, dy = {0, 0, 1, 0, -1};
	//2. 충전기 객체 생성 : x,y좌료와 range, performance를 가짐
	static class BC{
		public int x, y, range, performance;

		public BC(int x, int y, int range, int performance) {
			this.x = x;
			this.y = y;
			this.range = range;
			this.performance = performance;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int moveTime = Integer.parseInt(st.nextToken());
			int bcNum = Integer.parseInt(st.nextToken());
			int aPosX = 1, aPosY = 1, bPosX = 10, bPosY = 10;
			
			aMoveDir = new int[moveTime+1];
			bMoveDir = new int[moveTime+1];
			bcArray = new BC[bcNum+1];
			st = new StringTokenizer(br.readLine());
			for(int aIdx = 0; aIdx < moveTime; aIdx++) aMoveDir[aIdx] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int bIdx = 0; bIdx < moveTime; bIdx++) bMoveDir[bIdx] = Integer.parseInt(st.nextToken());
			
			for(int bcIdx = 0; bcIdx < bcNum; bcIdx++) {
				st = new StringTokenizer(br.readLine());
				int col = Integer.parseInt(st.nextToken());
				int row = Integer.parseInt(st.nextToken());
				bcArray[bcIdx] = new BC(row, col, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			//3. aPosX, aPosY, bPosX, bPosY 변수를 시간에 따라 변화시키면서 현재 위치에서 충전할 수 있는 최대치를 반환하는 함수를 호출한다
			int answer = getCurrentMaxSum(aPosX, aPosY, bPosX, bPosY, bcNum);
			for(int time = 0; time < moveTime; time++) {
				aPosX += dx[aMoveDir[time]];
				aPosY += dy[aMoveDir[time]];
				bPosX += dx[bMoveDir[time]];
				bPosY += dy[bMoveDir[time]];
				answer += getCurrentMaxSum(aPosX, aPosY, bPosX, bPosY, bcNum);
			}
			System.out.printf("#%d %d\n", test, answer);
		}
	}
	static int getCurrentMaxSum(int aPosX, int aPosY, int bPosX, int bPosY, int bcNum) {
		List<Integer> canChargeA = new ArrayList<>();
		List<Integer> canChargeB = new ArrayList<>();
		//4-1. 충전기들을 순회하면서 A, B의 위치에서 현재 공유기와의 거리, range를 비교 후 범위 내에 있다면 canChargeA, canChargeB에 추가한다.
		for(int bcIdx = 0; bcIdx < bcNum; bcIdx++) {
			if(Math.abs(aPosX - bcArray[bcIdx].x) + Math.abs(aPosY - bcArray[bcIdx].y) <= bcArray[bcIdx].range) {
				canChargeA.add(bcIdx);
			}
			if(Math.abs(bPosX - bcArray[bcIdx].x) + Math.abs(bPosY - bcArray[bcIdx].y) <= bcArray[bcIdx].range) {
				canChargeB.add(bcIdx);
			}
		}
		int duplicateMaxSum = 0;
		//4-2. 만약 canChargeA, canChargeB 둘 중 하나가 비었다면 나머지 배열만 순회해서 performance maximum 값을 리턴한다.
		if(canChargeA.size() == 0 && canChargeB.size() != 0) {
			for(int dupB: canChargeB) {
				duplicateMaxSum = Math.max(duplicateMaxSum, bcArray[dupB].performance);
			}
		}
		else if(canChargeA.size() != 0 && canChargeB.size() == 0) {
			for(int dupA: canChargeA) {
				duplicateMaxSum = Math.max(duplicateMaxSum, bcArray[dupA].performance);
			}
		}
		//4-3. 만약 canChargeA, canChargeB 둘 다 차있다면 -> 둘 다 순회하면서 두 공유기를 택했을 때 performance 합을 구하고 최댓값에 업데이트한다.
		for(int dupA: canChargeA) {
			for(int dupB: canChargeB) {
				if(dupA == dupB) {
					//4-4. 이 때 두 공유기의 index가 같다면 그냥 해당 공유기의 performance만을 더한다. (둘이 충전해도 한 명분밖에 충전할 수 없음)
					duplicateMaxSum = Math.max(bcArray[dupA].performance, duplicateMaxSum);
				} else {
					duplicateMaxSum = Math.max(bcArray[dupA].performance + bcArray[dupB].performance, duplicateMaxSum);
				}
			}
		}
		return duplicateMaxSum;
	}
}