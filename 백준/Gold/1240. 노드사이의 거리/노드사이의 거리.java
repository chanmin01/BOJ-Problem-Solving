import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
    static boolean[] visited;
    static int n, m;

    static class Pair {
        int node;
        int weight;

        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }



        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph.get(u).add(new Pair(v, w));
            graph.get(v).add(new Pair(u, w));
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            visited = new boolean[n + 1];

            Queue<Pair> queue = new LinkedList<>();

            queue.add(new Pair(start, 0));
            while (!queue.isEmpty()) {
                Pair cur = queue.poll();

                if (cur.node == end) {
                    System.out.println(cur.weight);
                }

                for (Pair nxt : graph.get(cur.node)) {
                    if (visited[nxt.node]) continue;
                    visited[nxt.node] = true;
                    queue.add(new Pair(nxt.node, cur.weight + nxt.weight));
                }

            }
        }




    }
}