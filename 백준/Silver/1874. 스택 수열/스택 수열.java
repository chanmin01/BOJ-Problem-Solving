import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        StringBuilder ans = new StringBuilder();
        int cnt = 1;

        while (n-- > 0) {
            int num = Integer.parseInt(br.readLine());
            while (cnt <= num) {
                stack.push(cnt++);
                ans.append("+\n");
            }

            if (stack.peek() != num) {
                System.out.println("NO\n");
                return;
            }
            stack.pop();
            ans.append("-\n");

        }
        System.out.println(ans);
    }
}