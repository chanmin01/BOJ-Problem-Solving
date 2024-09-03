import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();  // 바구니의 수
        int m = sc.nextInt();  // 명령의 수

        int[] baskets = new int[n];  // 바구니 배열 생성

        for (int i = 0; i < m; i++) {
            int start = sc.nextInt();  // 시작 인덱스 (1-based)
            int end = sc.nextInt();    // 끝 인덱스 (1-based)
            int value = sc.nextInt();  // 넣을 값

            // 배열의 해당 범위에 값 설정
            for (int j = start - 1; j < end; j++) {
                baskets[j] = value;
            }
        }

        // 배열의 결과 출력
        for (int i = 0; i < n; i++) {
            System.out.print(baskets[i] + " ");
        }
    }
}
