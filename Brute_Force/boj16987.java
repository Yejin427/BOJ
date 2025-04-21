import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 계란 배열 eggInfo[index][0] : 해당 index 계란의 내구도, eggInfo[index][1] : 해당 index 계란의 무게
 * 2. 자기 자신이 아니며 아직 깨지지 않은 계란 중 하나를 깬다. (가지치기)
 * 3. 다음 칠 계란은 현재 index + 1부터 순회하여 아직 내구도가 양수인 계란을 고른다 -> findNextEgg함수
 * 4. 계란을 친 결과 두 개 깨졌다면 eggBreak + 2, 한 개 깨졌다면 eggBreak + 1, 깨지지 않았다면 eggBreak를 다음 재귀로 넘겨준다.
 * 5. hitIndex가 eggNum을 넘어서거나 현재 hitIndex가 있지만 칠 다음 계란이 없는 경우 -> maxBreakCount를 update하고 return.
 */
public class BOJ16987 {
    //1. 계란 배열 eggInfo[index][0] : 해당 index 계란의 내구도, eggInfo[index][1] : 해당 index 계란의 무게
    static int[][] eggInfo = new int[9][2];
    static int eggNum;
    static int maxBreakCount;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        eggNum = Integer.parseInt(st.nextToken());
        for(int index = 1; index <= eggNum; index++) {
            st = new StringTokenizer(br.readLine());
            eggInfo[index][0] = Integer.parseInt(st.nextToken());
            eggInfo[index][1] = Integer.parseInt(st.nextToken());
        }
        eggSimulation(1, 0);
        System.out.println(maxBreakCount);
    }

    static void eggSimulation(int hitIndex, int eggBreak) {
        //hitIndex가 eggNum을 넘어섬 -> maxBreakCount를 update하고 return.
        if(hitIndex > eggNum) {
            maxBreakCount = Math.max(eggBreak, maxBreakCount);
            return;
        }
        boolean hasNextEgg = false;
        for(int nxtIndex = 1; nxtIndex <= eggNum; nxtIndex++) {
            //2. 자기 자신이 아니며 아직 깨지지 않은 계란 중 하나를 깬다. (가지치기)
            if(nxtIndex != hitIndex && eggInfo[nxtIndex][0] > 0) {
                hasNextEgg = true;
                eggInfo[nxtIndex][0] -= eggInfo[hitIndex][1];
                eggInfo[hitIndex][0] -= eggInfo[nxtIndex][1];
                //4. 계란을 친 결과 두 개 깨졌다면 eggBreak + 2, 한 개 깨졌다면 eggBreak + 1, 깨지지 않았다면 eggBreak를 다음 재귀로 넘겨준다.
                if(eggInfo[nxtIndex][0] <= 0 && eggInfo[hitIndex][0] <= 0) {
                    eggSimulation(findNextEgg(hitIndex), eggBreak + 2);
                } else if(eggInfo[nxtIndex][0] > 0 && eggInfo[hitIndex][0] > 0) {
                    eggSimulation(findNextEgg(hitIndex), eggBreak);
                } else {
                    eggSimulation(findNextEgg(hitIndex), eggBreak + 1);
                }

                eggInfo[nxtIndex][0] += eggInfo[hitIndex][1];
                eggInfo[hitIndex][0] += eggInfo[nxtIndex][1];
            }
        }
        //hitIndex가 있지만 칠 다음 계란이 없는 경우 -> maxBreakCount를 update하고 return.
        if(!hasNextEgg) {
            maxBreakCount = Math.max(eggBreak, maxBreakCount);
            return;
        }
    }
    //3. 다음 칠 계란은 현재 index + 1부터 순회하여 아직 내구도가 양수인 계란을 고른다 -> findNextEgg함수
    static int findNextEgg(int currentIndex) {
        for(int nxtindex = currentIndex + 1; nxtindex <= eggNum; nxtindex++) {
            if(eggInfo[nxtindex][0] > 0) return nxtindex;
        }
        return eggNum + 1;
    }
}