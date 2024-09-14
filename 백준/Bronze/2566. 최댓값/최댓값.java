import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] matrix = new int[9][9];
        int maxVal = Integer.MIN_VALUE;
        int maxRow = 0;
        int maxCol = 0;

        // 9x9 배열 입력 받기
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = scanner.nextInt();
                // 최대값 및 위치 갱신
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }

        // 결과 출력 (최대값과 위치)
        System.out.println(maxVal);
        System.out.println((maxRow + 1) + " " + (maxCol + 1)); // 인덱스는 1부터 시작하므로 +1
    }
}
