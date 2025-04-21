import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 쿼리의 최대 개수가 크므로 각 쿼리에 대해 해당 숫자가 있는 지 여부를 비트로 표시한다.
 * 1. 1, 2, ..., 20을 각각 2진법으로 2^0, 2^1...2^19까지로 표시한다.
 * 2. add x : 1<<(x-1) (x-1번째 bit만 1임)을 or 연산해주면 bit의 x번째가 1로 표시된다.
 * 3. remove x : (1<<20)-1 - (1<<(x-1)) (x-1번째 bit만 0임)을 and 연산해준다.
 * 4. check x : 현재 bit에 1<<(x-1)을 &연산 했을 때 0이면 없고 0이 아니면 있다
 * 5. toggle x : 1<<(x-1)을 xor 연산해주면 0->1, 1->0으로 toggle 된다.
 * 6. all : bit를 1<<20-1 (모든자리가 1임)으로 bit 초기화
 * 7. empty : bit를 0으로 초기화
 */
public class BOJ11723 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int queryCount = Integer.parseInt(st.nextToken());
        int currentBit = 0;
        while(queryCount > 0) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            int num;
            switch (command){
                case "add":
                    //2. add x : 1<<(x-1) (x-1번째 bit만 1임)을 or 연산해주면 bit의 x번째가 1로 표시된다.
                    num = Integer.parseInt(st.nextToken());
                    currentBit |= (1 << (num-1));
                    break;
                case "remove":
                    //3. remove x : (1<<20)-1 - (1<<(x-1)) (x-1번째 bit만 0임)을 and 연산해준다.
                    num = Integer.parseInt(st.nextToken());
                    currentBit &= ((1<<20)-1 - (1<<(num-1)));
                    break;
                case "check":
                    //check x : 현재 bit에 1<<(x-1)을 &연산 했을 때 0이면 없고 0이 아니면 있다
                    num = Integer.parseInt(st.nextToken());
                    if((currentBit & (1 << (num-1))) != 0){
                        sb.append(1).append("\n");
                    } else {
                        sb.append(0).append("\n");
                    }
                    break;
                case "toggle":
                    //toggle x : 1<<(x-1)을 xor 연산해주면 0->1, 1->0으로 toggle 된다.
                    num = Integer.parseInt(st.nextToken());
                    currentBit ^= (1 << (num-1));
                    break;
                case "all":
                    //all : bit를 1<<20-1 (모든자리가 1임)으로 bit 초기화
                    currentBit = ((1<<20)-1);
                    break;
                default:
                    //7. empty : bit를 0으로 초기화
                    currentBit = 0;
                    break;
            }
            queryCount--;
        }
        System.out.println(sb);
    }
}