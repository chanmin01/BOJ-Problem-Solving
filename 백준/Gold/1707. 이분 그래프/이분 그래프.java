import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
            int[] visited = new int[n + 1];
            Arrays.fill(visited, -1);

            for (int k = 0; k <= n; k++) {
                graph.add(new ArrayList<>());
            }
            for (int j = 0; j < e; j++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                graph.get(u).add(v);
                graph.get(v).add(u);
            }

            Queue<Integer> queue = new LinkedList<>();
            boolean check = true;
            for (int l = 1; l <= n; l++) {
                if (visited[l] != -1) continue;
                queue.add(l);
                visited[l] = 0;
                while (!queue.isEmpty()) {
                    int cur = queue.poll();
                    for (int nxt : graph.get(cur)) {
                        if (visited[nxt] != -1) {
                            if (visited[nxt] == visited[cur]) {
                                check = false;
                                break;
                            } else continue;
                        }
                        visited[nxt] = (visited[cur] + 1) % 2;
                        queue.add(nxt);
                    }
                    if (!check) break;
                }
            }
            if (check) System.out.println("YES");
            else System.out.println("NO");

        }

    }
}