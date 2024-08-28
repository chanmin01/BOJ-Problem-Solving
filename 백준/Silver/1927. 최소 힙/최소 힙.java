import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] heap = new int[100005];
    static int size = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int q = Integer.parseInt(br.readLine());
            if (q == 0) {
                if (size == 0) {
                    System.out.println(0);
                    continue;
                }
                System.out.println(top());
                pop();
                continue;
            }
            push(q);
        }

    }

    public static void push(int x) {
        heap[++size] = x;
        int idx = size;
        while (idx != 1) {
            int parent = idx / 2;
            if (heap[parent] <= heap[idx]) break;
            int tmp = heap[parent];
            heap[parent] = heap[idx];
            heap[idx] = tmp;
            idx = parent;
        }
    }

    public static int top() {
        return heap[1];
    }

    public static void pop() {
        heap[1] = heap[size--];
        int idx = 1;
        //왼쪽 자식의 인덱스(2 * idx)가 size 보다 크면 idx는 리프
        while(2 * idx <= size) {
            int lc = 2 * idx, rc = 2 * idx + 1; //왼쪽 자식, 오른쪽 자식
            int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
            if (rc <= size && heap[rc] < heap[lc]) {
                min_child = rc;
            }
            if (heap[idx] <= heap[min_child]) break;
            int tmp = heap[idx];
            heap[idx] = heap[min_child];
            heap[min_child] = tmp;
            idx = min_child;
        }
    }
}