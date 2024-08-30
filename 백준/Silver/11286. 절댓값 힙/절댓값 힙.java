import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(
                (x, y) -> {
                    int absCompare = Math.abs(x) - Math.abs(y);
                    return absCompare != 0 ? absCompare : x - y;
                });

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) {
                if (pq.isEmpty()) {
                    System.out.println(0);
                    continue;
                }
                System.out.println(pq.poll());
                continue;
            }

            pq.add(num);
        }
    }
}