import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] cost = new int[n + 1][4];
        int[][] dp = new int[n + 1][4];

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 3; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        //dp 정의 i 번째 집까지 cost 최소값 / i 번째 집의 색깔

        dp[1][1] = cost[1][1];
        dp[1][2] = cost[1][2];
        dp[1][3] = cost[1][3];


        for (int i = 2; i <= n; i++) {
            dp[i][1] = Math.min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
            dp[i][2] = Math.min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
            dp[i][3] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];

        }

        System.out.println(Math.min(Math.min(dp[n][1], dp[n][2]), dp[n][3]));


    }
}