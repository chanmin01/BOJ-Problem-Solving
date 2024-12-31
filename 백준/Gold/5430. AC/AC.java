import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String commands = br.readLine();

            int n = Integer.parseInt(br.readLine());
            String input = br.readLine();
            Deque<Integer> deque = new ArrayDeque<>();

            input = input.substring(1, input.length() - 1);
            if (!input.isEmpty()) {
                String[] numbers = input.split(",");
                for (String num : numbers) {
                    deque.add(Integer.parseInt(num));
                }
            }

            boolean isReversed = false;
            boolean isError = false;

            for (char command : commands.toCharArray()) {
                if (command == 'R') {
                    isReversed = !isReversed;
                } else if (command == 'D') {
                    if (deque.isEmpty()) {
                        isError = true;
                        break;
                    }
                    if (isReversed) {
                        deque.pollLast();
                    } else {
                        deque.pollFirst();
                    }
                }
            }

            if (isError) {
                System.out.println("error");
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append("[");
                while (!deque.isEmpty()) {
                    sb.append(isReversed ? deque.pollLast() : deque.pollFirst());
                    if (!deque.isEmpty()) {
                        sb.append(",");
                    }
                }
                sb.append("]");
                System.out.println(sb);
            }
        }

    }
}