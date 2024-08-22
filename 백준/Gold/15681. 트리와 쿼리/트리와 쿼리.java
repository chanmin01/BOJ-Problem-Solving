import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int N, R, Q;
    static boolean[] visited;
    static int[] subTreeSize;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        subTreeSize = new int[100005];
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        countSubtreeNode(R);
        for (int i = 0; i < Q; i++) {
            int q = Integer.parseInt(br.readLine());
            System.out.println(subTreeSize[q]);
        }


    }

    private static int countSubtreeNode(int cur) {
        visited[cur] = true;
        for (int nxt : graph.get(cur)) {
            if (visited[nxt]) continue;
            subTreeSize[cur] += countSubtreeNode(nxt);
        }

        subTreeSize[cur]++;
        return subTreeSize[cur];
    }
}