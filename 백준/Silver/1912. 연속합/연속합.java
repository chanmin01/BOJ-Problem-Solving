import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        int[] dp = new int[100003];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int a = Integer.parseInt(st.nextToken());
            arr[i] = a;
        }


        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(0, dp[i - 1]) + arr[i];
        }

        int maxElement = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++) {
            maxElement = Math.max(maxElement, dp[i]);
        }

        System.out.println(maxElement);

    }
}