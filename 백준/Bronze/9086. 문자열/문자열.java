import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 입력 개수 받기
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            String input = br.readLine();
            
            // 문자열의 첫 번째와 마지막 문자 가져오기
            char first = input.charAt(0);
            char last = input.charAt(input.length() - 1);
            
            // 결과 출력
            System.out.println(first + "" + last);
        }
    }
}
