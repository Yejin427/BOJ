import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 선을 이을 때마다 구간에 모두 1씩 더해주어야 한다 -> lazy segmentTree로 해결
 * 2-1. 홀수 : n -> 3*n+1 [n, 3*n]에 1씩 더함
 * 2-2. 짝수 : n -> n/2 [n/2, n-1]에 1씩 더함
 * 3. 999001까지 입력받으므로 999001 * 2까지는 segmentTree를 선언하고 update_range 호출
 * 4. Lazy Segment Tree : 구간 update 시 만약 update 구간 내에 start와 end가 위치해 있다면 현재 tree에만 구간 길이만큼 더해주고 lazy 자식에게 전파
 * 	4-1. update_lazy
 * 		4-1-1. 구간들 계속해서 탐색해 나가면서 현재 구간에 lazy가 있다면 tree에 구간만큼 update해주고 lazy 전파 -> 자신의 lazy는 0으로 초기화
 * 	4-2. query : (left, right)의 구간 합을 구하는 함수
 * 		4-2-1. segmentTree와 같지만 탐색하면서 update_lazy를 계속 호출해주어야 한다.
 * 	4-3. update_range : 구간 update 함수
 * 		4-3-1. 구간을 탐색하면서 update_lazy를 계속 호출해주며, 현재 start, end가 left와 right 사이에 있다면 tree update, 
 * 		자식에게 lazy 전파 후 더 호출하지 않고 리턴
 * @author SSAFY
 *
 */
public class SWEA_24303_웹공부빼고다재밌는기민이_조예진 {
	static int[] dp;
	static int[] nxt;
	//4. Lazy Segment Tree : 구간 update 시 만약 update 구간 내에 start와 end가 위치해 있다면 현재 tree에만 구간 길이만큼 더해주고 lazy 자식에게 전파
	static class Segtree{
		int leafSize;
		long[] tree;
		long[] lazy;
		Segtree(int numSize) {
			for(leafSize = 1; leafSize < numSize; leafSize *= 2);
			tree = new long[leafSize * 2];
			lazy = new long[leafSize * 2];
		}
		//4-1-1. 구간들 계속해서 탐색해 나가면서 현재 구간에 lazy가 있다면 tree에 구간만큼 update해주고 lazy 전파 -> 자신의 lazy는 0으로 초기화
		void update_lazy(int pos, int start, int end) {
			if(lazy[pos] != 0) {
				tree[pos] += (end - start + 1) * lazy[pos];
				if(start != end) {
					lazy[pos * 2] += lazy[pos];
					lazy[pos * 2 + 1] += lazy[pos];
				}
				lazy[pos] = 0;
			}
		}
		//4-3. update_range : 구간 update 함수
		void update_range(int start, int end, int pos, int left, int right) {
			//4-3-1. 구간을 탐색하면서 update_lazy를 계속 호출해주며, 현재 start, end가 left와 right 사이에 있다면 tree update, 
			 //* 		자식에게 lazy 전파 후 더 호출하지 않고 리턴
			update_lazy(pos, start, end);
			if(end < left || right < start) return;
			if(left <= start && end <= right) {
				tree[pos] += (long)(end - start + 1);
				if(start != end) {
					lazy[pos*2]++;
					lazy[pos*2+1]++;
				}
				return;
			}
			int mid = (start + end) >> 1;
			update_range(start, mid, pos * 2, left, right);
			update_range(mid + 1, end, pos * 2 + 1, left, right);
			tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		}
		//4-2. query : (left, right)의 구간 합을 구하는 함수
		long query(int pos, int start, int end, int left, int right) {
			//4-2-1. segmentTree와 같지만 탐색하면서 update_lazy를 계속 호출해주어야 한다.
			update_lazy(pos, start, end);
			if(end < left || right < start) return 0;
			if(left <= start && end <= right) {
				return tree[pos];
			}
			int mid = (start + end) >> 1;
			return query(pos * 2, start, mid, left, right) + query(pos * 2 + 1, mid + 1, end, left, right);
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int testCase = Integer.parseInt(st.nextToken());
		//3. 999001까지 입력받으므로 999001 * 2까지는 segmentTree를 선언하고 update_range 호출
		Segtree segtree = new Segtree(2000000);
		for(int index = 2; index <= 2000000; index++) {
			if(index % 2 == 1) {
				//2-1. 홀수 : n -> 3*n+1 [n, 3*n]에 1씩 더함
				segtree.update_range(1, segtree.leafSize, 1, index, index * 3);
			} else {
				//2-2. 짝수 : n -> n/2 [n/2, n-1]에 1씩 더함
				segtree.update_range(1, segtree.leafSize, 1, index/2, index-1);
			}
		}
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			System.out.printf("#%d %d\n", test, segtree.query(1, 1, segtree.leafSize, num, num));
		}
	}
}