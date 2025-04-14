import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 해당 재료를 추가할수도, 추가하지 않을 수도 있음 => 부분집합
 * 2. ingredientAdded 배열을 통해 특정 재료의 추가 여부를 표시한다.
 * 3. Pair class를 선언하여 같이 넣을 수 없는 재료의 쌍들을 저장한다.
 * 4. 해당 index마다 limitArray를 순회하여 다음 재료를 추가할 수 있는지 여부를 판단한다.
 *  4-1. pair에 다음 index와 ingredientAdded에 true로 체크된 재료가 동시에 있다면 cannotAdd = true
 * 5. 추가할 수 있다면 추가 체크 후 다음 재귀, default로 추가하지 않고 다음 재귀 두 가지를 진행
 * 6. lastIngredient(마지막으로 추가할지 추가하지 않을지 확인하는 매개변수)가 ingredientCount와 같아지면 재귀함수를 종료한다
 */
public class SWEA3421 {
    //같이 넣을 수 없는 두 ingredient
    static class Pair{
        public int ingred1, ingred2;
        public Pair(int ingred1, int ingred2) {
            this.ingred1 = ingred1;
            this.ingred2 = ingred2;
        }
    }
    //버거의 종류 수 정답 변수
    static int burgerCount = 0;
    //재료의 총 개수 -> 재귀함수 깊이의 최대값이 될 것임
    static int ingredientCount;
    //input으로 주어지는 limit pair들을 추가할
    static Pair[] limitArray;
    //2. ingredientAdded 배열을 통해 특정 재료의 추가 여부를 표시한다.
    static boolean[] ingredientAdded = new boolean[21];
    static void combination(int lastIngredient) {
        //5. lastIngredient(마지막으로 추가할지 추가하지 않을지 확인하는 매개변수)가 ingredientCount와 같아지면 재귀함수를 종료한다
        if(lastIngredient == ingredientCount) {
            burgerCount++;
            return;
        }

        //다음 index를 추가할 수 있는지 저장 변수
        boolean cannotAdd = false;
        for(Pair ingredient: limitArray) {
            //4-1. pair에 다음 index와 ingredientAdded에 true로 체크된 재료가 동시에 있다면 cannotAdd = true
            if(ingredient.ingred1 == lastIngredient + 1 && ingredientAdded[ingredient.ingred2]) {
                cannotAdd = true;
                break;
            } else if(ingredient.ingred2 == lastIngredient + 1 && ingredientAdded[ingredient.ingred1]) {
                cannotAdd = true;
                break;
            }
        }
        if(!cannotAdd) {
            //추가할 수 있다며 ingredientAdded = true 표시 후 다음 재귀
            ingredientAdded[lastIngredient + 1] = true;
            combination(lastIngredient + 1);
            //추가할 수 있다며 ingredientAdded = false 초기화
            ingredientAdded[lastIngredient + 1] = false;
        }
        //해당 재료를 추가하지 않는 재귀 또한 호출
        combination(lastIngredient + 1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        for(int test = 1; test <= testCase; test++) {
            st = new StringTokenizer(br.readLine());
            ingredientCount = Integer.parseInt(st.nextToken());
            int limitCount = Integer.parseInt(st.nextToken());
            limitArray = new Pair[limitCount];
            for(int limit = 0; limit < limitCount; limit++) {
                st = new StringTokenizer(br.readLine());
                int ingred1 = Integer.parseInt(st.nextToken());
                int ingred2 = Integer.parseInt(st.nextToken());

                limitArray[limit] = new Pair(ingred1, ingred2);
            }
            combination(0);
            System.out.printf("#%d %d\n", test, burgerCount);
            burgerCount = 0;
        }
    }
}