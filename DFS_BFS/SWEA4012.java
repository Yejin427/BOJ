import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. 재료들을 딱 절반으로 나누어서 조합들의 시너지를 구해야 한다.
 * 2. 재료 조합드을 구하는 것으로 combination을 사용한다. nC(n/2)
 * 3. combinationArray을 ingredientCount / 2 만큼 할당한다.
 * 4. combination을 수행하면서 selectedIndex == ingredientCount/2가 되었을 때 해당 조합의 시너지를 구한다.
 * 	4-1. 선택된 것을 a에 넣고, 선택되지 않은 것들을 b에 조합한다.
 *  4-2. 선택된 것들의 index를 저장하고 선택되지 않은 것들을 notSelected 배열에 넣는다.
 *  4-3. combinationArray와 notSelected를 순회하면서 두 개를 선택하고 시너지에 S[i][j] + S[j][i]를 더해준다.
 *  4-4. answer에 aSynergy-bSynergy를 Math.min으로 계속 update해준다.
 * @author SSAFY
 *
 */
public class SWEA4012 {
	static int synergy[][];
	static int combinationArray[];
	static int ingredientSize;
	static int answer;
	static void combination(int lastIndex, int selectedIndex) {
		//4. combination을 수행하면서 selectedIndex == ingredientCount/2가 되었을 때 해당 조합의 시너지를 구한다.
		if(selectedIndex == ingredientSize / 2) {
			// * 4-1. 선택된 것을 a에 넣고, 선택되지 않은 것들을 b에 조합한다.
			// * 4-2. 선택된 것들의 index를 저장하고 선택되지 않은 것들을 notSelected 배열에 넣는다.
			boolean currentSelected[] = new boolean[ingredientSize+1];
			for(int number: combinationArray) currentSelected[number] = true;
			int notSelected[] = new int[ingredientSize / 2];
			int index = 0;
			for(int num = 1; num <= ingredientSize; num++) {
				if(!currentSelected[num]) {
					notSelected[index++] = num;
				}
			}
			
			// 4-3. combinationArray와 notSelected를 순회하면서 두 개를 선택하고 시너지에 S[i][j] + S[j][i]를 더해준다.
			int aSynergy = 0, bSynergy = 0;
			for(int firstIndex = 0; firstIndex < ingredientSize / 2; firstIndex++) {
				for(int secondIndex = firstIndex + 1; secondIndex < ingredientSize / 2; secondIndex++) {
					aSynergy += synergy[combinationArray[firstIndex]][combinationArray[secondIndex]]
							+ synergy[combinationArray[secondIndex]][combinationArray[firstIndex]];
				}
			}
			
			for(int firstIndex = 0; firstIndex < ingredientSize / 2; firstIndex++) {
				for(int secondIndex = firstIndex + 1; secondIndex < ingredientSize / 2; secondIndex++) {
					bSynergy += synergy[notSelected[firstIndex]][notSelected[secondIndex]]
							+ synergy[notSelected[secondIndex]][notSelected[firstIndex]];
				}
			}
			//4-4. answer에 aSynergy-bSynergy를 Math.min으로 계속 update해준다.
			answer = Math.min(answer, Math.abs(aSynergy - bSynergy));
			return;
		}
		for(int nxtIndex = lastIndex + 1; nxtIndex <= ingredientSize; nxtIndex++) {
			combinationArray[selectedIndex] = nxtIndex;
			combination(nxtIndex, selectedIndex + 1);
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int test = Integer.parseInt(st.nextToken());
		for(int testCase = 1; testCase <= test; testCase++) {
			st = new StringTokenizer(br.readLine());
			ingredientSize = Integer.parseInt(st.nextToken());
			synergy = new int[17][17];
			answer = Integer.MAX_VALUE;
			
			//3. combinationArray을 ingredientCount / 2 만큼 할당한다.
			combinationArray = new int[ingredientSize/2];
			for(int row = 1; row <= ingredientSize; row++) {
				st = new StringTokenizer(br.readLine());
				for(int col = 1; col <= ingredientSize; col++) {
					synergy[row][col] = Integer.parseInt(st.nextToken());
				}
			}

			combination(0, 0);
			System.out.printf("#%d %d\n", testCase, answer);
		}
	}

}