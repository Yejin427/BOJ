import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 6팀이 모든 팀과 한번씩 경기했을 때 가능한 월드컵 결과를 naive하게 구한다.
 * 2. 경우의 수 : 3^15 (각 대진에 대해 승, 패, 무)
 * 3. resultTmpArray로 재귀를 돌리면서 가능한 결과를 저장한다.
 * 4. team1과 상대할 team2를 증가시키며 team1 = 4, team2 = 5일 때 resultTmpArray와 resultQuery의 값들을 비교한다.
 * 5. 만약 모두 같다면 answer[queryIndex] = true로 저장한다.
 * 6. 하나라도 틀리면 isSame 변수를 false로 바꾸고 for문을 즉시 종료한다.
 */
public class BOJ6987 {
    static int[][][] resultQuery = new int[4][6][3];
    static int[][] resultTmpArray = new int[6][3];
    static boolean[] answer = new boolean[4];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int queryIndex = 0; queryIndex < 4; queryIndex++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int team = 0; team < 6; team++) {
                for(int resIdx = 0; resIdx < 3; resIdx++) {
                    resultQuery[queryIndex][team][resIdx] = Integer.parseInt(st.nextToken());
                }
            }
        }
        gameSimulation(0, 0);
        for(int queryIndex = 0; queryIndex < 4; queryIndex++) {
            System.out.printf("%d ", answer[queryIndex] ? 1 : 0);
        }
    }
    static void gameSimulation(int team1, int team2) {
        if(team1 == 4 && team2 == 5) {
            for(int queryIndex = 0; queryIndex < 4; queryIndex++) {
                boolean isSame = true;
                for(int team = 0; team < 6; team++) {
                    if(!isSame) break;
                    for(int resIdx = 0; resIdx < 3; resIdx++) {
                        if(resultQuery[queryIndex][team][resIdx] != resultTmpArray[team][resIdx]) {
                            //하나라도 틀리면 isSame 변수를 false로 바꾸고 for문을 즉시 종료한다.
                            isSame = false;
                            break;
                        }
                    }
                }
                if(isSame) {
                    //만약 모두 같다면 answer[queryIndex] = true로 저장한다.
                    answer[queryIndex] = true;
                }
            }
            return;
        }
        //team1과 상대할 team2를 증가시키며 team1 = 4, team2 = 5일 때 resultTmpArray와 resultQuery의 값들을 비교한다.
        if(team2 < 5) team2++;
        else {
            team1++;
            team2 = team1+1;
        }
        //team1이 team2에 이김
        resultTmpArray[team1][0]++; resultTmpArray[team2][2]++;
        gameSimulation(team1, team2);
        resultTmpArray[team1][0]--; resultTmpArray[team2][2]--;

        //team2가 team1에 이김
        resultTmpArray[team1][2]++; resultTmpArray[team2][0]++;
        gameSimulation(team1, team2);
        resultTmpArray[team1][2]--; resultTmpArray[team2][0]--;

        //team1, team2비김
        resultTmpArray[team1][1]++; resultTmpArray[team2][1]++;
        gameSimulation(team1, team2);
        resultTmpArray[team1][1]--; resultTmpArray[team2][1]--;
    }
}