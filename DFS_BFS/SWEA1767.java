import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 1. 부분집합을 통해 해당 core을 연결 / 비연결 선택
 * 2. calcLen : 해당 방향으로 전선을 연결했을 때의 길이 -> 연결할 수 없다면 -1
 * 3. backtrace : 전설 연결하면서 visited 체크한 부분 다음 재귀를 위해 해제
 * 4. 만약 index가 coresize에 도달했다면
 * 5. 연결 개수가 많다면 answer, maxCore 초기화, 같다면 cost가 더작을 때 answer 초기화
 */
public class SWEA1767 {
    static List<int[]> cores = new ArrayList<int[]>();
    static int size, max = 0, minLen = Integer.MAX_VALUE;
    static boolean[][] visited;
    static int[] dx = { 1, -1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };

    // 해당 방향으로 전선을 이을 수 있는지 체크 후 길이 출력
    public static int calcLen(int x, int y, int d) {
        int len = 0;
        int tmpx = x, tmpy = y;
        while (true) {
            tmpx += dx[d];
            tmpy += dy[d];
            if (tmpx >= 0 && tmpx < size && tmpy>= 0 && tmpy < size) {
                if (!visited[tmpx][tmpy]) {
                    len++;
                    visited[tmpx][tmpy] = true;
                } else {
                    // 중간에 끊겼다면 지금까지 방문표시한 것들 해제
                    while(true) {
                        tmpx -= dx[d];
                        tmpy -= dy[d];
                        if(tmpx == x && tmpy == y) break;
                        visited[tmpx][tmpy] = false;
                    }
                    return -1;
                }
            } else
                break;
        }
        return len;
    }

    public static void backtrace(int x, int y, int d) {
        while (true) {
            x += dx[d];
            y += dy[d];
            if (x >= 0 && x < size && y >= 0 && y < size)
                visited[x][y] = false;
            else
                break;
        }
    }

    public static void dfs(int index, int count, int length) {
        if (index == cores.size()) {
            if (max < count) {
                minLen = length;
                max = count;
            } else if (max == count) {
                minLen = Math.min(minLen, length);
            }
            return;
        }
        for (int d = 0; d < 4; d++) {
            int nx = cores.get(index)[0];
            int ny = cores.get(index)[1];

            int len = calcLen(nx, ny, d);
            if (len == -1) {
                continue; // 이 방향은 안돼
            } else {
                // 전선을 포함한 경우
                dfs(index + 1, count + 1, length + len);
                backtrace(nx, ny, d);

            }
        }
        // 전선을 포함하지 않은 경우
        dfs(index + 1, count, length);
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            cores.clear();
            size = Integer.parseInt(br.readLine());
            visited = new boolean[size][size];
            minLen = Integer.MAX_VALUE;
            max = 0;
            for (int row = 0; row < size; row++) {
                st = new StringTokenizer(br.readLine());
                for (int col = 0; col < size; col++) {
                    if (Integer.parseInt(st.nextToken()) == 1) {
                        if (row != 0 && row != size - 1 && col != 0 && col != size - 1)
                            cores.add(new int[] { row, col }); // 가장자리 코어가 아니라면 코어 리스트에 저장
                        visited[row][col] = true;
                    }
                }
            }

            dfs(0, 0, 0);
            sb.append('#').append(t).append(' ').append(minLen).append('\n');
        }
        System.out.println(sb);
    }
}