
import java.io.IOException;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String lline = sc.nextLine();
            System.out.println(lline);
        }

        sc.close();



    }
}