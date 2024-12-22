import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();

        while (k-- > 0) {
            int num = Integer.parseInt(br.readLine());
            if (num != 0) {
                stack.push(num);
            } else {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            }
        }

        int sum = stack.stream().mapToInt(Integer::intValue).sum();
        System.out.println(sum);

    }
}