import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/**
 * 1. 해당 달까지의 최소 비용값을 dp배열에 저장한다.
 * 2. 해당 달에 하루권을 사용, 1달권 사용, 3달권 사용 중 최소를 update
 * 3. 하루 권을 사용한다면 swimPlan만큼 곱해주고 전 달에 더한다. (만약 swimPlan이 0이라면 이 때 전 달과 같아지므로 최소다)
 * 4. 한달 권을 사용한다면 swimPlan 전 달에 oneMonth를 더한다. 
 * 5. month가 3 이상이면 세달 전 dp에서 threeMonth를 더한다.
 * 6. 마지막에 dp[12]를 oneYear랑 비교해서 최소 update
 * @author SSAFY
 *
 */
public class SWEA1952{
	static int oneDay, oneMonth, threeMonth, oneYear;
    static int swimPlan[] = new int[13];
    static int[] dp;
    static int minimumPrice;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            oneDay = Integer.parseInt(st.nextToken());
            oneMonth = Integer.parseInt(st.nextToken());
            threeMonth = Integer.parseInt(st.nextToken());
            oneYear = Integer.parseInt(st.nextToken());
            minimumPrice = Integer.MAX_VALUE;
             
            st = new StringTokenizer(br.readLine());
            for(int month = 1; month <= 12; month++) {
                swimPlan[month] = Integer.parseInt(st.nextToken());
            }
            dp = new int[13];
            for(int month = 1; month <= 12; month++) {
            	//3. 하루 권을 사용한다면 swimPlan만큼 곱해주고 전 달에 더한다. (만약 swimPlan이 0이라면 이 때 전 달과 같아지므로 최소다)
            	dp[month] = dp[month-1] + oneDay * swimPlan[month];
            	//4. 한달 권을 사용한다면 swimPlan 전 달에 oneMonth를 더한다. 
            	dp[month] = Math.min(dp[month-1] + oneMonth, dp[month]);
            	//5. month가 3 이상이면 세달 전 dp에서 threeMonth를 더한다.
            	if(month >= 3) dp[month] = Math.min(dp[month-3] + threeMonth, dp[month]);
            }
            //6. 마지막에 dp[12]를 oneYear랑 비교해서 최소 update
            dp[12] = Math.min(dp[12], oneYear);
            System.out.printf("#%d %d\n", test, dp[12]);
        }
    }
    
}