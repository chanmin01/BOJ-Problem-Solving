import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, 100000001});

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            int height = Integer.parseInt(st.nextToken());

            while (!stack.isEmpty() && stack.peek()[1] < height) {
                stack.pop();
            }

            sb.append(stack.peek()[0] + " ");
            stack.add(new int[]{i, height});
        }

        System.out.println(sb);
    }
}