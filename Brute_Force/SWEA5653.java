import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * 1. 세포 Cell 객체를 선언
 *  1-1. x,y: 좌표, life: 생명력, status: 현재상태 (-1: 죽음, 0: 비활성, 1: 활성), time: 생긴 시간
 * 2. cellList에 실시간으로 증식하는 세포들을 저장해서 관리한다. (범위를 넘어서게 증식하는 것을 기록하기 위해 배열을 크게 잡고 중간에 기록한다)
 * 3. cellArray을 통해서 현재 위치에서의 세포가 존재하는지 (죽은 상태라도) 저장한다.
 * 4. curTime을 1부터 증가시키면서 활성 상태인 세포들의 증식을 먼저 처리하고, 그 다음 상태 변경을 처리한다
 *  4-1. cellList의 status == 1이면 -> cellArray에 다음 위치의 배열값을 저장한다.
 *      4-1-1. 이때 해당 array에 이미 cell이 없다면 newCell에 push, cell이 있다면 life 현재보다 클 때만 cellArray update
 *  4-2. 이후 newCell의 좌표값들을 cellList에 추가해주고 cellArray를 1000으로 초기화한다
 *      4-2-1. 이미 세포가 존재하는 상태 -> 1000
 *  4-3. 이후 cellList에서 최대값은 넣는 시점에 life값이 지났으면 활성상태, life값이 두번 지났으면 죽은 상태로 cellList에서 제거한다.
 */
public class SWEA5653 {
    /**
     *  1. 세포 Cell 객체를 선언
     *  1-1. x,y: 좌표, life: 생명력, status: 현재상태 (-1: 죽음, 0: 비활성, 1: 활성), time: 생긴 시간
     */
    static class Cell{
        public int x,y;
        public int life;
        public int status, time;
        public Cell(int x, int y, int life, int time) {
            this.x = x;
            this.y = y;
            this.life = life;
            this.status = 0;
            this.time = time;
        }

    }
    static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    static List<Cell> cellList;
    static int[][] cellArray;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            int rowSize = Integer.parseInt(st.nextToken());
            int colSize = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());

            cellList = new ArrayList<>();
            //3. cellArray을 통해서 현재 위치에서의 세포가 존재하는지 (죽은 상태라도) 저장한다.
            cellArray = new int[450][450];
            for(int row = 1; row <= rowSize; row++) {
                st = new StringTokenizer(br.readLine());
                for(int col = 1; col <= colSize; col++) {
                    int life = Integer.parseInt(st.nextToken());
                    if(life > 0) {
                        //2. cellList에 실시간으로 증식하는 세포들을 저장해서 관리한다. (범위를 넘어서게 증식하는 것을 기록하기 위해 배열을 크게 잡고 중간에 기록한다)
                        cellList.add(new Cell(row + 200, col + 200, life, 0));
                        cellArray[row+200][col+200] = 1000;
                    }
                }
            }
            //4. curTime을 1부터 증가시키면서 활성 상태인 세포들의 증식을 먼저 처리하고, 그 다음 상태 변경을 처리한다
            for(int curTime = 1; curTime <= time; curTime++) {
//                System.out.println("curSize: "+cellList.size());
                List<int[]> newCell = new ArrayList<>();
                for(int index = 0; index < cellList.size(); index++) {
                    Cell cell = cellList.get(index);
                    //4-1. cellList의 status == 1이면 -> cellArray에 다음 위치의 배열값을 저장한다.
                    if(cell.status == 1) {
                        for(int dir = 0; dir < 4; dir++) {
                            int nx = cell.x + dx[dir];
                            int ny = cell.y + dy[dir];

                            // 4-1-1. 이때 해당 array에 이미 cell이 없다면 newCell에 push, cell이 있다면 life 현재보다 클 때만 cellArray update
                            if(cellArray[nx][ny] == 0){
                                newCell.add(new int[]{nx, ny});
                                cellArray[nx][ny] = cell.life;
                            }
                            else if(cellArray[nx][ny] < cell.life) {
                                cellArray[nx][ny] = cell.life;
                            }
                        }
                    }
                }
                //4-2. 이후 newCell의 좌표값들을 cellList에 추가해주고 cellArray를 1000으로 초기화한다
                for(int[] position: newCell) {
                    cellList.add(new Cell(position[0], position[1],  cellArray[position[0]][position[1]], curTime));
                    cellArray[position[0]][position[1]] = 1000;
                }
                //4-3. 이후 cellList에서 최대값은 넣는 시점에 life값이 지났으면 활성상태, life값이 두번 지났으면 죽은 상태로 cellList에서 제거한다.
                for(int index = 0; index < cellList.size(); index++) {
                    if(cellList.get(index).time + cellList.get(index).life == curTime) {
                        cellList.get(index).status = 1;
                    }
                    else if(cellList.get(index).time +  2 * cellList.get(index).life == curTime) {
                        cellList.remove(index);
                        index--;
                    }
                }
            }
            sb.append('#').append(test).append(' ').append(cellList.size()).append('\n');
        }
        System.out.print(sb);
    }
}