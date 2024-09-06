import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 바구니의 개수 n과 뒤집기 연산 수 m 입력 받기
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // 바구니 배열 초기화 (1부터 n까지)
        int[] baskets = new int[n];
        for (int i = 0; i < n; i++) {
            baskets[i] = i + 1;
        }

        // m번의 연산 수행
        for (int i = 0; i < m; i++) {
            int start = scanner.nextInt() - 1; // 인덱스는 0부터 시작하므로 -1
            int end = scanner.nextInt() - 1;

            // start부터 end까지 뒤집기
            while (start < end) {
                int temp = baskets[start];
                baskets[start] = baskets[end];
                baskets[end] = temp;
                start++;
                end--;
            }
        }

        // 결과 출력
        for (int i = 0; i < n; i++) {
            System.out.print(baskets[i] + " ");
        }

        scanner.close();
    }
}
