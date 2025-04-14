import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 아이디어 : 시간을 0부터 돌리면서 데스크와 대기 줄 상황을 바꾼다.
 * 1. curReception curRepair 배열 : 현재 reception, repair 데스크에 누가, 몇분 째에 왔는지 저장한다. -> 비어있다면{0, 0}
 * 2. receptionWait, repairWait 큐 : 각각 reception, repair 대기큐이며, 고객 index와 들어갈 수 있는 시간을 저장한다.
 * 3. clientUsed : 각 index의 client가 몇 번 reception, repair desk를 사용했는지 나타낸다. -> 다 끝나고 나올 때 저장한다.
 * 4. 시간마다 다음과 같은 순서로 처리한다.
 * 	4-1. 만약 모든 client가 repairdesk를 모두 사용한 상태 -> while문 종료
 * 	4-2. reception desk 완료 상태 확인 -> 완료되었다면 curReception 데스크를 비우고, repair 큐에 고객index와 시간 넣고, clientUsed[index][0]을 채움
 *  4-3. reception queue확인 -> 만약 빈 데스크가 있고, 고객이 온 시간보다 더 지난 상태면 빈 가장 작은 index desk에 curReception 채우기
 *  4-4. 4-2와 같은 방법으로 repair desk 완료 상태 확인
 *  4-5. repair queue 확인 -> 빈 데스크가 있다면 빈 가장 작은 index desk에 curReception 채우기
 * 5. 모든 작업이 끝났다면 clientUsed를 확인해서 지갑 잃어버린 사람의 reception, repair desk와 비교해서 answer 더하기
 * @author SSAFY
 *
 */
public class SWEA2477{
	static int[] reception;
	static int[] repair;
	//3. clientUsed : 각 index의 client가 몇 번 reception, repair desk를 사용했는지 나타낸다. -> 다 끝나고 나올 때 저장한다.
	static int[][] clientUsed;
	static int[] clientTime;
	//1. curReception curRepair 배열 : 현재 reception, repair 데스크에 누가, 몇분 째에 왔는지 저장한다. -> 비어있다면{0, 0}
	static int[][] curReception, curRepair;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int testCase = Integer.parseInt(br.readLine());
		for(int test = 1; test <= testCase; test++) {
			st = new StringTokenizer(br.readLine());
			int receptionSize = Integer.parseInt(st.nextToken());
			int repairSize = Integer.parseInt(st.nextToken());
			int clientSize = Integer.parseInt(st.nextToken());
			int targetReceptionNum = Integer.parseInt(st.nextToken());
			int targetRepairNum = Integer.parseInt(st.nextToken());
			
			reception = new int[receptionSize+1];
			repair = new int[repairSize+1];
			curReception = new int[receptionSize+1][2];
			curRepair = new int[repairSize+1][2];
			
			st = new StringTokenizer(br.readLine());
			for(int index = 1; index <= receptionSize; index++) {
				reception[index] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int index = 1; index <= repairSize; index++) {
				repair[index] = Integer.parseInt(st.nextToken());
			}
			clientUsed = new int[clientSize+1][2];
			clientTime = new int[clientSize+1];
			//2. receptionWait, repairWait 큐 : 각각 reception, repair 대기큐이며, 고객 index와 들어갈 수 있는 시간을 저장한다.
			Queue<int[]> receptionWait = new ArrayDeque<>();
			Queue<int[]> repairWait = new ArrayDeque<>();
			
			st = new StringTokenizer(br.readLine());
			for(int index = 1; index <= clientSize; index++) {
				clientTime[index] = Integer.parseInt(st.nextToken());
				receptionWait.offer(new int[] {index, clientTime[index]});
			}
			
			int time = 0;
			while(true) {	//시간을 돌리는 루프
				boolean finished = true;
				//4-1. 만약 모든 client가 repairdesk를 모두 사용한 상태 -> while문 종료
				for(int index = 1; index <= clientSize; index++) {
					if(clientUsed[index][1] == 0) {
						finished = false;
						break;
					}
				}
				if(finished) break;
				//4-2. reception desk 완료 상태 확인 -> 완료되었다면 curReception 데스크를 비우고, repair 큐에 고객index와 시간 넣고, clientUsed[index][0]을 채움
				for(int index = 1; index <= receptionSize; index++) {
					if(curReception[index][0] != 0 && curReception[index][1] + reception[index] == time) {
						clientUsed[curReception[index][0]][0] = index;
						//끝낸 후 repairWait queue에 들어가기
						repairWait.offer(new int[] {curReception[index][0], time});
						curReception[index] = new int[] {0, 0};
					}
				}
				//4-3. reception queue확인 -> 만약 빈 데스크가 있고, 고객이 온 시간보다 더 지난 상태면 빈 가장 작은 index desk에 curReception 채우기
				while(!receptionWait.isEmpty()) {
					int[] cur = receptionWait.peek();
					if(cur[1] > time) break;
					//빈 곳이 있는지 확인
					int emptyIndex = -1;
					for(int index = 1; index <= receptionSize; index++) {
						if(curReception[index][0] == 0) {
							emptyIndex = index;
							break;
						}
					}
					if(emptyIndex != -1) {
						curReception[emptyIndex] = new int[] {cur[0], time};
						receptionWait.poll();
					} else {
						break;
					}
				}
				//4-4. 4-2와 같은 방법으로 repair desk 완료 상태 확인
				for(int index = 1; index <= repairSize; index++) {
					if(curRepair[index][0] != 0 && curRepair[index][1] + repair[index] == time) {
						clientUsed[curRepair[index][0]][1] = index;
						curRepair[index] = new int[] {0, 0};
					}
				}
				//repair queue 확인 -> 빈 데스크가 있다면 빈 가장 작은 index desk에 curReception 채우기
				while(!repairWait.isEmpty()) {
					int[] cur = repairWait.peek();
					//빈 곳이 있는지 확인
					int emptyIndex = -1;
					for(int index = 1; index <= repairSize; index++) {
						if(curRepair[index][0] == 0) {
							emptyIndex = index;
							break;
						}
					}
					if(emptyIndex != -1) {
//						System.out.println("emptyIdx2: "+emptyIndex+" clientIdx2: "+cur[0]+" time2: "+time);
						curRepair[emptyIndex] = new int[] {cur[0], time};
						repairWait.poll();
					} else {
						break;
					}
				}
				time++;
			}
			int answer = 0;
			//5. 모든 작업이 끝났다면 clientUsed를 확인해서 지갑 잃어버린 사람의 reception, repair desk와 비교해서 answer 더하기
			for(int index = 1; index <= clientSize; index++) {
				if(clientUsed[index][0] == targetReceptionNum && clientUsed[index][1] == targetRepairNum) {
					answer += index;
				}
			}
			System.out.printf("#%d %d\n", test, answer != 0 ? answer : -1);
		}
	}
}