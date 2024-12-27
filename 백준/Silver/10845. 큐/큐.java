import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] stack = new int[10004];
        int head = 0;
        int tail = 0;
        int n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            String[] s = br.readLine().split(" ");

            if (s[0].equals("push")) {
                stack[tail++] = Integer.parseInt(s[1]);
            } else if (s[0].equals("pop")) {
                if (tail - head != 0) {
                    System.out.println(stack[head++]);
                } else {
                    System.out.println(-1);
                }
            } else if (s[0].equals("size")) {
                System.out.println(tail - head);
            } else if (s[0].equals("empty")) {
                if (tail - head == 0) {
                    System.out.println(1);
                } else {
                    System.out.println(0);
                }
            } else if (s[0].equals("front")) {
                if (tail - head != 0) {
                    System.out.println(stack[head]);
                } else {
                    System.out.println(-1);
                }
            } else if (s[0].equals("back")) {
                if (tail - head != 0) {
                    System.out.println(stack[tail - 1]);
                } else{
                    System.out.println(-1);
                    
                }
            }

        }
    }
}