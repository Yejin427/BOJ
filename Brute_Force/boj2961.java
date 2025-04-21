import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 도영이가 만드는 음식 조합을 재귀함수 부분집합으로 푼다
 * 2. 재귀함수에서 여태까지 판단한 음식의 index를 넘겨준다.
 * 3. 다믕 index(index + 1)를 먹는 선택지와 먹지 않는 선택지 모두 재귀 호출한다.
 * 4. index가 재료의 수만큼 도달하면 answer에 신맛과 쓴맛의 차이의 최솟값으로 계속 업데이트해준다.
 *  4-1. 이때 아무 음식을 넣지 않을 것을 방지하기 위해 sourMultiply ==1 bitterSum == 0을 업데이트하지 않는다.
 */
public class BOJ2961 {
    //각각 쓴맛, 신맛 정도 저장 배열
    static int sourDegree[] = new int[11];
    static int bitterDegree[] = new int[11];
    //재료의 수
    static int ingredientCount;
    //신맛 쓴맛 차이의 최솟값. 계속 minimum값으로 Math.min으로 update하기 위해 Integer.MAX_VALUE로 초기화
    static int answer = Integer.MAX_VALUE;
    static boolean ingredientAdded[] = new boolean[11];
    static void make(int index, int sourMultiply, int bitterSum) {
        if(index == ingredientCount) {
            if(sourMultiply != 1 && bitterSum != 0) {
                answer = Math.min(Math.abs(bitterSum - sourMultiply), answer);
            }
            return;
        }
        make(index + 1, sourMultiply * sourDegree[index + 1], bitterSum + bitterDegree[index + 1]);
        make(index + 1, sourMultiply, bitterSum);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ingredientCount = Integer.parseInt(st.nextToken());
        for(int ingredient = 1; ingredient <= ingredientCount; ingredient++) {
            st = new StringTokenizer(br.readLine());
            sourDegree[ingredient] = Integer.parseInt(st.nextToken());
            bitterDegree[ingredient] = Integer.parseInt(st.nextToken());
        }
        //계속 곱해주는 sourMultiply는 초기값 1, 계속 더해주는 bitterSum 초기값은 0
        make(0, 1, 0);
        System.out.println(answer);
    }
}