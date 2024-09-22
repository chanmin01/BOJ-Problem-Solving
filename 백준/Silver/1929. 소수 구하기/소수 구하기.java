import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        ArrayList<Boolean> arr = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            arr.add(true);
        }

        arr.set(1, false);
        for (int i = 2; i * i <= n; i++) {
            if (!arr.get(i)) {
                continue;
            }
            for (int j = i * i; j <= n; j += i) {
                arr.set(j, false);
            }

        }

        for (int i = m; i <= n; i++) {
            if (arr.get(i)) {
                System.out.println(i);
            }
        }




    }
}