import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] numOfBinaryOne = new int[20];

        int num = 0;
        Long result = 0L;

        for (int i = 0; i < n; i++) {
            num = Integer.parseInt(br.readLine());
            int cnt = 0;
            while (num > 0) {
                int k = num % 2;
                num = num / 2;
                if (k == 1) {
                    numOfBinaryOne[cnt]++;
                }
                cnt++;
            }
        }

        for (int i = 0; i < 20; i++) {
            result += (1L << i) * numOfBinaryOne[i] * (n - numOfBinaryOne[i]);
        }

        System.out.println(result);
    }


}