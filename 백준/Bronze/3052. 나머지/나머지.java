import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashSet<Integer> remainders = new HashSet<>();

        // 10개의 정수를 입력받아 42로 나눈 나머지를 HashSet에 추가
        for (int i = 0; i < 10; i++) {
            int number = scanner.nextInt();
            int remainder = number % 42;
            remainders.add(remainder);
        }

        // 서로 다른 나머지의 개수 출력
        System.out.println(remainders.size());
    }
}
