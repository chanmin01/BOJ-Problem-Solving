import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> party = new ArrayList<>();
    static int[] visited;

    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int knows = Integer.parseInt(st.nextToken());

        visited = new int[n + 1];

        for (int i = 0; i < knows; i++) {
            int a = Integer.parseInt(st.nextToken());
            visited[a] = 1; //진실을 아는 사람의 visited 배열을 1로 만들어줌
        }

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }



        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int people = Integer.parseInt(st.nextToken());
            ArrayList<Integer> currentParty = new ArrayList<>(); //마지막에 party 배열에 추가
            int prev = Integer.parseInt(st.nextToken());
            currentParty.add(prev);
            for (int j = 1; j < people; j++) {
                int cur = Integer.parseInt(st.nextToken());
                graph.get(prev).add(cur);
                graph.get(cur).add(prev);
                currentParty.add(cur);
                prev = cur;
            }
            party.add(currentParty);

        }

        bfs();
        int count = 0;
        for (int i = 0; i < m; i++) {
            boolean check = true;
            for (int a : party.get(i)) {
                if (visited[a] == 1) {
                    check = false;
                    break;
                }

            }
            if (check) count++;
        }

        System.out.println(count);

    }

    private static void bfs() {
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 1) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int nxt : graph.get(cur)) {
                if (visited[nxt] == 1) continue;
                visited[nxt] = 1;
                queue.add(nxt);
            }
        }
    }
}