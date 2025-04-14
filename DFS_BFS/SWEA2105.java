import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 시작지점이 될 수 있는곳 : row = 0~size-3, column = 1~size-2
 * 2. dx, dy는 우하, 좌하, 좌상, 우상 순서로 배치한다. 경로를 그릴 수 있는 순서대로
 * 3. visitedBlock : 방문한 칸 체크, visitedDessert: 방문한 디저트 숫자 체크
 * 4. 디저트 개수, 현재 위치, 이전 방향을 매개변수로 넘겨주는 dfs를 돌린다. : traverse함수
 *  4-1. 현재 방향으로 가거나 현재 방향의 다음 방향으로 전진할 수 있음
 *  4-2. 범위 내에 있으며 visitedBlock, visitedDessert모두 false일 때만 다음으로 전진 가능
 *  4-3. 첫 위치를 traverse호출 전 저장해주고, count가 2 이상이면서 시작 위치로 되돌아왔으면 -> 경로를 완성한 것이므로 maxEatCount 업데이트
 */
public class SWEA2105 {
    static int size;
    static int[][] map;
    //3. visitedBlock : 방문한 칸 체크, visitedDessert: 방문한 디저트 숫자 체크
    static boolean[][] visitedBlock;
    static boolean[] visitedDessert;
    //2. dx, dy는 우하, 좌하, 좌상, 우상 순서로 배치한다. 경로를 그릴 수 있는 순서대로
    static int[] dx = {1, 1, -1, -1}, dy = {1, -1, -1, 1};
    static int maxEatCount;
    static int startRow, startColumn;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            size = Integer.parseInt(br.readLine());
            map = new int[size][size];
            maxEatCount = 0;
            for(int row = 0; row < size; row++) {
                st = new StringTokenizer(br.readLine());
                for(int col = 0; col < size; col++) {
                    map[row][col] = Integer.parseInt(st.nextToken());
                }
            }
            //1. 시작지점이 될 수 있는곳 : row = 0~size-3, column = 1~size-2
            for(int row = 0; row < size - 2; row++) {
                for(int col = 1; col < size - 1; col++) {
                    visitedBlock = new boolean[size][size];
                    visitedDessert = new boolean[101];
                    visitedBlock[row][col] = true;
                    visitedDessert[map[row][col]] = true;
                    startRow = row; startColumn = col;
                    traverse(1, row, col, 0);
                }
            }
            System.out.printf("#%d %d\n", test, maxEatCount > 0 ? maxEatCount : -1);
        }
    }
    //4. 디저트 개수, 현재 위치, 이전 방향을 매개변수로 넘겨주는 dfs를 돌린다. : traverse함수
    static void traverse(int count, int row, int column, int prevDirection) {
        //4-1. 현재 방향으로 가거나 현재 방향의 다음 방향으로 전진할 수 있음
        for(int dir = prevDirection; dir <= prevDirection + 1; dir++) {
            if(dir == 4) break;
            int nextRow = row + dx[dir];
            int nextCol = column + dy[dir];
            if(nextRow < 0 || nextRow >= size || nextCol < 0 || nextCol >= size) continue;
            //4-3. 첫 위치를 traverse호출 전 저장해주고, count가 2 이상이면서 시작 위치로 되돌아왔으면 -> 경로를 완성한 것이므로 maxEatCount 업데이트
            if(nextRow == startRow && nextCol == startColumn && count > 2) {
                maxEatCount = Math.max(count, maxEatCount);
                return;
            }
            //4-2. 범위 내에 있으며 visitedBlock, visitedDessert모두 false일 때만 다음으로 전진 가능
            if(!visitedBlock[nextRow][nextCol] && !visitedDessert[map[nextRow][nextCol]]) {
                visitedBlock[nextRow][nextCol] = true;
                visitedDessert[map[nextRow][nextCol]] = true;
                traverse(count + 1, nextRow, nextCol, dir);
                visitedBlock[nextRow][nextCol] = false;
                visitedDessert[map[nextRow][nextCol]] = false;
            }
        }
    }
}