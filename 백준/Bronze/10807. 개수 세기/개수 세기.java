import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, Integer> numsMap = new HashMap<>();

        int n = Integer.parseInt(br.readLine());

        int[] numbers = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();

        for (int number : numbers) {
            if (numsMap.containsKey(number)) {
                numsMap.put(number, numsMap.get(number) + 1);
            } else {
                numsMap.put(number, 1);
            }
        }

        int question = Integer.parseInt(br.readLine());

        System.out.println(numsMap.getOrDefault(question, 0));

    }
}