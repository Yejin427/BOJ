import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * 1. 무게가 가볍고, 밑면이 넓을수록 먼저 놓아야 하므로 block 객체를 선언하고 width, height 기준으로 정렬한다.
 * 2. block객체에 num instance를 추가해 원래 몇 번 벽돌인지 저장한다.
 * 3. 정렬 후 LIS를 구하는 것과 같이 dp를 통해 현재 index까지의 최대 높이를 저장한다.
 *  3-1. 일단 dp를 자기 자신의 높이로 설정한다.
 *  3-2. 자기 앞의 블럭을 봤을 때 무게, 면적 모두 적게 나간다면, 이전dp와 자긴의 height를 더한것과 자신 dp를 비교한다.
 *  3-3. 만약 더 크면 dp와 prev 배열을 초기화한다. (prev배열은 이후 블럭 출력을 위해 자신 이전의 블럭을 저장한다)
 * 4. dp를 돌면서 최대 높이라면 stack에 자신과 자신 이전 블럭들을 저장하고 size와 함께 stack을 pop하면서 출력한다.
 */
public class BOJ2655{
    static class Block implements Comparable<Block>{
        //2. block객체에 num instance를 추가해 원래 몇 번 벽돌인지 저장한다.
        public int num, width, height, weight;

        //1. 무게가 가볍고, 밑면이 넓을수록 먼저 놓아야 하므로 block 객체를 선언하고 width, height 기준으로 정렬한다.
        public Block(int num, int width, int height, int weight) {
            this.num = num;
            this.width = width;
            this.height = height;
            this.weight = weight;
        }

        @Override
        public int compareTo(Block o) {
            if(this.width == o.width) {
                return Integer.compare(this.height, o.height);
            }
            return Integer.compare(this.width, o.width);
        }
    }
    static Block[] block;
    static int[] dp;  //index까지 밑바닥이 width까지 쌓았을 때 높이
    static int[] prev;
    static int answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int blockSize = Integer.parseInt(st.nextToken());
        block = new Block[blockSize+1];
        dp = new int[blockSize+1];
        prev = new int[blockSize+1];
        block[0] = new Block(0, 0, 0, 0);
        for(int index = 1; index <= blockSize; index++) {
            st = new StringTokenizer(br.readLine());
            block[index] = new Block(index, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(block);
        //3. 정렬 후 LIS를 구하는 것과 같이 dp를 통해 현재 index까지의 최대 높이를 저장한다.
        for(int index = 1; index <= blockSize; index++) {
            //3-1. 일단 dp를 자기 자신의 높이로 설정한다.
            dp[index] = block[index].height;
            for(int idx2 = 1; idx2 < index; idx2++) {
                //3-2. 자기 앞의 블럭을 봤을 때 무게, 면적 모두 적게 나간다면, 이전dp와 자긴의 height를 더한것과 자신 dp를 비교한다.
                if(block[index].weight >= block[idx2].weight && block[index].width >= block[idx2].width) {
                    if(dp[idx2]+block[index].height > dp[index]) {
                        //3-3. 만약 더 크면 dp와 prev 배열을 초기화한다. (prev배열은 이후 블럭 출력을 위해 자신 이전의 블럭을 저장한다)
                        dp[index] = dp[idx2] + block[index].height;
                        prev[index] = idx2;
                    }
                }
            }
        }
        int maxHeight = 0;
        for(int index = 1; index <= blockSize; index++) {
            maxHeight = Math.max(maxHeight, dp[index]);
        }

        for(int index = 1; index <= blockSize; index++) {
            if(dp[index] == maxHeight) {
                //4. dp를 돌면서 최대 높이라면 stack에 자신과 자신 이전 블럭들을 저장하고 size와 함께 stack을 pop하면서 출력한다.
                Stack<Integer> stack = new Stack<>();
                while(index != 0) {
                    stack.add(block[index].num);
                    index = prev[index];
                }
                System.out.println(stack.size());
                while(!stack.isEmpty()) {
                    System.out.println(stack.pop());
                }
                break;
            }
        }
    }
}