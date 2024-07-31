import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = 0;
        Queue<String> math = new LinkedList<>();
        Queue<Integer> number = new LinkedList<>();
        while(true) {
            String s = br.readLine();
            if (s.equals("=")) {
                break;
            }
            else if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                math.add(s);
            } else {
                number.add(Integer.parseInt(s));
            }
        }

        if (number.isEmpty()) {
            System.out.println(0);
            return;
        } else {
            result = number.poll();
        }

        while(!number.isEmpty()) {
            String operation = math.poll();
            int nextNumber = number.poll();
            switch (operation) {
                case "+":
                    result += nextNumber;
                    break;
                case "-":
                    result -= nextNumber;
                    break;
                case "*":
                    result *= nextNumber;
                    break;
                case "/":
                    result /= nextNumber;
                    break;
            }
        }

        System.out.println(result);
    }
}
