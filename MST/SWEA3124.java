import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1. Kruskal Algorithm을 사용해 노드들을 최소의 가중치로 연결 -> 최소 스패닝 트리
 * 2. node1, node2를 잇는 weight가중치의 edge를 저장하는 class 생성
 * 3. edgelist에 저장하고 weight기준 정렬
 * 4. 부모배열은 일단 자기 자신으로 초기화
 * 5. find함수 : 만약 자기자신이 부모면 자기자신 리턴, 아니면 경로 압축을 통해 부모 리턴
 * 6. union함수 : 두 node의 부모를 구하고 한 노드의 부모에 합친다.
 * 7. 만약 두 노드의 부모가 다르다면 union 호출 후 가중치 더함.
 * 8. 간선 개수가 20만, 가중치가 100만 까지 가능하므로 answer를 long type으로 선언
 */
public class SWEA3124 {
	static int[] parent;
    static Edge[] edges;
    static class Edge implements Comparable<Edge>{
        int node1, node2, weight;

        //2. node1, node2를 잇는 weight가중치의 edge를 저장하는 class 생성
        public Edge(int node1, int node2, int weight) {
            this.node1 = node1;
            this.node2 = node2;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }
    //5. find함수 : 만약 자기자신이 부모면 자기자신 리턴, 아니면 경로 압축을 통해 부모 리턴
    static int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    //6. union함수 : 두 node의 부모를 구하고 한 노드의 부모에 합친다.
    static void union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        parent[root2] = root1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
        	st = new StringTokenizer(br.readLine());
        	int nodeSize = Integer.parseInt(st.nextToken());
            int lineSize = Integer.parseInt(st.nextToken());
            edges = new Edge[lineSize];
            parent = new int[nodeSize+1];
            //4. 부모배열은 일단 자기 자신으로 초기화
            for(int index = 1; index <= nodeSize; index++) {
                parent[index] = index;
            }
            for(int index = 0; index < lineSize; index++) {
                st = new StringTokenizer(br.readLine());
                int node1 = Integer.parseInt(st.nextToken());
                int node2 = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                edges[index] = new Edge(node1, node2, weight);
            }
            //3. edgelist에 저장하고 weight기준 정렬
            Arrays.sort(edges);
            //8. 간선 개수가 20만, 가중치가 100만 까지 가능하므로 answer를 long type으로 선언
            long answer = 0;
            for(int index = 0; index < lineSize; index++) {
            	//7. 만약 두 노드의 부모가 다르다면 union 호출 후 가중치 더함.
                if(find(edges[index].node1) != find(edges[index].node2)) {
                    union(edges[index].node1, edges[index].node2);
                    answer += (long)edges[index].weight;
                }
            }
            System.out.printf("#%d %d\n", test, answer);
        }
        
    }
}