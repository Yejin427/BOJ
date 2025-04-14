import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 최대한 제곱근 연산을 빨리, 많이 하는 방향으로 계산해야 한다.
 * 2. 현재 수의 제곱근을 구한 후 만약 정수가 아니라면 => (sqrt + 1)^2에서 현재 수를 뺀만큼 +1 연산을 해야한다.
 * 3. N이 10^12로 큰 만큼 도달할 때까지 while문을 통해 +1연산 하지 않고 한번에 count를 제곱수 도달할 때까지 더해준다.
 * 4. 제곱근이라면 sqrt 연산 한번 후 count 1증가
 */
public class SWEA6782 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            long target = Long.parseLong(st.nextToken());
            long count = 0;
            while(target != 2) {
                long sqrt = (long)Math.sqrt(target);
                //2. 현재 수의 제곱근을 구한 후 만약 정수가 아니라면 => (sqrt + 1)^2에서 현재 수를 뺀만큼 +1 연산을 해야한다.
                if(Math.sqrt(target) != sqrt) {
                    //3. N이 10^12로 큰 만큼 도달할 때까지 while문을 통해 +1연산 하지 않고 한번에 count를 제곱수 도달할 때까지 더해준다.
                    count += ((sqrt+1) * (sqrt+1) - target);
                    target = (sqrt+1) * (sqrt+1);
                } else {
                    //4. 제곱근이라면 sqrt 연산 한번 후 count 1증가
                    target = (long) Math.sqrt(target);
                    count++;
                }
            }
            System.out.printf("#%d %d\n", test, count);
        }
    }
}