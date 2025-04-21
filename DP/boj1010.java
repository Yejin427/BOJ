import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 서쪽 - 동쪽 점을 잇는 다리를 만드는데 다리가 겹칠 수 없음 -> 동쪽에 이을 점을 고른다면 순서가 정해져있다
 * 2. 조합을 통해 동쪽에서 서쪽 개수만큼 고르는 것이 답임.
 * 3. 조합을 dp top-down과 메모이제이션으로 푼다.
 * 	3-1. n==k || k == 0이면 조합이 1임
 * 	3-2. nCk = n-1Ck + n-1Ck-1임을 이용하여 dp를 사용한다.
 *  3-3. 만약 combination에 값이 저장되어있다면 재귀를 호출하지 않고 바로 리턴.
 * @author SSAFY
 *
 */
public class BOJ1010 {
	static int[][] combination;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int testCase = Integer.parseInt(br.readLine());
		combination = new int[31][31];
		while(testCase-- > 0) {
			st = new StringTokenizer(br.readLine());
			int west = Integer.parseInt(st.nextToken());
			int east = Integer.parseInt(st.nextToken());
			
			System.out.println(comb(east, west));
		}
	}
	//3. 조합을 dp top-down과 메모이제이션으로 푼다.
	static int comb(int east, int west) {
		//3-1. n==k || k == 0이면 조합이 1임
		if(east == west || west == 0) return 1;
		//3-3. 만약 combination에 값이 저장되어있다면 재귀를 호출하지 않고 바로 리턴.
		if(combination[east][west] > 0) return combination[east][west];
		//3-2. nCk = n-1Ck + n-1Ck-1임을 이용하여 dp를 사용한다.
		return combination[east][west] = comb(east-1, west) + comb(east-1, west-1);
	}
}