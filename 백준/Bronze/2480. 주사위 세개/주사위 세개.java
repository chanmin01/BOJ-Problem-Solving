import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // 세 개의 주사위 값을 입력받음
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        int prize = 0;

        // 세 개가 모두 같은 경우
        if (a == b && b == c) {
            prize = 10000 + a * 1000;
        }
        // 두 개만 같은 경우
        else if (a == b || a == c) {
            prize = 1000 + a * 100;
        }
        else if (b == c) {
            prize = 1000 + b * 100;
        }
        // 모두 다른 경우
        else {
            prize = Math.max(a, Math.max(b, c)) * 100;
        }
        
        // 결과 출력
        System.out.println(prize);
        
        scanner.close();
    }
}
