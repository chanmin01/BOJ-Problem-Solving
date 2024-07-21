import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer>[] stacks = new Stack[4];

        for (int i = 0; i < stacks.length; i++) {
            stacks[i] = new Stack<>();
            stacks[i].push(-1);
        }

        int n = Integer.parseInt(br.readLine());

        int[] numbers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();



        for (int num : numbers) {
            boolean isPossible = false;
            for (int j = 0; j < 4; j++) {
                if (stacks[j].peek() < num) {
                    stacks[j].push(num);
                    isPossible = true;
                    break;
                }
            }

            if (!isPossible) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");

    }
}
