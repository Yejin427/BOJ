import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. Disjoint Set , Union-find를 통해 문제를 해결한다.
 * 2. 자신의 최상위 부모 노드를 저장하는 parent배열을 둔다. 
 * 3. 초기에 자신의 부모는 자신이다. 모든 집합에 자신만 있기 때문이다.
 * 4. find함수 : 자신의 root 부모를 찾는 함수다.
 * 	4-1. 자기 자신이 parent와 같다면 자신을 리턴, 아니면 경로 압축을 통해 parent를 리턴한다.
 * 5. merge 함수 : 두 집합을 합치는 연산을 하는 함수다.
 * 	5-1. 각자 자신의 root부모를 찾고 parent[root2] = root1을 통해 한 집합의 부모를 다른 집합의 부모로 둔다.
 * 	5-2. 이미 같은 집합에 있다면 호출하지 않는다.
 * @author SSAFY
 *
 */
public class SWEA3289 {
	//2. 자신의 최상위 부모 노드를 저장하는 parent배열을 둔다. 
	static int parent[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int testCase = Integer.parseInt(st.nextToken());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int size = Integer.parseInt(st.nextToken());
			int calculate = Integer.parseInt(st.nextToken());
			parent = new int[size+1];
			//3. 초기에 자신의 부모는 자신이다. 모든 집합에 자신만 있기 때문이다.
			for(int node = 0; node <= size; node++) {
				parent[node] = node;
			}
			sb.append("#").append(test).append(" ");
			while(calculate-- > 0) {
				st = new StringTokenizer(br.readLine());
				int command = Integer.parseInt(st.nextToken());
				int node1 = Integer.parseInt(st.nextToken());
				int node2 = Integer.parseInt(st.nextToken());
				
				if(command == 0) {
					//5-2. 이미 같은 집합에 있다면 호출하지 않는다.
					if(find(node1) != find(node2)) {
						merge(node1, node2);
					}
				} else {
					int sameSet = find(node1) == find(node2) ? 1 : 0;
					sb.append(sameSet);
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
	//4. find함수 : 자신의 root 부모를 찾는 함수다.
	static int find(int node) {
		//	4-1. 자기 자신이 parent와 같다면 자신을 리턴, 아니면 경로 압축을 통해 parent를 리턴한다.
		if(node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}
	//5. merge 함수 : 두 집합을 합치는 연산을 하는 함수다.
	static void merge(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		//5-1. 각자 자신의 root부모를 찾고 parent[root2] = root1을 통해 한 집합의 부모를 다른 집합의 부모로 둔다.
		parent[root2] = root1;
	}
}