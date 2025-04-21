import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 한자리, 두자리 ... 8자리 차례로 소수 확인 후 소수면 다음 재귀 진행
 * 2. 다음 자리로 갈 때 0~9가 뒤에 붙는다고 할 때 이전 수에 10을 곱하고, 그 뒤에 0~9를 붙인다
 * 3. currentNumber * 10 + addNum에 대해 소수 확인
 * 4. 소수 확인 함수 isPrime
 *  4-1. 1은 아무것도 나눠지지 않아도 소수가 아님
 *  4-1. 2부터 현재 수의 제곱근까지 나누어보았을 때 아무것도 나누어 떨어지지 않으면 소수가 아님
 * 5. depth가 목표자리수만큼 왔으면 currentNumber 출력하고 종료
 */
public class BOJ2023 {
    static int length;

    /**
     * * 4. 소수 확인 함수 isPrime
     *  *  4-1. 1은 아무것도 나눠지지 않아도 소수가 아님
     *  *  4-1. 2부터 현재 수의 제곱근까지 나누어보았을 때 아무것도 나누어 떨어지지 않으면 소수가 아님
     * @param number
     * @return
     */
    static boolean isPrime(int number) {
        if(number == 1) return false;
        for(int divide = 2; divide <= Math.sqrt(number); divide++) {
            if(number % divide == 0) return false;
        }
        return true;
    }
    static void makeNumber(int depth, int currentNumber) {
        //5. depth가 목표자리수만큼 왔으면 currentNumber 출력하고 종료
        if(depth == length) {
            System.out.println(currentNumber);
            return;
        }
        for(int addNum = 0; addNum <= 9; addNum++) {
            if(depth == 0 && addNum == 0) continue;
            //2. 다음 자리로 갈 때 0~9가 뒤에 붙는다고 할 때 이전 수에 10을 곱하고, 그 뒤에 0~9를 붙인다
            //3. currentNumber * 10 + addNum에 대해 소수 확인
            if(isPrime(currentNumber * 10 + addNum)) {
                makeNumber(depth + 1, currentNumber * 10 + addNum);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        length = Integer.parseInt(st.nextToken());
        makeNumber(0, 0);
    }
}