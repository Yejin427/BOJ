import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 1. 앞으로 빼고 뒤로 넣기 위해 Queue를 사용하여 자료를 저장하고 로직을 구현함.
 * 2. finished 변수를 통해 cycle의 종료조건을 만족한지 확인함
 * 3. 만약 front - 현재감소계수가 0보다 작거나 같으면 뒤에 0을 추가하고 finished = true, break
 * 4. 그렇지 않다면 front - 현재감소계수 add
 */
public class SWEA1225 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int test = 1; test <= 10; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int testCase = Integer.parseInt(st.nextToken());
            Queue<Integer> q = new ArrayDeque<>();
            st = new StringTokenizer(br.readLine());
            for(int idx = 1; idx <= 8; idx++) {
                int num = Integer.parseInt(st.nextToken());
                q.add(num);
            }

            boolean finished = false;
            //2. finished 변수를 통해 cycle의 종료조건을 만족한지 확인함
            while(!finished) {
                for(int decrease = 1; decrease <= 5; decrease++) {
                    int front = q.poll();
                    //3. 만약 front - 현재감소계수가 0보다 작거나 같으면 뒤에 0을 추가하고 finished = true, break
                    if(front - decrease <= 0) {
                        q.add(0);
                        finished = true;
                        break;
                    } else {
                        //4. 그렇지 않다면 front - 현재감소계수 add
                        q.add(front-decrease);
                    }
                }
            }
            System.out.printf("#%d ", testCase);
            while(!q.isEmpty()) {
                System.out.printf("%d ", q.poll());
            }
            System.out.println();
        }
    }
}