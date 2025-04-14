import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 지뢰찾기 -> dfs로 인접 칸들을 확인하면서 주위 8방 내 지뢰가 있다면 탐색을 종료한다.
 * 2. 8방은 dx, dy배열을 통해서 확인한다.
 * 3. 일단 배열을 다 돌면서 자기 주위에 지뢰가 몇개 있는지 저장한다. 자신이 지뢰라면 -1 저장.
 * 4. dfs를 돌면서 현재 칸에 방문 체크 후 주위 8방을 탐색하고, 범위 내에 있거나 방문하지 않은 칸이면 다음 칸을 탐색한다.
 * 5. 만약 주위에 지뢰가 있는 0칸 (bombCount > 0)에 도달했다면 더 탐색하지 않고 종료한다.
 * 6. 이런 dfs 첫 호출 횟수가 최소 클릭 횟수다.
 * @author SSAFY
 *
 */
public class SWEA1868 {
	//입력받는 지뢰 map
    static char map[][];
    //주변에 지뢰 몇개? -> 자신이 지뢰면 -1
    static int bombCount[][];
    //2. 8방은 dx, dy배열을 통해서 확인한다.
    static int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
     
    static int size;
    static boolean visited[][];
    //dfs를 돌면서 현재 칸에 방문 체크 후 주위 8방을 탐색하고, 범위 내에 있거나 방문하지 않은 칸이면 다음 칸을 탐색한다.
    static void dfs(int currentRow, int currentColumn) {
        visited[currentRow][currentColumn] = true;
        //5. 만약 주위에 지뢰가 있는 0칸 (bombCount > 0)에 도달했다면 더 탐색하지 않고 종료한다.
        if(bombCount[currentRow][currentColumn] != 0) return;
        for(int dir=0;dir<8;dir++) {
            int nextRow = currentRow + dx[dir], nextColumn = currentColumn + dy[dir];
            if(nextRow < 1 || nextRow > size || nextColumn < 1 || nextColumn > size || visited[nextRow][nextColumn]) continue;
            dfs(nextRow, nextColumn);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            size = Integer.parseInt(st.nextToken());
            map = new char[size+1][size+1];
            bombCount = new int[size+1][size+1];
            visited = new boolean[size+1][size+1];
            
            for(int row = 1; row <= size; row++) {
                for(int col = 1; col <= size; col++) {
                    map[row][col] = (char) br.read();
                }
                br.readLine();
            }
            
            //일단 배열을 다 돌면서 자기 주위에 지뢰가 몇개 있는지 저장한다. 자신이 지뢰라면 -1 저장.
            for(int row=1;row<=size;row++) {
                for(int col=1;col<=size;col++) {
                    if(map[row][col] == '*') bombCount[row][col] = -1;
                    else {
                        for(int dir=0;dir<8;dir++) {
                            //칸 범위 내에 지뢰가 있으면
                            if(1 <= row+dx[dir] && row+dx[dir] <= size && 1 <= col+dy[dir] && col+dy[dir] <= size && map[row+dx[dir]][col+dy[dir]] == '*') 
                                bombCount[row][col]++; 
                        }
                    }
                     
                }
            }
            int answer = 0;
            for(int row=1;row<=size;row++) {
                for(int col=1;col<=size;col++) {
                    if(!visited[row][col] && bombCount[row][col] == 0) {
                        //이런 dfs 첫 호출 횟수가 최소 클릭 횟수다.
                    	answer++;
                        dfs(row, col);
                    }
                }
            }
            //0인 것이 없지만 아직 체크하지 않은 곳이 있다면 -> 각각 하나씩 더해줌
            for(int row=1;row<=size;row++) {
                for(int col=1;col<=size;col++) {
                    if(!visited[row][col] && map[row][col] != '*') answer++;
                }
            }
            System.out.printf("#%d %d\n", test, answer);
        }
    }
}