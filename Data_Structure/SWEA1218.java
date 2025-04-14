import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * 특정 열린 괄호가 있다면 그 열린 괄호에 맞는 닫힌 괄호가 들어오기 전까지 다른 괄호를 닫을 수 없음
 * 1. 괄호 character를 저장할 Stack을 생성한다.
 * 2. 입력받은 string을 순회한다.
 * 3. 순회하면서 열린 괄호는 stack에 push한다.
 * 4. 닫힌 괄호가 들어왔다면 맨 위에 그에 맞는 열린 괄호가 있는지 확인한다.
 * 	4-1. stack pop할시 stack이 비어있다면 runtimeerror을 내므로 먼저 isEmpty를 꼭 확인해준다.
 * 5. 맨 위에 특정 열린 괄호가 없다면 유효하지 않다 -> isRight = false 후 바로 for문 break
 * 6. 또한 문자열 모두 순회 후 stack이 비어있지 않다면 유효하지 않음 isRight = false;
 * @author SSAFY
 *
 */
public class SWEA1218 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int test = 1; test <= 10; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int length = Integer.parseInt(st.nextToken());
			String string = br.readLine();
			Stack<Character> stack = new Stack<>();
			boolean isRight = true;
			for(int index = 0; index < length; index++) {
				//5. 맨 위에 특정 열린 괄호가 없다면 유효하지 않다 -> isRight = false 후 바로 for문 break
				if(!isRight) break;
				
				switch(string.charAt(index)) {
				//4. 닫힌 괄호가 들어왔다면 맨 위에 그에 맞는 열린 괄호가 있는지 확인한다.
				//4-1. stack pop할시 stack이 비어있다면 runtimeerror을 내므로 먼저 isEmpty를 꼭 확인해준다.
				case '}':
					if(stack.isEmpty() || stack.pop() != '{') {
						isRight = false;
					}
					break;
				case '>':
					if(stack.isEmpty() || stack.pop() != '<') {
						isRight = false;
					}
					break;
				case ']':
					if(stack.isEmpty() || stack.pop() != '[') {
						isRight = false;
					}
					break;
				case ')':
					if(stack.isEmpty() || stack.pop() != '(') {
						isRight = false;
					}
					break;
				default:
					//3. 순회하면서 열린 괄호는 stack에 push한다.
					stack.push(string.charAt(index));
					break;
				}
			}
			//6. 또한 문자열 모두 순회 후 stack이 비어있지 않다면 유효하지 않음 isRight = false;
			if(!stack.isEmpty()) isRight = false;
			System.out.printf("#%d %d\n", test, isRight ? 1 : 0);
		}
	}
}