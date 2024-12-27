import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder(); // 결과를 저장할 StringBuilder
        int[] stack = new int[2000004];
        int head = 0;
        int tail = 0;
        int n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            String[] s = br.readLine().split(" ");

            if (s[0].equals("push")) {
                stack[tail++] = Integer.parseInt(s[1]);
            } else if (s[0].equals("pop")) {
                if (tail - head != 0) {
                    sb.append(stack[head++]).append("\n");
                } else {
                    sb.append("-1\n");
                }
            } else if (s[0].equals("size")) {
                sb.append(tail - head).append("\n");
            } else if (s[0].equals("empty")) {
                if (tail - head == 0) {
                    sb.append("1\n");
                } else {
                    sb.append("0\n");
                }
            } else if (s[0].equals("front")) {
                if (tail - head != 0) {
                    sb.append(stack[head]).append("\n");
                } else {
                    sb.append("-1\n");
                }
            } else if (s[0].equals("back")) {
                if (tail - head != 0) {
                    sb.append(stack[tail - 1]).append("\n");
                } else {
                    sb.append("-1\n");
                }
            }
        }

      
        System.out.print(sb.toString());
    }
}
