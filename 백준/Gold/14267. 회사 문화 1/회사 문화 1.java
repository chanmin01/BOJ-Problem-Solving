import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] visited;
    static int[] praise;
    static int n, m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        visited = new int[n + 1];
        praise = new int[n + 1];

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            int p = Integer.parseInt(st.nextToken());
            if (p == -1) continue;
            graph.get(i).add(p);
            graph.get(p).add(i);

        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int node = Integer.parseInt(st.nextToken());
            int good = Integer.parseInt(st.nextToken());
            praise[node] += good;
        }

        dfs(1);

        for (int i = 1; i <= n; i++) {
            System.out.print(praise[i] + " ");
        }
    }

    private static void dfs(int cur) {
        visited[cur] = 1;
        for (int nxt : graph.get(cur)) {
            if (visited[nxt] != 0) continue;
            praise[nxt] += praise[cur];
            dfs(nxt);
        }
    }
}