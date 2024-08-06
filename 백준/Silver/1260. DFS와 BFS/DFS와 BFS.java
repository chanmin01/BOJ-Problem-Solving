import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[] visitedDfs;
    static boolean[] visitedBfs;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());

        visitedDfs = new boolean[n + 1];
        visitedBfs = new boolean[n + 1];

        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(graph.get(i));
        }

        dfs(start);
        System.out.println();
        bfs(start);
    }

    static void dfs(int start) {
        int cur = start;
        visitedDfs[start] = true;
        System.out.print(cur + " ");
        for (int nxt : graph.get(cur)) {
            if (visitedDfs[nxt]) continue;
            dfs(nxt);
        }
    }


    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visitedBfs[start] = true;
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            System.out.print(cur + " ");
            for (int nxt : graph.get(cur)) {
                if (visitedBfs[nxt]) continue;
                queue.add(nxt);
                visitedBfs[nxt] = true;
            }
        }
    }
}