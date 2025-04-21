import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. Knapsack문제로 해결
 * 2. dp[i][j] : i번째까지 과목을 봤을 때 j의 시간으로 얻을 수 있는 최대 중요도.
 * 3. subject를 돌고 그 안에서 시간을 0~최대시간까지 돌면서 만약 현재 과목의 시간이 현재 time보다 길다면
 *  3-1. dp[index][time] = dp[index-1][time-subject[index][1]] + subject[index][0]
 */
public class BOJ17845 {
    static int[][] subject;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int maxStudy = Integer.parseInt(st.nextToken());
        int subjectNum = Integer.parseInt(st.nextToken());

        subject = new int[subjectNum+1][2];
        for(int index = 1; index <= subjectNum; index++) {
            st = new StringTokenizer(br.readLine());
            subject[index][0] = Integer.parseInt(st.nextToken());
            subject[index][1] = Integer.parseInt(st.nextToken());
        }
        dp = new int[subjectNum+1][maxStudy+1];
        for(int index = 1; index <= subjectNum; index++) {
            for(int time = 0; time <= maxStudy; time++) {
                dp[index][time] = dp[index-1][time];
                if(time >= subject[index][1]) {
                    dp[index][time] = Math.max(dp[index][time], dp[index-1][time-subject[index][1]] + subject[index][0]);
                }
            }
        }
        System.out.println(dp[subjectNum][maxStudy]);
    }
}