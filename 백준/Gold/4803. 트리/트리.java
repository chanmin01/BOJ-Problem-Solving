import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;
    static int[] parent;
    static int isTree;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = 1;
        while (true) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) {
                break;
            }


            visited = new boolean[n + 1];
            parent = new int[n + 1];
            graph = new ArrayList<>();

            for (int i = 0; i <= n + 1; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                graph.get(u).add(v);
                graph.get(v).add(u);
            }


            int treeCount = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    isTree = 1;
                    visited[i] = true;
                    checkTree(i);
                    treeCount += isTree;
                }
            }

            if (treeCount == 0) {
                System.out.println("Case " + c + ": No trees.");
            } else if (treeCount == 1) {
                System.out.println("Case " + c + ": There is one tree.");
            } else {
                System.out.println("Case " + c + ": A forest of " + treeCount + " trees.");

            }
            c++;
        }
    }

    private static void checkTree(int root) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(root);
        visited[root] = true;

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int nxt : graph.get(cur)) {
                if (nxt == parent[cur]) continue;
                if (visited[nxt]) {
                    isTree = 0;
                    continue;
                }
                parent[nxt] = cur;
                visited[nxt] = true;
                queue.add(nxt);
            }
        }
    }
}