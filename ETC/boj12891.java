import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1. 연속되는 특정 길이의 부분문자열에 대해 a, c, g, t의 개수를 볼 것임
 * 2. N과 M이 모두 최대 10^6 이므로 O(n^2) 풀이는 시간초과를 받음
 * 3. 슬라이딩 윈도우를 통해 현재의 a, c, g, t의 개수를 저장
 * 4. 첫 0번~m-1번 index의 a, c, g, t만 처음에 구해주고
 * 5. 그 이후엔 window가 한 칸 이동할 시 전의 첫번째 index 문자열을 하나 빼고, 현재 window의 마지막 index 문자열을 더해준다.
 * 6. window마다 a, c, g, t의 현재값이 limit보다 크면 경우의 수를 추가해준다.
 */
public class BOJ12891 {
    static String dna;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int stringLength = Integer.parseInt(st.nextToken());
        int pieceLength = Integer.parseInt(st.nextToken());
        dna = br.readLine();
        st = new StringTokenizer(br.readLine());
        int aLimit = Integer.parseInt(st.nextToken());
        int cLimit = Integer.parseInt(st.nextToken());
        int gLimit = Integer.parseInt(st.nextToken());
        int tLimit = Integer.parseInt(st.nextToken());

        //3. 슬라이딩 윈도우를 통해 현재의 a, c, g, t의 개수를 저장
        int aCount = 0, cCount = 0, gCount = 0, tCount = 0;
        int answer = 0;
        for(int startIndex = 0; startIndex <= stringLength - pieceLength; startIndex++) {
            //4. 첫 0번~m-1번 index의 a, c, g, t만 처음에 구해주고
            if(startIndex == 0) {
                for(int len = 0; len < pieceLength; len++) {
                    if(dna.charAt(len) == 'A') aCount++;
                    else if(dna.charAt(len) == 'C') cCount++;
                    else if(dna.charAt(len) == 'G') gCount++;
                    else tCount++;
                }
            } else { //5. 그 이후엔 window가 한 칸 이동할 시 전의 첫번째 index 문자열을 하나 빼고, 현재 window의 마지막 index 문자열을 더해준다.
                if(dna.charAt(startIndex-1) == 'A') aCount--;
                else if(dna.charAt(startIndex-1) == 'C') cCount--;
                else if(dna.charAt(startIndex-1) == 'G') gCount--;
                else tCount--;

                if(dna.charAt(startIndex + pieceLength - 1) == 'A') aCount++;
                else if(dna.charAt(startIndex + pieceLength - 1) == 'C') cCount++;
                else if(dna.charAt(startIndex + pieceLength - 1) == 'G') gCount++;
                else tCount++;
            }
            //6. window마다 a, c, g, t의 현재값이 limit보다 크면 경우의 수를 추가해준다.
            if(aCount >= aLimit && cCount >= cLimit && gCount >= gLimit && tCount >= tLimit) answer++;
        }
        System.out.println(answer);
    }
}