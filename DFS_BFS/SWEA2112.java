import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. d, w, k모두 작은 숫자 -> 완전 탐색(조합)을 이용해 약품 바르는 위치를 지정해준다.
 * 2. 기저조건으로 모든 열이 최소 연속 개수를 충족했는지 확인한다.
 *  2-1. 모두 충족했다면 약품 수(medicineCount)를 answer와 비교해준 후 작은 값을 update하고 리턴
 * 3. nxtIndex번째 row에 A, B필름을 붙였을 때 재귀를 호출한다.
 *  3-1. 이 때, 다른 array에 미리 있던 값들을 저장한 후, 필름을 통해 해당 열을 모두 0 또는 1로 바꾼다.
 *  3-2. 재귀 호출 후 원래값을 되돌려주기 위해 복사했던 값을 재할당한다.
 */
public class SWEA2112 {
    static int[][] film;
    static int thick, width, passCount;
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            thick = Integer.parseInt(st.nextToken());
            width = Integer.parseInt(st.nextToken());
            passCount = Integer.parseInt(st.nextToken());
            film = new int[thick+1][width+1];
            answer = thick+1;

            for(int row = 1; row <= thick; row++) {
                st = new StringTokenizer(br.readLine());
                for(int col = 1; col <= width; col++) {
                    film[row][col] = Integer.parseInt(st.nextToken());
                }
            }
            if(passCount == 1) {
                System.out.printf("#%d 0\n", test);
            } else {
                dfs(0, 0);
                System.out.printf("#%d %d\n", test, answer);
            }
        }
    }
    static void dfs(int medicineCount, int lastIndex) {
        //2. 기저조건으로 모든 열이 최소 연속 개수를 충족했는지 확인한다.
        boolean allPass = true;
        for(int col = 1; col <= width; col++) {
            int duplicateCount = 1, currentFilm = film[1][col];
            boolean pass = false;
            for(int row = 2; row <= thick; row++) {
                if(film[row][col] == currentFilm) {
                    if(++duplicateCount == passCount) {
                        pass = true;
                        break;
                    }
                } else {
                    duplicateCount = 1;
                    currentFilm = film[row][col];
                }
            }
            if(!pass) {
                allPass = false;
                break;
            }
        }
        //2-1. 모두 충족했다면 약품 수(medicineCount)를 answer와 비교해준 후 작은 값을 update하고 리턴
        if(allPass) {
            answer = Math.min(medicineCount, answer);
            return;
        }
        //3. nxtIndex번째 row에 A, B필름을 붙였을 때 재귀를 호출한다.
        for(int nxtIndex = lastIndex + 1; nxtIndex <= thick; nxtIndex++) {
            //해당 row의 모든 film배열 복사
            //3-1. 이 때, 다른 array에 미리 있던 값들을 저장한 후, 필름을 통해 해당 열을 모두 0 또는 1로 바꾼다.
            int[] copyRow = new int[width+1];
            for(int column = 1; column <= width; column++) {
                copyRow[column] = film[nxtIndex][column];
            }
            //film A부착
            for(int column = 1; column <= width; column++) {
                film[nxtIndex][column] = 0;
            }
            dfs(medicineCount+1, nxtIndex);
            //film B부착
            for(int column = 1; column <= width; column++) {
                film[nxtIndex][column] = 1;
            }
            dfs(medicineCount+1, nxtIndex);
            //3-2. 재귀 호출 후 원래값을 되돌려주기 위해 복사했던 값을 재할당한다.
            for(int column = 1; column <= width; column++) {
                film[nxtIndex][column] = copyRow[column];
            }
        }
    }
}