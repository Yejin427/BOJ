import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. baseballResult에 주어지는 입력을 저장한다. innningIndex를 0~n-1로 하며 타자들도 0번~8번 타자로 한다.
 * 2. 1번~9번 타자들의 순서를 정하는데 1번 타자의 순서는 4번 고정이므로 2~9번 타자들만 (여기서 1~8번) nextPermutation을 돌려준다.
 * 3. 각 permutationArray마다 야구 simulation을 돌려서 score를 확인하고 maxScore에 계속 update해준다.
 * 4. playBaseball 함수 -> return score
 * 	4-1. permutationArray의 3번 index에 0(1번타자)를 넣은 batOrder array 생성
 *  4-2. 변수 초기화 : 현재 타자 번수 index(currentBatterIndex), 1, 2, 3루타에 타자가 있는지 여부, 현재 점수(currentScore)
 *  4-3. inning을 돌면서 현재 타자의 주어진 결과에 따라 simulation을 진행한다. 
 *    4-3-1. out : out이 1추가됨
 *    4-3-2. 1, 2, 3루타 : 1, 2, 3base에 주자가 있다면 각각 한칸, 두칸, 세칸 진루한다. 만약 더 이상 진루할 base가 없다면 home으로 돌아오며 currentScore이 추가된다.
 *    4-3-3. 4(homreun) : 1, 2, 3base에 있는 주자가 모두 home으로 돌아오고 1점씩 먹는다.
 *    - 3번 base부터 처리해야 중간에 변수 초기화되는 일이 없다.
 *    4-3-4. currentBatterIndex를 1증가해준다. 8번 -> 0번으로 처리하기 위해 % 9를 해줌
 * @author SSAFY
 *
 */
public class BOJ17281 {
	static int baseballResult[][];
	static int permutationArray[];
	static int inningCount;
	static int maxScore;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		inningCount = Integer.parseInt(st.nextToken());
		baseballResult = new int[inningCount][9];
		permutationArray = new int[8];
		
		//1, 2, 3, 4, ..., 8까지 집어넣음 -> 정렬된 상태
		for(int inning = 1; inning < 9; inning++) {
			permutationArray[inning-1] = inning;
		}
		
		//* 1. baseballResult에 주어지는 입력을 저장한다. innningIndex를 0~n-1로 하며 타자들도 0번~8번 타자로 한다.
		for(int inning = 0; inning < inningCount; inning++) {
			st = new StringTokenizer(br.readLine());
			for(int batter = 0; batter < 9; batter++) {
				baseballResult[inning][batter] = Integer.parseInt(st.nextToken());
			}
		}
		
		//2. 1번~9번 타자들의 순서를 정하는데 1번 타자의 순서는 4번 고정이므로 2~9번 타자들만 (여기서 1~8번) nextPermutation을 돌려준다.
		do {
			//3. 각 permutationArray마다 야구 simulation을 돌려서 score를 확인하고 maxScore에 계속 update해준다.
			maxScore = Math.max(maxScore, playBaseball());
		} while(nextPermutation());
		
		System.out.println(maxScore);
	}
	
	static boolean nextPermutation() {
		int biggestIdx = 7;
		while(biggestIdx > 0 && permutationArray[biggestIdx-1] >= permutationArray[biggestIdx]) --biggestIdx;
		if(biggestIdx == 0) return false;

		int nxtBiggestIdx = 7;
		while(permutationArray[biggestIdx-1] >= permutationArray[nxtBiggestIdx]) --nxtBiggestIdx;
		
		swap(biggestIdx-1, nxtBiggestIdx);
		int swapIndex = 7;
		while(biggestIdx < swapIndex) swap(biggestIdx++, swapIndex--);
		
		return true;
	}

	
	static void swap(int leftIdx, int rightIdx) {
		int temp = permutationArray[leftIdx];
		permutationArray[leftIdx] = permutationArray[rightIdx];
		permutationArray[rightIdx] = temp;
	}
	
	//4. playBaseball 함수 -> return score
	static int playBaseball() {
		//1번을 포함한 batOrder array 생성
		int[] batOrder = new int[9];
		for(int index=0;index<3;index++) {
			batOrder[index] = permutationArray[index];
		}
		batOrder[3] = 0;
		for(int index = 4; index < 9; index++) {
			batOrder[index] = permutationArray[index-1];
		}
		
		//4-2. 변수 초기화 : 현재 타자 번수 index(currentBatterIndex), 1, 2, 3루타에 타자가 있는지 여부, 현재 점수(currentScore)
		//현재 타자 번수 (0부터 시작)
		int currentBatterIndex = 0;
		//각각 1, 2, 3루타에 타자가 존재하는지
		boolean firstBase = false, secondBase = false, thirdBase = false;
		//현재 스코어
		int currentScore = 0;
		for(int inning = 1; inning <= inningCount; inning++) {
			int out = 0;
			firstBase = false;
			secondBase = false; 
			thirdBase = false;
			while(out < 3) {
				switch(baseballResult[inning-1][batOrder[currentBatterIndex]]) {
				case 0:
					//4-3-1. out : out이 1추가됨
					out++;
					break;
				//4-3-2. 1, 2, 3루타 : 1, 2, 3base에 주자가 있다면 각각 한칸, 두칸, 세칸 진루한다. 만약 더 이상 진루할 base가 없다면 home으로 돌아오며 currentScore이 추가된다.
				// 3번 base부터 처리해야 중간에 변수 초기화되는 일이 없다.
				case 1:
					if(thirdBase) {
						currentScore++;
						thirdBase = false;
					}
					if(secondBase) {
						thirdBase = true;
						secondBase = false;
					}
					if(firstBase) {
						secondBase = true;
						firstBase = false;
					}
					firstBase = true;
					break;
				case 2:
					if(thirdBase) {
						currentScore++;
						thirdBase = false;
					}
					if(secondBase) {
						currentScore++;
						secondBase = false;
					}
					if(firstBase) {
						thirdBase = true;
						firstBase = false;
					}
					secondBase = true;
					break;
				case 3:
					if(thirdBase) {
						currentScore++;
						thirdBase = false;
					}
					if(secondBase) {
						currentScore++;
						secondBase = false;
					}
					if(firstBase) {
						currentScore++;
						firstBase = false;
					}
					thirdBase = true;
					break;
				default:
					//4-3-3. 4(homreun) : 1, 2, 3base에 있는 주자가 모두 home으로 돌아오고 1점씩 먹는다.
					if(thirdBase) {
						currentScore++;
						thirdBase = false;
					}
					if(secondBase) {
						currentScore++;
						secondBase = false;
					}
					if(firstBase) {
						currentScore++;
						firstBase = false;
					}
					currentScore++;
					break;
				}
				//4-3-4. currentBatterIndex를 1증가해준다. 8번 -> 0번으로 처리하기 위해 % 9를 해줌
				currentBatterIndex = (currentBatterIndex + 1) % 9;
			}
		}
		return currentScore;
	}	
}