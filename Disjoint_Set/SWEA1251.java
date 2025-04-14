import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
/**
 * 1. Prim 알고리즘으로 문제 해결
 * 2. adjMatrix : 두 노드간 인접 행렬을 2차원 배열로 저장한다. 1~n까지 돌면서 두 정점 간 거리를 저장한다.
 * 3. 노드들을 돌면서 트리에 속할 방문하지 않은 가장 minEdge가 작은 정점 찾기
 * 4. 찾은 노드의 minEdge값을 최소 스패닝 트리에 추가해준다.
 * 5. 새롭게 확장된 트리 정점과 나머지 비트리 정점 간의 최소간선비용 비교 후 업데이트
 * 6. 구한 answer값에 tax를 곱하고 반올림한다.
 * @author SSAFY
 *
 */
public class SWEA1251{
    static long[][] islandList;
    static long[][] adjMatrix;
    static boolean[] visited;
    static long[] minEdge;
    static long distance(long xpos1, long ypos1, long xpos2, long ypos2) {
        return (xpos1 - xpos2) * (xpos1 - xpos2) + (ypos1 - ypos2) * (ypos1 - ypos2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            int islands = Integer.parseInt(st.nextToken());
            
            islandList = new long[islands+1][2];
            adjMatrix = new long[islands+1][islands+1];
            visited = new boolean[islands+1];
            minEdge = new long[islands+1];
            st = new StringTokenizer(br.readLine());
            for(int island = 1; island <= islands; island++) {
                islandList[island][0] = Long.parseLong(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int island = 1; island <= islands; island++) {
                islandList[island][1] = Long.parseLong(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            double tax = Double.parseDouble(st.nextToken());

            //2. adjMatrix : 두 노드간 인접 행렬을 2차원 배열로 저장한다. 1~n까지 돌면서 두 정점 간 거리를 저장한다.
            for(int idx1 = 1; idx1 <= islands; idx1++) {
                for(int idx2 = idx1 + 1; idx2 <= islands; idx2++) {
                    adjMatrix[idx1][idx2] = distance(islandList[idx1][0], islandList[idx1][1]
                            , islandList[idx2][0], islandList[idx2][1]);
                    adjMatrix[idx2][idx1] = distance(islandList[idx1][0], islandList[idx1][1]
                            , islandList[idx2][0], islandList[idx2][1]);
                }
            }
            Arrays.fill(minEdge, Long.MAX_VALUE);
            long answer = 0;
            minEdge[1] = 0;
            for(int start = 1; start <= islands; start++) {
            	long min = Long.MAX_VALUE;
            	int minvertex = -1;
            	//노드들을 돌면서 트리에 속할 방문하지 않은 가장 minEdge가 작은 정점 찾기
            	for(int nxt = 1; nxt <= islands; nxt++) {
            		if(!visited[nxt] && min > minEdge[nxt]) {
            			min = minEdge[nxt];
            			minvertex = nxt;
            		}
            	}
            	if(minvertex == -1) break;
            	//4. 찾은 노드의 minEdge값을 최소 스패닝 트리에 추가해준다.
            	answer += min;
            	visited[minvertex] = true;
            	//5. 새롭게 확장된 트리 정점과 나머지 비트리 정점 간의 최소간선비용 비교 후 업데이트
            	for(int nxt = 1; nxt <= islands; nxt++) {
            		if(!visited[nxt] && adjMatrix[minvertex][nxt] != 0 && minEdge[nxt] > adjMatrix[minvertex][nxt]) {
    					minEdge[nxt] = adjMatrix[minvertex][nxt];
    				}
            	}
            }
            // 6. 구한 answer값에 tax를 곱하고 반올림한다.
            System.out.printf("#%d %d\n", test, Math.round(answer * tax));
        }
    }
}